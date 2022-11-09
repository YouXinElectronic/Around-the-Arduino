#define JOYSTICK_X    A5  //定义X输入引脚
#define JOYSTICK_Y    A4  //定义Y输入引脚
#define JOYSTICK_B    2   //定义按键输入引脚

int value_x,value_y,value_b;  //定义记录模拟输入的变量
void setup()
{
    pinMode(JOYSTICK_X, INPUT);  //初始化X引脚
    pinMode(JOYSTICK_Y, INPUT);  //初始化Y引脚
    pinMode(JOYSTICK_B, INPUT_PULLUP);  //初始化按键引脚
    Serial.begin(9600);  //设置波特率
}

void loop() 
{
    value_x=analogRead(JOYSTICK_X);  //读取X模拟值
    value_y=analogRead(JOYSTICK_Y);  //读取Y模拟值
    value_b=digitalRead(JOYSTICK_B); //读取按键输入 
    if(value_x<=25)
    {
        Serial.println("right"); //print right

    }
    else if(value_x>=990)
    {
         Serial.println("left"); //打印left
    }
    if(value_y<=50)  //
    {
        Serial.println("down"); //打印up
    }
    else if(value_y>=990) //
    {
        Serial.println("up"); //打印down
    }
    if(value_b == LOW)  //
    {
        Serial.println("enter");//打印enter
    }
    delay(100);
}
