//
// Created by данил чикилев on 21.10.2020.
//
#include <SPI.h>
#include <Adafruit_GFX.h>
#include "vector.cpp"
#include "Platform.cpp"
#include "Stairs.cpp"
#include "Hero.cpp"
#include "Monster.cpp"
#include "finish.cpp"
#include <Adafruit_PCD8544.h>
#include "Bullet.cpp"

 static const unsigned char PROGMEM  heart_bmp[] =
    { B00101000,
      B01111100,
      B01111100,
      B00111000,
      B00010000,
    };


 static const unsigned char PROGMEM automat_bmp[] =
{ B00000000, B10000000,
  B00111111, B11111000,
  B00111111, B11100000,    //автомат
  B00110000, B10000000,
  B00100000, B10000000,
   };

static const unsigned char PROGMEM automatRot_bmp[] =
{ B00000001, B00000000,
  B00011111, B11111100,
  B00000111, B11111100,    //автомат
  B00000001, B00001100,
  B00000001, B00000100,
};


static const unsigned char PROGMEM finish_bmp[] =
{ B00110011, B00110000,
  B11001100, B11001100,
  B00110011, B00110000,    //автомат
  B11001100, B11001100,
  B00110011, B00110000,
  B11001100, B11001100,
  B00110011, B00110000,
  B11000000, B00000000,
  B11000000, B00000000,
  B11000000, B00000000,
  B11000000, B00000000,
  B11000000, B00000000,
  B11000000, B00000000,
  B11000000, B00000000,
  B11000000, B00000000,
};

static const unsigned char PROGMEM monster_bmp[] =
{ B00000101, B00000000,
  B00001111, B10000000,
  B01011111, B11010000,
  B01010010, B01010000,   //монстр
  B01111111, B11110000,
  B00011111, B11000000,
  B00101000, B10100000,
  B01000101, B00010000,
   };
  

class GameField {
private:
     Adafruit_PCD8544 display = Adafruit_PCD8544(9, 10, 11,12,  13);
    LinkedList<Platform>  platforms;
    LinkedList<Stairs> stairss;
    LinkedList<Monster> monsters;
    LinkedList<Bullet> bullets;

    Finish *finish;

    int bullets1 = 3;

    LinkedList<Automat> automats;

    int heartHeight = 5;
    int heartWidth = 7;

    int automatWidth = 16;
    int automatHeight = 5;

    const int finishHeight = 15;
    const int finishWidth = 16;

    



public:


    void createGameField() {
        display.begin();
        display.display();
        display.clearDisplay();
//        this->platforms.Append(*(new Platform(0, 20, 15, 20)));
//        this->platforms.Append(*(new Platform(0, 59, 84, 59)));
//        this->platforms.Append(*(new Platform(0, 58, 0, 43)));
//        this->platforms.Append(*(new Platform(84, 58, 84, 43)));
//        this->platforms.Append(*(new Platform(60, 40, 84, 40)));
//        
//        for(int i = 59; i < 190; i += 10){
//          this->platforms.Append(*(new Platform(0, i, 84, i)));
//        }
//        
////       this->platforms.Append(*(new Platform(0, 28, 50, 28)));
//        this->platforms.Append(*(new Platform(0, 200, 84, 200)));
//        this->stairss.Append(*(new Stairs(30, 57, 30, 37)));
//         this->monsters.Append(*(new Monster(40, 49)));
//         this->automats.Append(*(new Automat(54, 54)));
          

          this->platforms.Append(*(new Platform(0, 50, 150, 50)));    // самая нижня платформа
          
          
          this->platforms.Append(*(new Platform(0, 20, 58, 20)));    // второй уровень
          this->platforms.Append(*(new Platform(69, 20, 150, 20))); 
          this->stairss.Append(*(new Stairs(60, 49, 60, 20)));

          this->monsters.Append(*(new Monster(62, 10)));
          this->automats.Append(*(new Automat(80, 13)));
          this->automats.Append(*(new Automat(145, -15)));

          this->platforms.Append(*(new Platform(90, 10, 115, 10)));
          this->platforms.Append(*(new Platform(115, 2, 140, 2)));
          this->platforms.Append(*(new Platform(140, -8, 175, -8)));  // 5ая платформа
          this->monsters.Append(*(new Monster(160, -18)));
          
          this->stairss.Append(*(new Stairs(163, -9, 163, -37)));

          this->platforms.Append(*(new Platform(70, -37, 162, -37)));
          this->platforms.Append(*(new Platform(175, -9, 175, -64)));
          this->platforms.Append(*(new Platform(70, -37, 70, -64)));
          this->platforms.Append(*(new Platform(70, -64, 175, -64)));
          this->monsters.Append(*(new Monster(130, -48)));

          this->finish = new Finish(83, -52);
          
          
          
          
    }

