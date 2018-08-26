#include<Arduboy.h>
Arduboy arduboy;

//初めてのArduboy
//上下ボタンで表示する数字を変える

int counter;
void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  arduboy.clear();
  counter=0;
  
}

void loop() {
  // put your main code here, to run repeatedly:
  arduboy.clear();
  if(arduboy.pressed(UP_BUTTON)==true){
    counter++;
  }
  if(arduboy.pressed(DOWN_BUTTON==true)){
    counter--;
  }
  if(counter==36){
    arduboy.setCursor(0,0);
    arduboy.print("Yay!");
  }
  arduboy.setCursor(0,0);
  arduboy.print(counter);
  arduboy.display();
  

}
