const int Xpin = A0;
const int Ypin = A1;
const int Zpin = A2;

//初始化每个轴的最小和最大原始范围
//Initialize min and max original range for each axis
int axisMin=0;
int axisMax=1023;

//加速度最大值和最小值范围
//Acceleration maximum and minimum range
int AccelMin=-3000;
int AccelMax=3000;

//采集多个样本以减少噪音
//Take multiple samples to reduce noise
const int sampleSize=10;


void setup() {
  // put your setup code here, to run once:
  analogReference(EXTERNAL);  //AREF引脚输入3.3V基准电压（AREF pin input 3.3V reference voltage）
  Serial.begin(115200);
}

void loop() {
  // put your main code here, to run repeatedly:

  //读取原始值
  //read raw value
  int xval=ReadAxis(Xpin);
  int yval=ReadAxis(Ypin);
  int zval=ReadAxis(Zpin);

//计算每个轴的加速度值
//Calculate the acceleration value for each axis
  float xAccel=Accel(xval);
  float yAccel=Accel(yval);
  float zAccel=Accel(zval);

  Serial.println("               X  ,  Y  ,  Z");
  Serial.print("analog:       ");
  Serial.print(xval);
  Serial.print(" , ");
  Serial.print(yval);
  Serial.print(" , ");
  Serial.println(zval);
  Serial.print("acceleration: ");
  Serial.print(xAccel,0);
  Serial.print("G , ");
  Serial.print(yAccel,0);
  Serial.print("G , ");
  Serial.print(zAccel,0);
  Serial.println("G , ");
  Serial.println("");
  delay(200);
  
}


//取样并返回平均值
//sample and return the mean
int ReadAxis(int DataPin)
{
  long reading = 0;
  analogRead(DataPin);
  delay(1);
  for(int i=0;i<sampleSize;i++)
  {
    reading +=analogRead(DataPin);
    }
    return reading/sampleSize;
  }

//模拟量转化成加速度
//Convert analog to acceleration
float Accel(int Value)
{
  float accel=(map(Value,axisMin,axisMax,AccelMin,AccelMax))/1000.0;
  return accel;
  }
