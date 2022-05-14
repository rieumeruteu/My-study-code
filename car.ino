//L298N 모더드라이버 예제

int ML1=3;
int ML2=4;
int MR1=5;
int MR2=6;


void setup() {
  pinMode(MR1,OUTPUT);
  pinMode(MR2,OUTPUT);
  pinMode(ML1,OUTPUT);
  pinMode(ML2,OUTPUT);
}

void loop() {
 Run_Wheel();
 delay(10000);
 Stop_Wheel();
 delay(1000);
}


void Right_Wheel()
{
  digitalWrite(MR1,LOW);
  digitalWrite(MR2,HIGH);
  delay(20);
}

void Left_Wheel()
{
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,HIGH);
  delay(20);
}

void Stop_Wheel_R()
{
  
  digitalWrite(MR1,HIGH);
  digitalWrite(MR2,HIGH);
  delay(20);
}

void Stop_Wheel_L()
{
  digitalWrite(ML1,HIGH);
  digitalWrite(ML2,HIGH);
  delay(20);
}

void Stop_Wheel()
{
  digitalWrite(ML1,LOW);
  digitalWrite(ML2,LOW);
  digitalWrite(MR1,LOW);
  digitalWrite(MR2,LOW);
  delay(20);
}
void Run_Wheel()
{
  digitalWrite(MR1,LOW);
  digitalWrite(MR2,HIGH);
  digitalWrite(ML1,HIGH);
  digitalWrite(ML2,LOW);
  delay(20);
}
