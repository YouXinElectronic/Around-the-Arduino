/*
  Output the current state of the encoder and count
  Author: YXDZ
  Creation Date: 2022/8/25
  Version: V1.0
  github：https://github.com/YouXinElectronic/Around-the-Arduino
*/

#define A_pin 2 //A端口连接引脚
#define B_pin 3 //A端口连接引脚
#define key_pin 4 //按键端口引脚

int EncoderNum =0; 
int A_pin_State; 
int A_pin_BeforeState;
bool bottomState =0; 
bool timeState = 0;

void setup() 
{
  pinMode (A_pin,INPUT); 
  pinMode (B_pin,INPUT); 
  pinMode (key_pin,INPUT);
  Serial.begin (115200); 
  A_pin_BeforeState = digitalRead(A_pin); 
}
void loop() 
{
  bottomState = 1;
  
  A_pin_State = digitalRead(A_pin);
  if (A_pin_State != A_pin_BeforeState)
  {
    if (digitalRead(B_pin) != A_pin_BeforeState)
    {
      EncoderNum++; 
    } 
    else 
    {
      EncoderNum--; 
    }
    
  }
  A_pin_BeforeState = A_pin_State;

  if (digitalRead(key_pin) == LOW)
  {
    bottomState = 0;
  }

  if(millis()%500/5 == 0)
  {
    if(timeState == 0)
    {
      timeState = 1;
      Serial.print("EncoderNum:");
      Serial.print(EncoderNum/2);
      Serial.print("     button state:");
      Serial.println(bottomState);
      }
    }
  else
  {
    timeState = 0;
    }
}
