// code written for Arduino-UNO bye praveen kumar
#define LMF  8
#define LMB  9
#define RMF 10
#define RMB 11
#define LIR  6
#define RIR  7
#define SWT  5
boolean IR1, IR2,mode;
char RD;
void setup() 
{
 pinMode(LMF,OUTPUT);
 pinMode(LMB,OUTPUT);
 pinMode(RMF,OUTPUT);
 pinMode(RMB,OUTPUT);
 pinMode(LIR, INPUT);
 pinMode(RIR, INPUT);
 Serial.begin(9600);
}

void loop() {
 mode = digitalRead(SWT);
 if(mode == false){
 IR1=digitalRead(LIR);
 IR2=digitalRead(RIR);
 if(IR1==false)
 {
  digitalWrite(LMF,HIGH);
  digitalWrite(LMB, LOW);
 }
 else
 {
  digitalWrite(LMF, LOW);
  digitalWrite(LMB, LOW);
 }
 if(IR2==false)
 {
  digitalWrite(RMF,HIGH);
  digitalWrite(RMB, LOW);
 }
 else
 {
  digitalWrite(RMF, LOW);
  digitalWrite(RMB, LOW);
 }
 }
 else
 {
  while (Serial.available())
    {
     RD=Serial.read();
    }
  if(RD=='f')
    {
    digitalWrite(LMF,HIGH);
    digitalWrite(LMB, LOW);
    digitalWrite(RMF,HIGH);
    digitalWrite(RMB, LOW);
    }
    if(RD=='b')
    {
    digitalWrite(LMF, LOW);
    digitalWrite(LMB,HIGH);
    digitalWrite(RMF, LOW);
    digitalWrite(RMB,HIGH);
    }
    if(RD=='r')
    {
    digitalWrite(LMF, LOW);
    digitalWrite(LMB, LOW);
    digitalWrite(RMF,HIGH);
    digitalWrite(RMB, LOW);
    }
    if(RD=='l')
    {
    digitalWrite(LMF,HIGH);
    digitalWrite(LMB, LOW);
    digitalWrite(RMF, LOW);
    digitalWrite(RMB, LOW);
    }
    if(RD=='s')
    {
    digitalWrite(LMF, LOW);
    digitalWrite(LMB, LOW);
    digitalWrite(RMF, LOW);
    digitalWrite(RMB, LOW);
    }
 }
}