    void createBullet(Hero *hero) {
        if(hero->isAimed()) {
            if(bullets1 != 0){
              Bullet *bullet;
              if(hero->getRotation() == 'r'){
                bullet = new Bullet(hero->getX() + 6, hero->getY() - 7, hero->getRotation());
              } else{
                bullet = new Bullet(hero->getX() - 6, hero->getY() - 7, hero->getRotation());
              }
                
          
                bullets.Append(*bullet);
                bullets1--;
                if(bullets1 == 0) {
                  hero->setAimed(false);
                  bullets1 = 3;
                }
                
            } 
                
            

        }
    }

    void bulletMove() {      // надо удалять если она вышла за пределы
        if(this->bullets.moveToStart())
            do{
                bullets.getCurrent().moves();

            }while(this->bullets.next());
    }

    void drawBullets(Hero *hero) {
        if(hero->isAimed()) {
            for( int i = 0; i < bullets1; i++) {
                display.drawLine(2*i, 1, 2*i, 3, BLACK);
            }
        }
    }

    void drawBullet(Bullet *bullet, Hero *hero) {
        int up = 10;
        int centerX = hero->getX() - display.width()/2;
        int centerY = hero->getY() - display.height() + up;
        display.drawRect(bullet->getX() - centerX,bullet->getY() - centerY , 2, 2, BLACK);
//        display.draw(, bullet->getY() - centerY, , bullet->getY() - centerY, BLACK);
    }


 void drawAutomat(Automat * automat, Hero *hero) {
        int up = 10;
        int centerX = hero->getX() - display.width()/2;
        int centerY = hero->getY() - display.height() + up;

        if(automat->getRotation() == 'r') {
            display.drawBitmap(automat->getX() - centerX, automat->getY() - centerY, automat_bmp, automat->getMonsterWidth(), automat->getMonsterHeight(), BLACK);
        } else {
            display.drawBitmap(automat->getX() - centerX, automat->getY() - centerY, automatRot_bmp, automat->getMonsterWidth(), automat->getMonsterHeight(), BLACK);
        }


    }
    void drawLives(Hero *hero) {
        for(int i = 0; i < hero->getLives(); i ++) {
            display.drawBitmap(display.width() - heartWidth - i*(heartWidth), 0, heart_bmp, heartWidth, heartHeight, BLACK);
        }
    }

    void drawFinish(Finish *finish, Hero *hero) {
      int up = 10;
        int centerX = hero->getX() - display.width()/2;
        int centerY = hero->getY() - display.height() + up;

        display.drawBitmap(finish->getX() - centerX, finish->getY() - centerY, finish_bmp, finishWidth, finishHeight, BLACK);
    }
    void drawStairs(Stairs *stairs, Hero *hero) {


        const int betweenVertical = stairs->getBetweenVertical();
        const int betweenHorizontal = stairs->getBetweenHorizontal();
        int up = 10;
        int centerX = hero->getX() - display.width()/2;
        int centerY = hero->getY() - display.height() + up;

                display.drawLine(stairs->getX0() - centerX, stairs->getY0() - centerY, stairs->getX() - centerX, stairs->getY() - centerY, BLACK);
                display.drawLine(stairs->getX0() - centerX + betweenVertical, stairs->getY0() - centerY, stairs->getX() - centerX + betweenVertical, stairs->getY() - centerY, BLACK);
            for (int i = 1; i < (stairs->getY0() - stairs->getY()) / betweenHorizontal; i++) {

                display.drawLine(stairs->getX0() - centerX, stairs->getY0() - centerY - i * betweenHorizontal, stairs->getX0() - centerX + betweenVertical,
                                 stairs->getY0() - centerY - i * betweenHorizontal, BLACK);

            }
        }
          
          
     void drawMonster(Monster *monster, Hero *hero) {
        int up = 10;
        int centerX = hero->getX() - display.width()/2;
        int centerY = hero->getY() - display.height() + up;

        display.drawBitmap(monster->getX()-centerX, monster->getY()-centerY, monster_bmp, monster->getMonsterWidth(), monster->getMonsterHeight(), BLACK);
        
        
    }

