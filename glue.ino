int temp, counter = 0;
bool btnInput = 0;
int range, rangeTemp;
    
void setup() {
  Serial.begin (9600);
  pinMode(9, INPUT_PULLUP); //BTN
  pinMode(2, INPUT_PULLUP); //Encoder ขา A
  pinMode(3, INPUT_PULLUP); //Encoder ขา B
  attachInterrupt(0, trigger, RISING); //สร้างอีเว้นกรณีเปลื่ยน Low เป็น High

  pinMode(13, OUTPUT); //Output กาว
  digitalWrite(13, LOW);
}
   
void loop() {
  range = map(analogRead(A1), 0, 1024, 0, 1000);
  if(digitalRead(9) == LOW){
      btnInput = 1;
      counter = 0;
  }
    
  if(range != rangeTemp){ //ค่าเปลื่ยนแปลงให้แแสดงผล
    Serial.println(range);
    rangeTemp = range;
      
     //แสดงค่า 7segment
  }
}
 
void trigger() {
  //นับ Encoder ทิศทางเดียว
  if(digitalRead(3) == LOW && digitalRead(2) == HIGH) {
    counter++;
  }else{
    counter--;
  }
    
  if(btnInput == 1 && counter > (range-1) && counter < ((range*2)-1)){
      digitalWrite(13, HIGH); //ฉีดกาว
  }else{
      digitalWrite(13, LOW); //หยุดฉีด
  }
    
  if(counter >= ((range*2)-1)){
      btnInput = 0;
  }
}
