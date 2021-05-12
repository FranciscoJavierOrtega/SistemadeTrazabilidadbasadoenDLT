
#include <dht.h>
#include <LiquidCrystal.h>
#include "pitches.h"

dht DHT;
LiquidCrystal lcd(8, 9, 10, 11, 12, 13);
#define DHT11_PIN 3
int melody = NOTE_G5;
int melody2 = NOTE_B5;
int duration = 1000;  
int ValorLdr = 0;    //Creamos la variable de tipo número entero para almacenar los datos recogidos del sensor analógico LDR (Light Dependant Resitor). 
int pinLDR = A0;    //Seleccionamos el pin analógico A0 como input del sensor LDR. 
int pinLedlum = 4;
int pinLedtemp = 5;
int pinLedtempverde = 7;
int pinLedhum = 6;
int pulsador = 2;
int Min_T = 5;
int Max_T = 15;
int Min_L = 20;
int Max_L = 200;
int Min_H = 80;
int Max_H = 95;  
byte baja[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B11111,
  B01110,
  B00100
};

byte elevada[8] = {
  B00100,
  B01110,
  B11111,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100
};

byte check[8] = {
  B00000,
  B00001,
  B00011,
  B10110,
  B11100,
  B01000,
  B00000,
  B00000
};

byte manipulado[8] = {
  B00100,
  B01110,
  B01110,
  B01110,
  B11111,
  B00000,
  B00100,
  B00000
};

void setup(){
    Serial.begin(9600);
    lcd.begin(16,2); //medidas de lcd
    pinMode (pinLedlum,OUTPUT);
    pinMode (pinLedtemp,OUTPUT);
    pinMode (pinLedtempverde,OUTPUT);
    pinMode (pinLedhum, OUTPUT); 
    pinMode (pulsador, INPUT_PULLUP);   
    lcd.createChar(7, baja);  
    lcd.createChar(8, elevada);
    lcd.createChar(9, check);
    lcd.createChar(6, manipulado);
}

void loop() {  


ValorLdr = analogRead(pinLDR); //Leemos el valor del pinLDR y lo guardamos en la variable creada.
int chk = DHT.read11(DHT11_PIN); //lee la humedad y temperatura
//Serial.print(analogRead(pinLDR));   
 
if ( Min_T<=DHT.temperature&&DHT.temperature<=Max_T && Min_L<=ValorLdr&&ValorLdr<=Max_L && DHT.humidity<Min_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Humedad baja"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(9);
      lcd.setCursor(9,1);
      lcd.write(7);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(9);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,LOW);
      digitalWrite(pinLedlum,LOW);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( Min_T<=DHT.temperature&&DHT.temperature<=Max_T && Min_L<=ValorLdr&&ValorLdr<=Max_L && DHT.humidity>Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Humedad alta"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
       lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(9);
      lcd.setCursor(9,1);
      lcd.write(8);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(9);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,LOW);
      digitalWrite(pinLedlum,LOW);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( Min_T<=DHT.temperature&&DHT.temperature<=Max_T && ValorLdr<Min_L && DHT.humidity<Min_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Luz y Humedad bajas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(9);
      lcd.setCursor(9,1);
      lcd.write(7);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(7);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,LOW);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( Min_T<=DHT.temperature&&DHT.temperature<=Max_T && ValorLdr>Max_L && DHT.humidity<Min_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Luz alta y Humedad baja"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(9);
      lcd.setCursor(9,1);
      lcd.write(7);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(8);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,LOW);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( Min_T<=DHT.temperature&&DHT.temperature<=Max_T && ValorLdr<Min_L && DHT.humidity>Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Luz baja y Humedad alta"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(9);
      lcd.setCursor(9,1);
      lcd.write(8);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(7);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,LOW);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( Min_T<=DHT.temperature&&DHT.temperature<=Max_T && ValorLdr>Max_L && DHT.humidity>Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Luz y Humedad altas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(9);
      lcd.setCursor(9,1);
      lcd.write(8);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(8);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,LOW);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( Min_T<=DHT.temperature&&DHT.temperature<=Max_T && ValorLdr<Min_L && Min_H<=DHT.humidity&&DHT.humidity<=Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Luz baja"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(9);
      lcd.setCursor(9,1);
      lcd.write(9);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(7);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,LOW);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,LOW);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( Min_T<=DHT.temperature&&DHT.temperature<=Max_T && ValorLdr>Max_L && Min_H<=DHT.humidity&&DHT.humidity<=Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Luz alta"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(9);
      lcd.setCursor(9,1);
      lcd.write(9);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(8);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,LOW);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,LOW);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature<Min_T && Min_L<=ValorLdr&&ValorLdr<=Max_L && Min_H<=DHT.humidity&&DHT.humidity<=Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura baja"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(7);
      lcd.setCursor(9,1);
      lcd.write(9);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(9);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,LOW);
      digitalWrite(pinLedhum,LOW);
      digitalWrite(pinLedtempverde,LOW); 
      }  
