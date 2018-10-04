#include<Arduboy.h>
Arduboy arduboy;

int gamestate=0;
int ballx=62;
int bally=0;
int ballsize=4;
int ballright=1;
int balldown=1;
int paddlewidth=4;
int paddleheight=9;
int playerx=0;
int playery=0;
int computery=0;
int computerx=127-paddlewidth;
int justpressed=0;
int playerscore=0;
int computerscore=0;

void resetgame(){
  ballx=63;
  playerscore=0;
  computerscore=0;
}
void setup() {
  // put your setup code here, to run once:
  arduboy.begin();
  srand(7/8);
  arduboy.setFrameRate(60);
  arduboy.clear();
  
  

}

void loop() {
  if(!arduboy.nextFrame()){
    return;
  }
  arduboy.clear();
  switch(gamestate){
    case 0:
      arduboy.setCursor(0,0);
      arduboy.print("Title Screen");
      if(arduboy.pressed(A_BUTTON) and justpressed==0){
        justpressed=1;
        gamestate=1;
      }
      break;
    case 1:
      arduboy.setCursor(0,0);
      //arduboy.print("Gameplay");
      arduboy.fillRect(ballx,bally,ballsize,ballsize,WHITE);
      if(ballright==1){
        ballx=ballx+1;
      }
      if(ballright==-1){
        ballx-=1;
      }
//      if(ballx==playerx+paddlewidth){
//        ballright=1;
//      }
//      if(ballx==0){
//        ballright=1;
//      }
//      if(ballx+ballsize==127){
//        ballright=-1;
//      }
      if(balldown==1){
        bally+=1;
      }
      if(balldown==-1){
        bally-=1;
      }
      if(bally==0){
        balldown=1;
      }
      if(bally+ballsize==63){
        balldown=-1;
      }
      arduboy.fillRect(playerx,playery,paddlewidth,paddleheight,WHITE);
      if(arduboy.pressed(UP_BUTTON) and playery>0){
        playery=playery-1;
      }
      if(arduboy.pressed(DOWN_BUTTON) and playery+paddleheight<63){
        playery=playery+1;
      }
      
      arduboy.fillRect(computerx,computery,paddlewidth,paddleheight,WHITE);
      if(ballx>110 or rand()%20<=3){
        if(bally<computery){
          computery=computery-1;
        }
        if(bally+ballsize>computery+paddleheight){
          computery=computery+1;
        }
      }
      if(ballx==playerx+paddlewidth and playery<bally+ballsize and playery+paddleheight>bally){
        ballright=1;
      }
      if(ballx+ballsize==computerx and computery < bally + ballsize and computery + paddleheight > bally){
       ballright=-1; 
      }
      if(ballx<-10){
        ballx=63;
        computerscore=computerscore+1;
      }
      if(ballx>130){
        ballx=63;
        playerscore=playerscore+1;
      }
      if(playerscore==5){
        gamestate=2;
      }
      if(computerscore==5){
        gamestate=3;
      }
      arduboy.setCursor(20,0);
      arduboy.print(playerscore);

      arduboy.setCursor(101,0);
      arduboy.print(computerscore);
      break;
    case 2:
      arduboy.setCursor(64,20);
      arduboy.print("You Win!");
      if(arduboy.pressed(A_BUTTON)and justpressed==0){
        justpressed=1;
        resetgame();
        gamestate=0;
      }
      break;
    case 3:
      arduboy.setCursor(64,20);
      arduboy.print("Game Over..");
      if(arduboy.pressed(A_BUTTON) and justpressed==0){
        justpressed=1;
        resetgame();
        gamestate=0;
      }
      break;
    
  }
  if(arduboy.notPressed(A_BUTTON)){
    justpressed=0;
  }
   
 
  // put your main code here, to run repeatedly:
  arduboy.display();
}
