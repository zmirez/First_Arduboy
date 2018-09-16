GameStatus gameStatus = GameStatus::Introduction;

void setup() {
  // put your setup code here, to run once:

}

void loop() {
  // put your main code here, to run repeatedly:

  switch(gameStatus){

    case GameStatus::PlayGame:
      playGame();
      break;

    case GameStatus::GameOver:
      gameOver();
      break;
  }
}

void introduction(){

  EEPROM.get(EEPROM_SCORE,highScore);
  arduboy.clear();

  initialiseGame();

  arduboy.setCursor(17,12);
  arduboy.print(F("Press A to begin"));

  drawGround(false);
  drawSteve();
  drawScoreboard(false);
  arduboy.display();

  if(arduboy.pressed(A_BUTTON)){
    gameStatus = GameStatus::playGame;
    steve.stance=Stance::Running1;
  }
}
