// Módulo: Funções de parametrização Openkit
// Company: OpenRobotics Ltda
// Versão: OpenKit 2014-2017 v 3.0

#include <Servo.h>
#include <Ultrasonic.h>

//Define os pinos para o trigger e echo
#define pino_trigger 3
#define pino_echo 5

Servo myservo1;
Servo myservo2;

#define D0 12
#define D1 9
#define D2 8
#define D3 7
#define D4 6

#define d0 12
#define d1 9
#define d2 8
#define d3 7
#define d4 6

#define D11 11
#define D12 12
#define D13 13
#define d11 11
#define d12 12
#define d13 13

#define Servo2 2
#define Servo1 1
#define servo2 2
#define servo1 1

#define Pressionado 0
#define pressionado 0
#define sim 0
#define Sim 0
#define nao 1
#define Nao 1

#define Claro 0
#define Escuro 1


#define Vertical 0
#define Horizontal 1

void PonteHNaporta(int x, int y)
{
   pinMode(x, OUTPUT);
   pinMode(y, OUTPUT);
}

void Direita(int x, int y)
{
   digitalWrite(x, HIGH);
   digitalWrite(y, LOW);
}

void Esquerda(int x, int y)
{
   digitalWrite(x, LOW);
   digitalWrite(y, HIGH);
}


void Girar(int x, int y)
{
   digitalWrite(x, HIGH);
   digitalWrite(y, LOW);
}

void PararMotor(int x, int y)
{
   digitalWrite(x, 0);
   digitalWrite(y, 0);
}


void PortaDeSaida(int x)
{
   pinMode(x,OUTPUT);  
}

int LeituraDaPorta(int pino)
{
   return analogRead(pino);
}

int LerCor(int pino)
{
   if (analogRead(pino)<500)
      return Escuro;
   return Claro;
}

int LerDistancia()
{
  int final = 0;
  int x;
  for (x=1; x<=5 ; x++)
  { 
     Ultrasonic ultrasonic(pino_trigger, pino_echo);
     final  = final + ultrasonic.convert(ultrasonic.timing(),Ultrasonic::CM);
  }
  final = final / 5;

  return final;
}

void LedNaPorta(int x)
{
   pinMode(x,OUTPUT);  
}

void MagneticoNaPorta(int x)
{
   pinMode(x,INPUT);  
}

void SireneNaPorta(int x)
{
   pinMode(x,OUTPUT);  
}

void LigarSirene(int x)
{
  digitalWrite(x, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void DesligarSirene(int x)
{
  digitalWrite(x, LOW);   // turn the LED on (HIGH is the voltage level)
}

void BotaoNaPorta(int x)
{
   pinMode(x,INPUT_PULLUP);  
}

void LigarLed(int x)
{
  digitalWrite(x, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void DesligarLed(int x)
{
  digitalWrite(x, LOW);   // turn the LED on (HIGH is the voltage level)
}

void PortaDeEntrada(int x)
{
   pinMode(x,INPUT);  
}

void Ligar(int x)
{
  digitalWrite(x, HIGH);   // turn the LED on (HIGH is the voltage level)
}

void Desligar(int x)
{
  digitalWrite(x, LOW);   // turn the LED on (HIGH is the voltage level)
}

void EsperarSegundos(float x)
{
  delay(x*1000);
}

void ServoNaPorta(int x)
{
  if(x==1)
    myservo1.attach(11);
  else
    myservo2.attach(10);
   
}




void PosicionarServo(int x, int pos)
{
    if(x==1)
       myservo1.write(pos);
    else
       myservo2.write(pos);
}


void TocarSom(int x, int som)
{
   tone(x,som);
}

void Silenciar(int x)
{
   noTone(x);
}

int Receber(int porta)
{ 
   return digitalRead(porta);
}


int BotaoPressionado(int porta)
{ 
   if (digitalRead(porta)==0)
      return Sim;
   return Nao;
}

void AtivarComunicacao()
{
   Serial.begin(9600);
}

void EnviarParaComputador(int x)
{
   Serial.println(x);
}

void EnviarParaComputador(String x)
{
   Serial.println(x);
}

void EnviarParaComputador(float x)
{
   Serial.println(x);
}

//Retorna se está aceso ou nao
int LuzNaPorta(int porta)
{
    if (analogRead(porta)<500)
       return Claro;
    else
       return Escuro;
}

int InclinacaoNaPorta(int porta)
{
    if (analogRead(porta)<500)
       return Vertical;
    else
       return Horizontal;
}

int LerSom(int porta)
{
   return analogRead(porta);
}

int LerMagnetico(int porta)
{
   return analogRead(porta);
}

int ReceberDoCelular()
{
   return Serial.read();
}

int SortearNumero(int min, int max)
{
   return random(min, max);

}

int LerTemperatura(int porta)
{ 
   return float(analogRead(A2))*5/(1023)/0.01;
}