else if ( DHT.temperature>Max_T && Min_L<=ValorLdr&&ValorLdr<=Max_L && Min_H<=DHT.humidity&&DHT.humidity<=Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura alta"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(8);
      lcd.setCursor(9,1);
      lcd.write(9);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(9);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,LOW);
      digitalWrite(pinLedhum,LOW);
      digitalWrite(pinLedtempverde,LOW); 
      }  
else if ( DHT.temperature<Min_T && ValorLdr<Min_L && Min_H<=DHT.humidity&&DHT.humidity<=Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura y Luz bajas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(7);
      lcd.setCursor(9,1);
      lcd.write(9);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(7);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,LOW);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature<Min_T && ValorLdr>Max_L && Min_H<=DHT.humidity&&DHT.humidity<=Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura baja y Luz alta"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(7);
      lcd.setCursor(9,1);
      lcd.write(9);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(8);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,LOW);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature>Max_T && ValorLdr<Min_L && Min_H<=DHT.humidity&&DHT.humidity<=Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura alta y Luz baja"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(8);
      lcd.setCursor(9,1);
      lcd.write(9);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(7);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,LOW);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature>Max_T && ValorLdr>Max_L && Min_H<=DHT.humidity&&DHT.humidity<=Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura y Luz altas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(8);
      lcd.setCursor(9,1);
      lcd.write(9);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(8);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,LOW);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature<Min_T && Min_L<=ValorLdr&&ValorLdr<=Max_L && DHT.humidity<Min_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura y Humedad bajas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(7);
      lcd.setCursor(9,1);
      lcd.write(7);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(9);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,LOW);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      } 
else if ( DHT.temperature<Min_T && Min_L<=ValorLdr&&ValorLdr<=Max_L && DHT.humidity>Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura baja y Humedad alta"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(7);
      lcd.setCursor(9,1);
      lcd.write(8);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(9);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,LOW);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      } 
else if ( DHT.temperature>Max_T && Min_L<=ValorLdr&&ValorLdr<=Max_L && DHT.humidity<Min_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura alta y Humedad baja"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(8);
      lcd.setCursor(9,1);
      lcd.write(7);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(9);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,LOW);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      } 
else if ( DHT.temperature>Max_T && Min_L<=ValorLdr&&ValorLdr<=Max_L && DHT.humidity>Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura y Humedad altas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(8);
      lcd.setCursor(9,1);
      lcd.write(8);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(9);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,LOW);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature>Max_T && ValorLdr<Min_L && DHT.humidity>Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Luz baja, Temperatura y Humedad altas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(8);
      lcd.setCursor(9,1);
      lcd.write(8);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(7);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature>Max_T && ValorLdr<Min_L && DHT.humidity<Min_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura alta, Luz y Humedad bajas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(8);
      lcd.setCursor(9,1);
      lcd.write(7);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(7);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature>Max_T && ValorLdr>Max_L && DHT.humidity>Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura, Luz y Humedad altas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(8);
      lcd.setCursor(9,1);
      lcd.write(8);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(8);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature>Max_T && ValorLdr>Max_L && DHT.humidity<Min_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Humedad baja, Temperatura y Luz altas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(8);
      lcd.setCursor(9,1);
      lcd.write(7);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(8);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature<Min_T && ValorLdr>Max_L && DHT.humidity>Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura baja, Luz y Humedad altas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(7);
      lcd.setCursor(9,1);
      lcd.write(8);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(8);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }   
