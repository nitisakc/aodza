int temp, counter = 0;
bool btnInput = 0;
int rg;
    
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
  rg = map(analogRead(A1), 0, 1024, 0, 1000);
  if(digitalRead(9) == LOW){
      btnInput = 1;
      counter = 0;
  }
    
  if( counter != temp ){ //ค่าเปลื่ยนแปลงให้แแสดงผล
    Serial.println (counter);
    temp = counter;
  }
}
 
void trigger() {
  //นับ Encoder ทิศทางเดียว
  if(digitalRead(3) == LOW && digitalRead(2) == HIGH) {
    counter++;
  }else{
    counter--;
  }
    
  if(btnInput == 1 && counter > (rg-1) && counter < ((rg*2)-1)){
      digitalWrite(13, HIGH);
  }else{
      digitalWrite(13, LOW); 
  }
    
  if(counter > ((rg*2)-1)){
      btnInput = 0;
  }
}
