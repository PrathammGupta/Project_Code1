#define Sensorpin A0   

#define Green_led 8 
#define Red_led 9 

#define inn1 2  
#define inn2 3  

int Set_Timer=5;

int Sensor =0;
int second_s =0;
int flag=0;
long delay_Start;

void setup(){ 
Serial.begin(9600);

pinMode(Sensorpin, INPUT); 

pinMode(Red_led,OUTPUT); 
pinMode(Green_led,OUTPUT); 

pinMode(inn1,OUTPUT); 
pinMode(inn2,OUTPUT); 

digitalWrite(inn1, LOW);  
digitalWrite(inn2, HIGH); 
delay(2000); 
digitalWrite(inn1, LOW); 
digitalWrite(inn2, LOW); 
}

void loop(){
Sensor = digitalRead(Sensorpin);
if(Sensor==1){
Serial.println("Motion detected!");
digitalWrite(Red_led, HIGH); 
digitalWrite(Green_led, HIGH); 

if(flag==0){
digitalWrite(inn1, HIGH); 
digitalWrite(inn2, LOW); 
delay(2000); 
digitalWrite(inn1, LOW);
digitalWrite(inn2, LOW);
}

second_s=0;
flag=1;
delay_Start = millis(); 
}else{ 
Serial.println("Motion stopped!");
digitalWrite(Green_led, LOW); 
}

if((flag==1) && (millis()- delay_Start) > 999){ 
second_s = second_s+1;  
delay_Start = millis(); 
}

if(second_s>Set_Timer){
digitalWrite(Red_led, LOW); 

digitalWrite(inn1, LOW); 
digitalWrite(inn2, HIGH);
delay(2000); 
digitalWrite(inn1, LOW); 
digitalWrite(inn2, LOW); 
flag=0;
second_s=0; 
}

delay(100);
}
