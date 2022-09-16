// Controle de velocidade de motor


#include <TimerOne.h>

// Pino dos botões
const char Botao1 = 6, Botao2 = 5, Botao3 = 4, Botao4 = 3; // Botões de controle de velocidade
const char saida_pwm = 9;                                  // Pino de saída do PWM
unsigned int velocidade_anterior = 0;

void setup() {
 
  // Define os botões
  pinMode(Botao1, INPUT);
  pinMode(Botao2, INPUT);
  pinMode(Botao3, INPUT);
  pinMode(Botao4, INPUT);
  pinMode(saida_pwm, OUTPUT);
 
  // Saida Serial
  Serial.begin(9600);
  Serial.println("Sistemas de controle de velocidade para motor DC");
  Serial.println("=================================================");
  Serial.println("Velocidade: 0 RPM");
 
  // Timer1, rotina:
  Timer1.initialize(100000);  // 100 ms
}


void loop() {
 
  if (!digitalRead(Botao1))
    MudaVelocidade(0);
  else if(!digitalRead(Botao2))
    MudaVelocidade(25);
  else if(!digitalRead(Botao3))
    MudaVelocidade(50);
  else if(!digitalRead(Botao4))
    MudaVelocidade(100);
  
  delay(5);

}

void MudaVelocidade(int velocidade){
  
  if (velocidade != velocidade_anterior){
    int duty =  velocidade * 10.23;
    Timer1.pwm(saida_pwm, duty);
    Timer1.restart();
  
    Serial.print("Velocidade: ");
    Serial.print(velocidade);
    Serial.println("% da velocidade maxima");
    velocidade_anterior = velocidade;
  }
  
  delay(1000);
}
