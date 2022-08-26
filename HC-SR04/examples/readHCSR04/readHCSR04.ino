/*
功能：通过SR04超声波传感器进行测距，并通过串口监视器显示测出的距离
*/
 
const int Trig = 3;                                           // 设定SR04连接的Arduino引脚
const int Echo = 4; 
double distance,timer;
void setup() 
{   
        Serial.begin(9600);                                    // 初始化串口通信及连接SR04的引脚
        pinMode(Trig, OUTPUT); 
  
        pinMode(Echo, INPUT);                                  //要检测引脚上输入的脉冲宽度，需要先设置为输入状态
    Serial.println("The distance is :");
} 
void loop() 
{ 
    
        digitalWrite(Trig, LOW);                                 
        delayMicroseconds(2);                                   
        digitalWrite(Trig, HIGH);                               
        delayMicroseconds(10);                                  //产生一个10us的高脉冲去触发SR04
        digitalWrite(Trig, LOW);                                
        
        timer = pulseIn(Echo, HIGH);                              // 检测脉冲宽度，注意返回值是微秒us
        distance = timer /58 ;                                  //计算出距离,输出的距离的单位是厘米cm
 
        Serial.print(distance);                                //把得到的距离值通过串口通信返回给电脑，通过串口监视器显示出来
        Serial.println("cm"); 
        delay(1000); 
}