else if ( DHT.temperature<Min_T && ValorLdr<Min_L && DHT.humidity<Min_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Temperatura, Luz y Humedad bajas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(7);
      lcd.setCursor(9,1);
      lcd.write(7);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(7);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature<Min_T && ValorLdr<Min_L && DHT.humidity>Max_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Humedad alta, Temperatura y Luz bajas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(7);
      lcd.setCursor(9,1);
      lcd.write(8);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(7);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
else if ( DHT.temperature<Min_T && ValorLdr>Max_L && DHT.humidity<Min_H){
      Serial.print("Temp: ");
      Serial.print(DHT.temperature);
      Serial.print("C, ");
      Serial.print("Hum: ");
      Serial.print(DHT.humidity);
      Serial.println("%; Luz alta, Temperatura y Luz bajas"); 
      lcd.clear(); //elimina los simbolos del LCD
      lcd.setCursor(0,0);
      lcd.print("T:");
      lcd.setCursor(2,0);
      lcd.print(DHT.temperature); //Escribe la temp
      lcd.setCursor(7,0);
      lcd.print("C");
      lcd.setCursor(0, 1); 
      lcd.print("H:");
      lcd.setCursor(2, 1);
      lcd.print(DHT.humidity);//Escribe la hum
      lcd.setCursor(7, 1);
      lcd.print("%");
      lcd.setCursor(9,0);
      lcd.write(7);
      lcd.setCursor(9,1);
      lcd.write(7);
      lcd.setCursor(12,0);
      lcd.print("Luz");
      lcd.setCursor(13,1);
      lcd.write(8);
      tone(19,melody,duration);
      digitalWrite(pinLedtemp,HIGH);
      digitalWrite(pinLedlum,HIGH);
      digitalWrite(pinLedhum,HIGH);
      digitalWrite(pinLedtempverde,LOW); 
      }
     
else {
 Serial.print("Temp: ");
  Serial.print(DHT.temperature);
  Serial.print("C, ");
  Serial.print("Hum: ");
  Serial.print(DHT.humidity);
  Serial.println("%; Valores correctos");
  lcd.clear(); //elimina los simbolos del LCD
  lcd.setCursor(0,0);
  lcd.print("T:");
  lcd.setCursor(2,0);
  lcd.print(DHT.temperature); //Escribe la temp
  lcd.setCursor(7,0);
  lcd.print("C");
  lcd.setCursor(0, 1); 
  lcd.print("H:");
  lcd.setCursor(2, 1);
  lcd.print(DHT.humidity);//Escribe la hum
  lcd.setCursor(7, 1);
  lcd.print("%");
  lcd.setCursor(9,0);
  lcd.write(9);
  lcd.setCursor(9,1);
  lcd.write(9);
  lcd.setCursor(12,0);
  lcd.print("Luz");
  lcd.setCursor(13,1);
  lcd.write(9);
  digitalWrite(pinLedtempverde,HIGH);
  digitalWrite(pinLedlum, LOW);
  digitalWrite(pinLedtemp,LOW);
  digitalWrite(pinLedhum,LOW);
}

if (digitalRead(pulsador) == HIGH){
   }
else {
  digitalRead(pulsador) == LOW;
  Serial.println("Sistema manipulado");
  lcd.setCursor(10,0);
  lcd.write(6);
  lcd.setCursor(10,1);
  lcd.write(6);
  lcd.setCursor(12,0);
  lcd.print("Luz");
  lcd.setCursor(14,1);
  lcd.write(6);
 }
    delay(10000);
}
