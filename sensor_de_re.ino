
//Sensor de ré

// Define os parametros
const int pingPin = A4;
const int echoPin = A5;
const int buzzer = 13;


const int leds[] = {3,4,5,6,7,8,9,10};   // pinos dos leds
const int displays[] = {11,12};   // pinos de enable dos displays

const int qtd_efeitos = 10;

byte efeito[] = {B111111, B110, B1011011, B1001111, B1100110,
                  B1101101, B1111101, B111, B1111111, B1101111
                 };

int j = 1, i = 0, periodo_cont = 100, periodo_multiplx = 5, uni = 0, dez = 0, cent = 0, disp = 0, cm = 30, f = 0, a = 0, b = 0;
long duration;
unsigned long tempo_cont = 0, tempo_atual, tempo_multiplx = 0;
long int TempodeUpdate = 1000;
long int TempoGravado = 0;

void setup() {
  Serial.begin(9600);
  Serial.println(" Sensor de Ré ");
  Serial.println(" =================================== ");
  
  pinMode(pingPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  pinMode(buzzer, OUTPUT);
  
  for (i = 0; i < 8; i++)
    pinMode(leds[i], OUTPUT);
    
  for (i = 0; i < 2; i++)
    pinMode(displays[i], OUTPUT);
   
    
  digitalWrite(displays[0], 0);
  digitalWrite(displays[1], 0);
}

void loop() {


  
  tempo_atual = millis();
  if (tempo_atual - tempo_cont > periodo_cont)    // atingiu o intervalo de tempo desejado para a contagem de cada número
  {
    
    cm = ultrasonic_sensor();
    
    apito(cm);
    
    
    if(cm > 500)
    {
      cent = 5;
      dez = 0;
      uni = 0;
    }
    else
    {
      if(cm < 5)
      {
        cent = 0;
        dez = 0;
        uni = 5;
      }
      else
      {
        cent = cm/100;
        dez = (cm%100)/10;
        uni = (cm%100)%10;
      }
    }
          
    
    Serial.print(cm);
    Serial.print("cm, faixa:");
    Serial.println(f);
    

    tempo_cont = tempo_atual;    // reinicia contagem para atingir o periodo de contagem desejado
  }
  
  if (tempo_atual - tempo_multiplx > periodo_multiplx)    // atingiu o intervalo de tempo desejado que cada display deve permanecer aceso durante a multiplexação
  {
    if(cent == 0){  //de 0 a 99
      switch (disp){  //rotina individual de cada display para imprimir o valor desejado em cada um
       case 0:{
         digitalWrite(displays[1], 0);
         escreva_leds(efeito[uni]);
         digitalWrite(displays[0], 1);
         disp++;
         break;
       }
       case 1:{
         digitalWrite(displays[0], 0);
         escreva_leds(efeito[dez]);
          digitalWrite(leds[7],1);
         digitalWrite(displays[1], 1);
         disp--;
         break;
       } 
      }
    }
    else{  //de 100 a 999
      switch (disp){  //rotina individual de cada display para imprimir o valor desejado em cada um
       case 0:{
         
         digitalWrite(displays[1], 0);
         
         escreva_leds(efeito[dez]);
         digitalWrite(leds[7],0);
          
         digitalWrite(displays[0], 1);
                 
         disp++;
         break;
       }
       case 1:{
         digitalWrite(displays[0], 0);
         
         escreva_leds(efeito[cent]+128);
         digitalWrite(displays[1], 1);
         
         disp--;
         break;
       } 
      }
    }

    tempo_multiplx = tempo_atual;    // reinicia contagem para atingir o periodo de contagem desejado
  }

}


void escreva_leds(byte x)    // escreve x (8 bits) no display de 7 segmentos
{
  for (i = 0; i < 7; i++)
    digitalWrite(leds[0 + i], !bitRead(x, i));
}

int ultrasonic_sensor() // rotina de leitura do sensor
{
  long int tempoagora = millis();
    if (abs (TempoGravado - TempoGravado) <= TempodeUpdate){
      digitalWrite(pingPin, LOW);
      delayMicroseconds(2);
      digitalWrite(pingPin, HIGH);
      delayMicroseconds(10);
      digitalWrite(pingPin, LOW);
      return pulseIn(echoPin, HIGH)/58;   // conversão de microsegundos para cm
  
      TempoGravado = millis();
    }
}

void apito(int cm) // rotina de faixas de apito
{
  if (cm<20)
    f = 1;
  else 
    if (cm >=20 && cm <60 )
      f = 4;
    else
      if (cm >= 60 && cm <100)
        f = 7;
      else
        if (cm >= 100)
          f = 10;
        
   
   if (a < f)
     a++;
   else
     if (a > f)
       a = 0;
     else
     {
       a++;
       b = !b;
       digitalWrite(buzzer,b);             
     }
    
}