 void drawPlatform(Platform *platform, Hero *hero) {
        
        int up = 10;
        int centerX = hero->getX() - display.width()/2;
        int centerY = hero->getY() - display.height() + up;
        
        display.drawLine(platform->getX0() - centerX, platform->getY0() - centerY, platform->getX() - centerX, platform->getY() - centerY, BLACK);
        

    }
   void drawHero(Hero *hero) {
        int up = 10;
        if(hero->getPos() == 1) {    //ножки
            display.drawLine((display.width()) / 2, display.height() - 5 - up, display.width()/2 + 2, display.height()-up, BLACK);
            display.drawLine((display.width()) / 2, display.height() - 5-up, display.width()/2 - 2, display.height()-up, BLACK);
        }else{
            display.drawLine((display.width()) / 2, display.height() - 5-up, display.width()/2, display.height()-up, BLACK);
        }

        display.drawLine((display.width()) / 2, display.height() - 5-up, display.width()/2, display.height() - 11-up, BLACK);

        display.drawLine((display.width()) / 2, display.height() - 11-up, display.width()/2 + 2, display.height() - 6-up, BLACK);
        display.drawLine((display.width()) / 2, display.height() - 11-up, display.width()/2 - 2, display.height() - 6-up, BLACK);

        display.drawCircle(display.width()/2, display.height() - 13-up, 2, BLACK);

        if(hero->isAimed()) {
            if(hero->getRotation() == 'r'){
                display.drawBitmap((display.width()) / 2 - hero->getHeroWidth()/2 - 3, display.height()-up - hero->getHeroHeight()/2 - 2, automat_bmp, automatWidth, automatHeight, BLACK);
            }else{
                display.drawBitmap((display.width()) / 2 - hero->getHeroWidth()/2 - 8,  display.height()-up - hero->getHeroHeight()/2 - 2, automatRot_bmp, automatWidth, automatHeight, BLACK);
            }

        }
    }

    void drawGameField(Hero *hero) {
        display.clearDisplay();
        display.display();
//        display.setTextSize(1);
//        display.setTextColor(BLACK);
//        display.setCursor(0,0);
//        display.println(hero->getX());
//        display.println(hero->getY());
//        display.println(bullets.getLength());

        if(this->stairss.moveToStart())
            do{
                this->drawStairs(&this->stairss.getCurrent(), hero);

            }while(this->stairss.next());

        if(this->platforms.moveToStart())
            do{
                this->drawPlatform(&this->platforms.getCurrent(), hero);

            }while(this->platforms.next());

        if(this->monsters.moveToStart())
            do{
                this->drawMonster(&this->monsters.getCurrent(), hero);

            }while(this->monsters.next());


        if(this->automats.moveToStart())
            do{
                this->drawAutomat(&this->automats.getCurrent(), hero);

            }while(this->automats.next());

        if(this->bullets.moveToStart())
            do{
                this->drawBullet(&this->bullets.getCurrent(), hero);

            }while(this->bullets.next());

        this->drawHero(hero);
        drawLives(hero);
        drawBullets(hero);
        drawFinish(this->finish, hero);

        display.display();
        delay(20);

    }

