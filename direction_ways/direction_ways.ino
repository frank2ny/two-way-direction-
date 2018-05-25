#include<LiquidCrystal.h>
LiquidCrystal lcd(6,7,5,4,3,2);

String in, out;
int total = 0;

void setup() {
  pinMode(8, INPUT);
  pinMode(9, INPUT);
  pinMode(12,OUTPUT);
  Serial.begin(9600);
    lcd.begin(16,2);
    lcd.print("Visitor Counter");
    Serial.println("Visitor Counter");

     Serial.println(" \n No one in the Room ..! \n");
    delay(2000);
    lcd.clear();
    lcd.begin(16,2);
    lcd.print("REQUIRED : 300 ");
     lcd.setCursor(0,1);
  lcd.print("CURRENT : ");  lcd.print(total);
    
}

void show() {
  Serial.print(total);
    Serial.println(" people in room.");
    lcd.begin(16,2);
    lcd.print("REQUIRED : 300 ");
    lcd.setCursor(0,1);
  lcd.print("CURRENT : ");  lcd.print(total);
    if(total>20){// number to exceeded
       Serial.println("===================================");
       Serial.println(" *** MAXIMUN No. REACHED **** ");
       Serial.println("===================================");
      int i=0;
      for(i=0;i<2;i++){
        digitalWrite(12,HIGH);
        delay(500);
        digitalWrite(12,LOW);
        delay(500);
         }}
}
void loop() {
  if (digitalRead(9) == LOW) {
    while (digitalRead(8) == HIGH) {
    }
    analogWrite(A1, 255);
    Serial.print("Person entered .. \n there are : ");
    total++;
    
    show();
    delay(1000);
    analogWrite(A1, 0);
  }
  
  else if (digitalRead(8) == LOW) {
    while (digitalRead(9) == HIGH) {
    }
    analogWrite(A0, 255);
    Serial.print("Person exited .. \n there are ");
    total--;
    if(total<=0){
      total=0;
      }
    show();
    delay(1000);
    analogWrite(A0, 0);
  }
  
}
