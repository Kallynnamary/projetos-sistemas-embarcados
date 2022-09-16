//Parte I

//Alarme controlando 4 pontos: infravermelho e rele reed
//Quando houver violação envia uma mensagem via GSM
//para um número de celular, informando o ponto violado.

// Sistema de segurança rsidencial - sensor de presença e aviso ao proprietário

#include "sim900.h"
#include <SoftwareSerial.h>

//Carrega a biblioteca SMS
#include "sms.h"
 
SMSGSM sms;


boolean started=false;


////
const int yellow= 4;  //led para teste
const int green    = 11; //led para teste
const int red    = 5; //led para teste
const int pinSwitch = 10; //reed switch1
const int pinSwitch1 = 9; //reed switch1
const int IR = 12;   //sensor IR1
const int LED = 7;
const int IR1 = 13; //sensor IR2
const int LED1 = 6;

int estado=0;
int estado1=0;


void setup() {
//
pinMode(yellow, OUTPUT);
pinMode(red, OUTPUT);
pinMode(green, OUTPUT);
pinMode(pinSwitch, INPUT);
pinMode(pinSwitch1, INPUT);
pinMode(IR, INPUT);
pinMode(LED, OUTPUT);
pinMode(IR1, INPUT);
pinMode(LED1, OUTPUT);

 
  Serial.begin(9600);
  Serial.println("Testando GSM shield...");
     //Inicia a configuracao do Shield
     if (gsm.begin(2400)) 
     {
       Serial.println("nstatus=READY");
       started=true;
     } 
     else Serial.println("nstatus=IDLE");
 
     if(started) 
     {
       //Envia um SMS para o numero selecionado
       //Formato sms.SendSMS(<numero>,<mensagem>)
       if (sms.SendSMS("088992939108","OK!!!"))
       Serial.println("nSMS sent OK");
     }

}
void loop() {
    
     digitalWrite(LED1, HIGH);
     estado1 = digitalRead(IR1);
     digitalWrite(LED, HIGH);
     estado = digitalRead(IR);
     delay( ( 10 * 60 * 1000 ) );
 
//ZONA 01
if ((estado1==LOW)&&(digitalRead(pinSwitch)== LOW)&&(digitalRead(pinSwitch1)==HIGH)){

zona1();

}else{

digitalWrite(red, LOW);}


//ZONA 02
if ((estado1==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==LOW)){

zona2();

}else{

digitalWrite(red, LOW);}


//ZONA 03
if ((estado1==HIGH)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){

zona3();

}else{

digitalWrite(red, LOW);}

//ZONA 04
if ((estado==HIGH)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){

                zona4();
}else{
          digitalWrite(red, LOW);}


//ZONA 05
if ((estado1==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){

digitalWrite(green, HIGH);}

else{
  digitalWrite(green, LOW);
}




if ((estado==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){

digitalWrite(green, HIGH);}

else{
  digitalWrite(green, LOW);
}

if ((estado==LOW)&&(digitalRead(pinSwitch)== LOW)&&(digitalRead(pinSwitch1)==HIGH)){

zona1();

}else{

digitalWrite(red, LOW);}


//ZONA 02
if ((estado==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==LOW)){

zona2();

}else{

digitalWrite(red, LOW);}


}






void zona1(){
  
  digitalWrite(red, HIGH);
 
  
  if (sms.SendSMS("088992939108","Zona 01 Extraviada!!!"))
  Serial.println("nSMS sent OK");
    
}
//ZONA 02
void zona2(){
  
  digitalWrite(red, HIGH);
  if (sms.SendSMS("088992939108","Zona 02 Extraviada!!!"))
  Serial.println("nSMS sent OK");
}
//ZONA 03
void zona3(){
  
  digitalWrite(red, HIGH);
  if (sms.SendSMS("088992939108","Zona 03 Extraviada!!!"))
  Serial.println("nSMS sent OK");
}
//ZONA 04
void zona4(){
  
  digitalWrite(red, HIGH);
  if (sms.SendSMS("088992939108","Zona 4 Extraviada!!!"))
  Serial.println("nSMS sent OK");
}


//Alarme controlando 4 pontos: infravermeho e rele reed
//Quando houver violacao envia uma mensagem via GSM
//para um numero de celular, informando o ponto violado.


//BIBLIOTECA DO MODULO GSM
#include "SIM900.h"
#include <SoftwareSerial.h>
//Carrega a biblioteca SMS
#include "sms.h"
 
SMSGSM sms;


boolean started=false;


////DECLARAR AS VARIAVEIS 
const int green    = 11; //LED VERDE INDICA SITUAÇÃO NORMAL
const int red    = 5; //LED VERMELHO INDICA ZONA VIOLADA
const int pinSwitch = 10; //reed switch
const int pinSwitch1 = 9; //reed switch1
const int IR = 12;   //sensor IR1
const int LED = 7; //TRANSMISSOR DO IR1
const int IR1 = 13; //sensor IR2
const int LED1 = 6; //TRANSMISSOR DO IR2


//ESTADO INICIAL DOS SENSORES
int estado=0;
int estado1=0;


void setup() {
// DECLARAR AS VARIAVEIS COMO ENTRADA OU SAIDA

    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(pinSwitch, INPUT);
    pinMode(pinSwitch1, INPUT);
    pinMode(IR, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(IR1, INPUT);
    pinMode(LED1, OUTPUT);

 
  Serial.begin(9600);
  Serial.println("Testando GSM shield...");
     //Inicia a configuracao do Shield
     if (gsm.begin(2400)) 
     {
       Serial.println("nstatus=READY");
       started=true;
     } 
     else Serial.println("nstatus=IDLE");
 
     if(started) 
     {
       //Envia um SMS para o numero selecionado
       //Formato sms.SendSMS(<numero>,<mensagem>)
       if (sms.SendSMS("088992939108","OK!!!"))
       Serial.println("nSMS sent OK");
     }

}
void loop() {
//LEITURA DOS SENSORES INFRAVERMELHOS
     digitalWrite(LED1, HIGH);
     estado1 = digitalRead(IR1);
     digitalWrite(LED, HIGH);
     estado = digitalRead(IR);
     delay( ( 10 * 60 * 1000 ) );
 

//ZONA 01 (IR)
if ((estado1==LOW)&&(digitalRead(pinSwitch)== LOW)&&(digitalRead(pinSwitch1)==HIGH)){
        zona1();
}else{
        digitalWrite(red, LOW);}


//ZONA 02 (IR)
if ((estado1==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==LOW)){
        zona2();
}else{
       digitalWrite(red, LOW);}


//ZONA 03 (IR)
if ((estado1==HIGH)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){
        zona3();
}else{
        digitalWrite(red, LOW);}


//ZONA 04 (IR)
if ((estado1==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){
      digitalWrite(green, HIGH);}
else{
      digitalWrite(green, LOW);
}




//ZONA 01 (IR1)
if ((estado==LOW)&&(digitalRead(pinSwitch)== LOW)&&(digitalRead(pinSwitch1)==HIGH)){
      zona1();
}else{
      digitalWrite(red, LOW);}


//ZONA 02  (IR1)
if ((estado==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==LOW)){
        zona2();
}else{
      digitalWrite(red, LOW);}


//ZONA 03  (IR1)
if ((estado==HIGH)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){
        zona4();
}else{
       digitalWrite(red, LOW);}


//ZONA 04 (IR1)
if ((estado==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){
      digitalWrite(green, HIGH);}
else{
      digitalWrite(green, LOW);
}

}



//FUNÇÕES PARA CADA ZONA
void zona1(){
  
  digitalWrite(red, HIGH);
  if (sms.SendSMS("088992939108","Zona 01 Extraviada!!!"))
  Serial.println("nSMS sent OK");
}
//ZONA 02
void zona2(){
  
  digitalWrite(red, HIGH);
  if (sms.SendSMS("088992939108","Zona 02 Extraviada!!!"))
  Serial.println("nSMS sent OK");
}
//ZONA 03
void zona3(){
  digitalWrite(red, HIGH);
  if (sms.SendSMS("088992939108","Zona 03 Extraviada!!!"))
  Serial.println("nSMS sent OK");
}
//ZONA 04
void zona4(){
  digitalWrite(red, HIGH);
  if (sms.SendSMS("088992939108","Zona 4 Extraviada!!!"))
  Serial.println("nSMS sent OK");
}


//Alarme controlando 4 pontos: infravermeho e rele reed
//Quando houver violacao envia uma mensagem via GSM
//para um numero de celular, informando o ponto violado.


//BIBLIOTECA DO MODULO GSM
#include "SIM900.h"
#include <SoftwareSerial.h>
//Carrega a biblioteca SMS
#include "sms.h"
 
SMSGSM sms;


boolean started=false;


////DECLARAR AS VARIAVEIS 
const int green    = 11; //LED VERDE INDICA SITUAÇÃO NORMAL
const int red    = 5; //LED VERMELHO INDICA ZONA VIOLADA
const int pinSwitch = 10; //reed switch
const int pinSwitch1 = 9; //reed switch1
const int IR = 12;   //sensor IR1
const int LED = 7; //TRANSMISSOR DO IR1
const int IR1 = 13; //sensor IR2
const int LED1 = 6; //TRANSMISSOR DO IR2


//ESTADO INICIAL DOS SENSORES
int estado=0;
int estado1=0;


void setup() {
// DECLARAR AS VARIAVEIS COMO ENTRADA OU SAIDA

    pinMode(red, OUTPUT);
    pinMode(green, OUTPUT);
    pinMode(pinSwitch, INPUT);
    pinMode(pinSwitch1, INPUT);
    pinMode(IR, INPUT);
    pinMode(LED, OUTPUT);
    pinMode(IR1, INPUT);
    pinMode(LED1, OUTPUT);

 
  Serial.begin(9600);
  Serial.println("Testando GSM shield...");
     //Inicia a configuracao do Shield
     if (gsm.begin(2400)) 
     {
       Serial.println("nstatus=READY");
       started=true;
     } 
     else Serial.println("nstatus=IDLE");
 
     if(started) 
     {
       //Envia um SMS para o numero selecionado
       //Formato sms.SendSMS(<numero>,<mensagem>)
       if (sms.SendSMS("088992939108","OK!!!"))
       Serial.println("nSMS sent OK");
     }

}
void loop() {
//LEITURA DOS SENSORES INFRAVERMELHOS
     digitalWrite(LED1, HIGH);
     estado1 = digitalRead(IR1);
     digitalWrite(LED, HIGH);
     estado = digitalRead(IR);
     delay( ( 10 * 60 * 1000 ) );
 

//ZONA 01 (IR)
if ((estado1==LOW)&&(digitalRead(pinSwitch)== LOW)&&(digitalRead(pinSwitch1)==HIGH)){
        zona1();
}else{
        digitalWrite(red, LOW);}


//ZONA 02 (IR)
if ((estado1==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==LOW)){
        zona2();
}else{
       digitalWrite(red, LOW);}


//ZONA 03 (IR)
if ((estado1==HIGH)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){
        zona3();
}else{
        digitalWrite(red, LOW);}


//ZONA 04 (IR)
if ((estado1==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){
      digitalWrite(green, HIGH);}
else{
      digitalWrite(green, LOW);
}




//ZONA 01 (IR1)
if ((estado==LOW)&&(digitalRead(pinSwitch)== LOW)&&(digitalRead(pinSwitch1)==HIGH)){
      zona1();
}else{
      digitalWrite(red, LOW);}


//ZONA 02  (IR1)
if ((estado==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==LOW)){
        zona2();
}else{
      digitalWrite(red, LOW);}


//ZONA 03  (IR1)
if ((estado==HIGH)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){
        zona4();
}else{
       digitalWrite(red, LOW);}


//ZONA 04 (IR1)
if ((estado==LOW)&&(digitalRead(pinSwitch)== HIGH)&&(digitalRead(pinSwitch1)==HIGH)){
      digitalWrite(green, HIGH);}
else{
      digitalWrite(green, LOW);
}

}



//FUNÇÕES PARA CADA ZONA
void zona1(){
  
  digitalWrite(red, HIGH);
  if (sms.SendSMS("088992939108","Zona 01 Extraviada!!!"))
  Serial.println("nSMS sent OK");
}
//ZONA 02
void zona2(){
  
  digitalWrite(red, HIGH);
  if (sms.SendSMS("088992939108","Zona 02 Extraviada!!!"))
  Serial.println("nSMS sent OK");
}
//ZONA 03
void zona3(){
  digitalWrite(red, HIGH);
  if (sms.SendSMS("088992939108","Zona 03 Extraviada!!!"))
  Serial.println("nSMS sent OK");
}
//ZONA 04
void zona4(){
  digitalWrite(red, HIGH);
  if (sms.SendSMS("088992939108","Zona 4 Extraviada!!!"))
  Serial.println("nSMS sent OK");
}
