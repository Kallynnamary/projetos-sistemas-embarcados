//Calculo do indice de massa corporal (IMC)

#include <LiquidCrystal.h>

#define RS  13
#define E   11
#define D4  9
#define D5  8
#define D6  7
#define D7  6
#define analogPin    A0   

//define as teclas a serem digitadas
const byte ROWS = 4; 
const byte COLS = 3; 
char keys[ROWS][COLS] = { 
                        {'1','2','3'},
                        {'4','5','6'},
                        {'7','8','9'},
                        {'*','0','#'}
                        };

LiquidCrystal lcd(RS, E, D4, D5, D6, D7);
boolean m=0;
float t;
int tecla, tecla2,a;
int altura,massa;
float faltura;
float imc;



void setup() {
  Serial.begin(9600);          //  setup serial
 
   Serial.println(" Clique em uma tecla do teclado");
   Serial.println(" ");
  
  
  lcd.begin(16, 2);      // LCD 16 colunas x 2 linhas
  
  // Deixe esse delay aqui
  delay(500);  
}

/************************************************************************************************************/
void loop() {

    limparLcd ();
    Serial.print("Digite altura em CENTIMETROS com 3 DIGITOS: ");
    lcd.print("USE 3 DIGITOS");

    delay (600);
    limparLcd ();
    lcd.print("DIGITE A ALTURA: ");
    lcd.setCursor(0, 1);  
    altura = lerDados();
    Serial.println();
    Serial.println();
    delay (200);
    limparLcd ();
    
    Serial.print("Digite o Peso em Kg com 3 DIGITOS: ");
    lcd.print("DIGITE O PESO: ");
    lcd.setCursor(0, 1);  
    massa = lerDados();
    delay (200);
    limparLcd ();
    
    Serial.println();
    faltura = altura/100.0;
    imc = massa/(faltura*faltura);
    Serial.print("SEU IMC: ");
    lcd.print("IMC: ");
    lcd.print(imc);
    Serial.println(imc);
    Serial.println();

    // define a interpretacao para os valores de IMC obtidos e printa na tela
    if (imc < 18.5){
    Serial.println ("Abaixo do peso");
        lcd.print("Abaixo do peso");
    }
    else if (imc >= 18.5 && imc <= 24.9 ){
    Serial.println ("Dentro do peso ideal");
        lcd.setCursor(0, 1);
        lcd.print("Dentro do peso");
    }
    else if (imc >= 25.0 && imc <= 29.9 ){
    Serial.println ("Acima do peso");  
         lcd.setCursor(0, 1); 
        lcd.print("Acima do peso");
    }
    else if (imc >= 30.0 && imc <= 34.9 ){
    Serial.println ("Obesidade grau 1");
        lcd.setCursor(0, 1);
        lcd.print("Obesidade grau 1");
    }
    else if (imc >= 35.0 && imc <= 39.9 ){
    Serial.println ("Obesidade grau 2");
         lcd.setCursor(0, 1);
        lcd.print("Obesidade grau 2");
    }
    else if (imc >= 40.0 ){
    Serial.println ("Obesidade grau 3");
        lcd.setCursor(0, 1);
        lcd.print("Obesidade grau 3");
    }
    delay (2000);
    Serial.println();
    Serial.println();
    Serial.println();
  
}
/************************************************************************************************************/
int readKeypad(void)//Lê um caracter do teclado;
{
   int val;
   
   do{
   val = analogRead(analogPin);  // #define analogPin    A0  
   delay(160);
   }
  while (val == 0);
  
  const byte ROWS = 4; 
  const byte COLS = 3; 
  /*char keys[ROWS][COLS] = { 
                          {'1','2','3'},
                          {'4','5','6'},
                          {'7','8','9'},
                          {'*','0','#'}
                           };*/


  if (val>950){
    return 1;
  }
  if (val>850 && val<=950){
    return 2;
  }
  if (val>800 && val<=850){
    return 3;  
  }
  if (val>750 && val<=800){
    return 4;  
  }  
  if (val>550 && val<=750){
    return 5;  
  }  
  if (val>450 && val<=550){
    return 6;  
  } 
  if (val>350 && val<=450){
    return 7;  
  } 
  if (val>250 && val<=350){
    return 8;  
  } 
  if (val>150 && val<=250){
    return 9;  
  }   
//  if (val>100 && val<=150){
//    return *;  
//  } 
  if (val>50 && val<=100){
    return 0;  
  } 
//  if (val<=50){
//    return #;  
//  } 
  
}
/************************************************************************************************************/
int lerDados (void)
{
  int i;
  int digitos[3];
  int altura;
  for (i = 0; i < 3; i++)
  {
digitos[i] = readKeypad();
        Serial.print (digitos[i]);
        lcd.print(digitos[i]);
  }
  altura = digitos[0]*100 + digitos[1]*10 + digitos[2];
  return altura;
 
}
/************************************************************************************************************/
void limparLcd (void){
   lcd.setCursor(0, 0);  
   lcd.print("                ");
   lcd.setCursor(0, 1);  
   lcd.print("                ");
   lcd.setCursor(0, 0);  
}