    void monstersMove() {
        if(this->monsters.moveToStart()) {
            do{
               Monster *monster = &this->monsters.getCurrent();
               monster->moves();
            }while(this->monsters.next());
        }
    }


    
    bool isGrounded(Hero *hero, Platform *platform) {
                if(platform->getType() == 'h') {
                    if(hero->getX() + hero->getHeroWidth()/2 +1 > min(platform->getX0(), platform->getX()) && hero->getX() - hero->getHeroWidth()/2 - 1 < max(platform->getX(), platform->getX0()) && hero->getY()+1 == platform->getY()) {
                        return true;
                    } else{
                        return false;
                    }
                } else{
                    if(hero->getX() == platform->getX() && hero->getY()+1 == min(platform->getY(), platform->getY0())){
                        return true;
                    }else{
                      return false;
                    }
                }
    }

    bool isBlockedUp(Hero *hero, Platform *platform) {
        if(platform->getType() == 'h') {
            if(hero->getX() + hero->getHeroWidth()/2 >= min(platform->getX0(), platform->getX()) && hero->getX() - hero->getHeroWidth()/2 <= max(platform->getX(), platform->getX0()) && (hero->getY() - hero->getHeroHeight()) - 1 == platform->getY()) {
                return true;
            }else{
                return false;
            }
        } else {
            if(hero->getX() == platform->getX() && hero->getY() - hero->getHeroHeight() - 1 == max(platform->getY(), platform->getY0())){
                return true;
            } else {
                return false;
            }
        }
    }

   bool isBlockedLeft(Hero *hero, Platform *platform){
        if(platform->getType() == 'h') {
            if(hero->getX() - (hero->getHeroWidth()/2) - 1 == max(platform->getX(), platform->getX0())  && platform->getY0() >= hero->getY()-hero->getHeroHeight() && platform->getY() <= hero->getY()) {
                return true;
            }else{
                return false;
            }
        }else {
            if(max(platform->getY0(), platform->getY()) >= hero->getY()-hero->getHeroHeight() && min(platform->getY(), platform->getY0()) <= hero->getY() && hero->getX() - (hero->getHeroWidth()/2) - 1 == platform->getX()) {
                return true;
            } else{
                return false;
            }
        }
    }

    bool isBlockedRight(Hero *hero, Platform *platform){
        if(platform->getType() == 'h') {
            if(hero->getX() + (hero->getHeroWidth()/2) + 1 == min(platform->getX(), platform->getX0()) && platform->getY0() >= hero->getY()-hero->getHeroHeight() && platform->getY() <= hero->getY()) {
                return true;
            }else{
                return false;
            }
        }else {
            if(max(platform->getY0(), platform->getY()) >= hero->getY() - hero->getHeroHeight() && min(platform->getY(), platform->getY0()) <= hero->getY()  && hero->getX() + (hero->getHeroWidth()/2) + 1 == platform->getX()) {
                return true;
            } else{
                return false;
            }
        }
    }
    
bool isOnStair(Hero *hero, Stairs *stair) {
        if((hero->getX() < (stair->getX() + stair->getBetweenVertical()))  && (hero->getX() > stair->getX()) &&  (hero->getY() >= stair->getY()-1 && (hero->getY() - hero->getHeroHeight()/2) <= stair->getY0())) {
            if((analogRead(A1) > 500 || analogRead(A1) < 150) ) {
                return true;
            } 
        }else{
            return false;
        }
    }

    int isHeroCrashed(Hero *hero, Monster *monster) {
        //monster->getY() >= hero->getY() - hero->getHeroHeight() && monster->getY() - monster->getMonsterHeight() <= hero->getHeroHeight()
        if(monster->getY() + monster->getMonsterHeight() >= hero->getY() - hero->getHeroHeight() && monster->getY() <= hero->getY()){    // исправь потом
            if(hero->getX() + hero->getHeroWidth()/2  == monster->getX() || hero->getX() + hero->getHeroWidth()/2 + 1 == monster->getX()) {
                return 1;

            }
            if(hero->getX() - hero->getHeroWidth()/2 == monster->getX() + monster->getMonsterWidth() || hero->getX() - hero->getHeroWidth()/2 - 1 == monster->getX() + monster->getMonsterWidth()){
                return 2;
            }
        }
        return 0;
    }

