int temp, counter = 0;
    
void setup() {
  Serial.begin (9600);
  pinMode(2, INPUT_PULLUP); //Encoder ขา A
  pinMode(3, INPUT_PULLUP); //Encoder ขา B
  attachInterrupt(0, trigger, RISING); //สร้างอีเว้นกรณีเปลื่ยน Low เป็น High

  pinMode(13, OUTPUT); //Output กาว
  digitalWrite(13, LOW);
}
   
void loop() {
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

  if(counter > 999 || counter < 0){ counter = 0; } // จำกัดช่วง 0-999 (range 1000)

  if( //เงื่อนนไขยิงกาว
      (counter >= 0 && counter <= 99) 
      || (counter >= 200 && counter <= 299) 
      || (counter >= 400 && counter <= 499)
      || (counter >= 600 && counter <= 699)
      || (counter >= 800 && counter <= 899)
    ){
      digitalWrite(13, LOW);
    }else{
      digitalWrite(13, HIGH);
    }
}
