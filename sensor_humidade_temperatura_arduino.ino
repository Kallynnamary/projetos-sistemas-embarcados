// Sensor de humidade e temperatura integrando arduino e phyton
//=====================================================

//Incluindo a biblioteca de comunicação com o sensor de humidade e temperatura.
#include "DHT.h"

//Define o macro DHTPIN de acordo com o pino digital correspondente.
#define DHTPIN 2

//Seleciona o tipo de sensor (no nosso caso, o DHT22)
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321

//Cria e inicializa os dados do sensor.
DHT dht(DHTPIN, DHTTYPE);

double currentHumidity =0.0;
double currentTemperature =0.0;

// Função que executa uma vez para configurar
// variáveis e parametros
void setup(){
  
  // Inicializa a porta serial a uma velocidade de 57600bps  
  Serial.begin(57600);
  
  //Envia um header pela porta serial.
  Serial.print("Humidity\tTemperature\n");
  
  //Inicializa o sensor.  
  dht.begin();
  }
  
  // Executa loop indefinidamente após a execução da função setup
  // podendo ser parado por certas funções e interrupções.
  void loop(){
    // Aguarda-se 250ms antes de realizar uma nova leitura do sensor.  
    delay(250);
    
    currentHumidity = dht.readHumidity();
    currentTemperature = dht.readTemperature();
    
    // Checa se alguma das leituras falhou.
    if(isnan(currentHumidity)|| isnan(currentTemperature)){
      Serial.println("ERROR: Failed to read from DHT sensor!");
      return;
      }
      
      // Envia através da porta serial os valores de umidade e temperatura. 
      Serial.print(currentHumidity);  
      Serial.print("\t");  
      Serial.print(currentTemperature);  
      Serial.print("\n");
  }
