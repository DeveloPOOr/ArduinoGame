#include "GameField.cpp"

const byte X = A0; // постоянная для координаты Х

const byte Y = A1; // постоянная для координаты Y
const int BUTTON_DOWN = 4;
const int BUTTON_LEFT = 5;
long previousMillis = 0;
GameField *gameField; 
Hero  *hero;

volatile boolean intFlag = false;
void setup()   {
  pinMode(7, OUTPUT);
  digitalWrite(7, LOW);
  Serial.begin(9600);
  pinMode(BUTTON_DOWN, INPUT);
  digitalWrite(BUTTON_DOWN, HIGH);
  pinMode(BUTTON_LEFT, INPUT);
  digitalWrite(BUTTON_LEFT, HIGH);
  gameField = new GameField();
  hero = new Hero(42, 48);
  
  gameField->createGameField();
 
 
}

void loop() {
  

  
  
    
    if(!hero->isHeroAlive()) {
        gameField->announce();
             
    } else{
      if(hero->isFinished()) {
        gameField->announceV();
      } else {
            gameField->findHeroPos(hero);
  hero->fall();
 
  hero->moves(analogRead(A0));
  hero->movesUp(analogRead(A1));
  hero->movesDown(analogRead(A1));
  hero->heroCrash();
  gameField->drawGameField(hero);
  gameField->monstersMove();
  gameField->bulletMove();
  

  if(digitalRead(BUTTON_DOWN) == LOW) {

   hero->setJump(true);
   
   }
    if(digitalRead(BUTTON_LEFT) == LOW) {
        if(millis() - previousMillis > 1000) {
          previousMillis = millis();
          gameField->createBullet(hero);
        }
    }
    
   hero->oneJump();
      }
    }
   

}
