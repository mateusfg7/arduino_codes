#include <inventor.h>
void setup() {
  // put your setup code here, to run once:
  BotaoNaPorta(D0);
  PonteHNaporta(D1,D2);
  PonteHNaporta(D4,D3);
}

void loop() 
{
  int x = 0;
  x++;
  while(BotaoPressionado(D0) == Sim)
    {
    // put your main code here, to run repeatedly:
    Girar(D1,D2);
    Girar(D4,D3);
    }
    PararMotor(D1,D2);
    PararMotor(D4,D3);
}
