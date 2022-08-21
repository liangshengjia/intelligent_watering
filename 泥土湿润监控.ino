/*
 * “变废为宝”智能浇花神器
 * 盛嘉创客实验室
 * 广州市越秀区铁一小学四年一班
 * 作者:梁盛嘉
 * 2022-8-10
 * 智能浇花神器的主要功能：
 * 1.检测泥土湿润程度；
 * 2.电动开关控制水流；
 * 3. 具备联网能力，可用手机控制；
 * 4.用单片机做主控，加入复杂的智能策略
 * 
 */
int sensorPin = A0;    
int pumpPin = 13;      
int sensorValue = 0;  

void setup() {
 
  pinMode(pumpPin, OUTPUT);  
  Serial.begin(115200); //app bt
}

void loop() {
  
  sensorValue = analogRead(sensorPin); 
  Serial.write(0xA5);
  Serial.write(0x5A);
  Serial.write(0x05);
  Serial.write(0x00); 
  Serial.write(sensorValue/4); 
  Serial.write(sensorValue/4+5);  
  Serial.write(0xAA); 
    
  //Serial.println(sensorValue);  
  if (sensorValue>600){

    //Serial.println("gan  干"); 
    digitalWrite(pumpPin, LOW);
  }else{
    //Serial.println("shi  湿"); 
    digitalWrite(pumpPin, HIGH);
  }

  delay(100); 
  
}