     bool isHeroAimed(Hero *hero, Automat *automat) {
        if((automat->getY() <= hero->getY()) && ((automat->getY() + automat->getMonsterHeight()) >= (hero->getY() - hero->getHeroHeight())) && ( (automat->getX()  == hero->getX()) || (automat->getX() + automat->getMonsterWidth() == hero->getX()) ) ) {
            return true;
        }
        return false;
        
    }

    bool bulletToMonster(Bullet *bullet, Monster *monster) {
        if(bullet->getX() >= monster->getX() && bullet->getX() <= monster->getX() + monster->getMonsterWidth()) {
            if(bullet->getY() >= monster->getY() && bullet->getY() <= monster->getY() + monster->getMonsterHeight()) {
                return true;
            }
        }
        return false;
    }

    bool heroFinished(Finish *finish, Hero *hero) {
      if(hero->getX() + hero->getHeroWidth()/2 >= finish->getX() && hero->getX() - hero->getHeroWidth()/2 <= finish->getX() + finish->getWidth()) {
        if(hero->getY() >= finish->getY() && hero->getY() && hero->getY() - hero->getHeroHeight() <= finish->getY() + finish->getHeight()) {
          return true;
        }
      }

      return false;
    }

  


    void findHeroPos(Hero *hero) {
        hero->setBlockedRight(false);
        hero->setBlockedLeft(false);
        hero->setIsGrounded(false);
        hero->setBlockedUp(false);
        hero->setOnStair(false);
        if(heroFinished(this->finish, hero)) {
          hero->setIsFinished(true);
        }else {
        
        if(this->platforms.moveToStart())
            do{
                Platform *platform = &this->platforms.getCurrent();
                if(!hero->isGrounded1())
                hero->setIsGrounded(isGrounded(hero, platform));
                if(!hero->isBlockedLeft())
                hero->setBlockedLeft(isBlockedLeft(hero, platform));
                if(!hero->isBlockedRight())
                hero->setBlockedRight(isBlockedRight(hero, platform));
                if(!hero->isBlockedUp()){
                    hero->setBlockedUp(isBlockedUp(hero, platform));
                }
            }while(this->platforms.next());

        if(this->stairss.moveToStart())
            do{
                Stairs *stair = &this->stairss.getCurrent();
                if(!hero->isOnStair())
                    hero->setOnStair(isOnStair(hero, stair));
            }while(this->stairss.next());

        if(this->monsters.moveToStart())
            do{
                Monster *monster = &this->monsters.getCurrent();
                if(hero->getHeroCrashed() == 0){
                  int crush = isHeroCrashed(hero, monster);
                  hero->setHeroCrashed(crush);
                  monster->setCrushed(crush);
                }

                if(this->bullets.moveToStart())
                    do{
                        Bullet *bullet = &this->bullets.getCurrent();
                        if(bulletToMonster(bullet, monster)) {
                            bullets.DeleteCurrent();
                            monsters.DeleteCurrent();
                        }

                    }while(this->bullets.next());
                  
            }while(this->monsters.next());
            
        if(!hero->isAimed()){
          if(this->automats.moveToStart())
              do{
                  Automat *automat = &this->automats.getCurrent();

                  bool isAimed = isHeroAimed(hero, automat);
                  if(isAimed && !hero->isAimed()){
                    hero->setAimed(isAimed);
                    automats.DeleteCurrent();
                    
                  }
                  

              }while(this->automats.next());
        }
        }
    }

    void announce() {
        display.clearDisplay();
         display.display();
        display.setCursor(24, 24);
        display.setTextColor(BLACK);
        display.setTextSize(1);
        display.println("wasted!");
        display.display();
        
    }

    void announceV() {
        display.clearDisplay();
         display.display();
        display.setCursor(20, 24);
        display.setTextColor(BLACK);
        display.setTextSize(1);
        display.println("victory!");
        display.display();
        
    }


};
