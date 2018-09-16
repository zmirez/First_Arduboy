#define EEPROM_START_C1       EEPROM_STORAGE_SPACE_START
#define EEPROM_START_C2       EEPROM_START_C1+1
#define EEPROM_SCORE          EEPROM_START_C1+2

//EEPROMでスコア記憶

void initEEPROM(){
  unsigned char c1=EEPROM.read(EEPROM_START_C1);
  unsigned char c2=EEPROM.read(EEPROM_START_C2);

  if(c1 != 'S' || c2 != 'T'){
    EEPROM.update(EEPROM_START_C1,'S');
    EEPROM.update(EEPROM_START_C2,'T');
    EEPROM.put(EEPROM_SCORE,(unsigned int)0);
  }
}
void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

}

//このコリジョンは物体を四角形で囲ったような形

bool collision(){
  for(byte i=0;i<NUMBER_OF_OBSTACLES;i++){
    if(obstacles[i].enabled==true){
      Rect steveRect =Rect{steve.x,steve.y-getImageHeight(steve.image),
                            getImageWidth(steve.image),getImageHeight(steve.image)};
     Rect obsRect=Rect{obstacles[i].x,obstacles[i].y-getImageHeight(obstacles[i].image),
                         getImageWidth(obstacles[i].image),getImageHeight(obstacles[i].image)};

      if(arduboy.collide(steveRect,obsRect)){
        return true;
      }

    }
  }
return false;
}
