#include<stdlib.h>
#define R 3
#define G 5
#define B 6

void setup() {
  // put your setup code here, to run once:
  pinMode(R, OUTPUT);
  pinMode(G, OUTPUT);
  pinMode(B, OUTPUT);
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  magic(R, G, B);

  //纯色呼吸灯
  //Init();   //注释掉就不是纯色呼吸灯

  while (1)
  {
    breathing();
  }


}


void magic(int a, int b, int c)
{
  for (int i = 0; i < 255; i++)
  {
    analogWrite(a, i);
    analogWrite(b, 255 - i);
    analogWrite(c, 100 - i);
    delay(50);
  }
  for (int i = 0; i < 255; i++)
  {
    analogWrite(b, i);
    analogWrite(a, 255 - i);
    analogWrite(c, 100 - i);
    delay(50);
  }
  for (int i = 0; i < 255; i++)
  {
    analogWrite(c, i);
    analogWrite(b, 255 - i);
    analogWrite(a, 100 - i);
    delay(50);
  }
}


void breathing()
{
  int j = choose();
  for (int i = 0; i < 255; i++)
  {
    analogWrite(j, i);
    delay(5);
  }
  delay(5);
  for (int k = 255; k > 0; k--)
  {
    analogWrite(j, k);
    delay(5);
  }
  delay(20);
}

int choose()
{
  int z;
  int j = random(1, 3);
  switch (j)
  {
    case 1: z = R; break;
    case 2: z = G; break;
    case 3: z = B; break;
  }
  return z;
}

void Init()
{
  analogWrite(R, 0);
  analogWrite(G, 0);
  analogWrite(B, 0);

}
