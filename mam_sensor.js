/*
Este fichero publica los datos leídos por los sensores en el Tangle de IOTA
*/


const SerialPort = require('serialport');
const moment = require('moment');

const IOTA = require('iota.lib.js');
const Mam = require('./lib/mam.client.js');

const iota = new IOTA({ provider: 'https://nodes.devnet.iota.org:443' });

const MODE = 'public'; // public, private or restricted
const SECURITYLEVEL = 3; // 1, 2 or 3

const PORTNAME = '/dev/tty.usbmodem14201';

const port = new SerialPort(PORTNAME, {
    baudRate: 9600,
    autoOpen: true
});

const Readline = SerialPort.parsers.Readline;
const parser = port.pipe(new Readline({ delimiter: '\r\n' }));

// Ininicializar MAM State
let mamState = Mam.init(iota, undefined, SECURITYLEVEL);

// Establecer el modo del canal
if (MODE == 'restricted') {
    const key = iota.utils.toTrytes(SIDEKEY);
    mamState = Mam.changeMode(mamState, MODE, key);
} else {
    mamState = Mam.changeMode(mamState, MODE);
}

// Publicar en el Tangle
const publish = async function(packet) {
    // Crear MAM Payload
    const trytes = iota.utils.toTrytes(JSON.stringify(packet));
    const message = Mam.create(mamState, trytes);

    // Guardar el nuevo mamState
    mamState = message.state;
    console.log('Root: ', message.root);
    console.log('Address: ', message.address);

    // Adjuntar el payload.
    await Mam.attach(message.payload, message.address, 3,9);

    return message.root;
}

// Eventos de la libreria del Puerto Serie 
port.on('open', showPortOpen);
parser.on('data', readSerialData);
port.on('close', showPortClose);
port.on('error', showError);

// Fuciones Callback
function showPortOpen() {
    console.log('Serial port open. Data rate: ' + port.baudRate);
}

async function readSerialData(data){
    console.log("Serial port open. Read serial data.");

    // Crear objeto JSON:
    // Convertir los datos recibidos de Arduino:  temp: 26.00C, humidity: 21.00%
    // a
    // json = { dateTime: '15/07/2018 10:57:35', data: { temp: '26.00C', humidity: '21.00%' } }
    //
    let json = {};

    const dateTime = moment().utc(+2).format('DD/MM/YYYY hh:mm:ss');
    json['dateTime'] = dateTime;
	json['data'] = `{${data}}`;

    console.log('json = ',json);

    const root = await publish(json);
}

function showPortClose() {
    console.log('Serial port closed.');
}

function showError(error) {
   console.log('Serial port error: ' + error);
}
