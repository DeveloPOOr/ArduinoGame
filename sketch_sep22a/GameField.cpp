//
// Created by данил чикилев on 21.10.2020.
//

#include "vector.cpp"
#include "Platform.cpp"
#include "Stairs.cpp"
#include "Hero.cpp"
#include <Adafruit_PCD8544.h>

class GameField {
private:
    Adafruit_PCD8544 display = Adafruit_PCD8544(9, 10, 11,12,  13);
    LinkedList<Platform>  platforms;
    LinkedList<Stairs> stairss;

//    Hero  *hero = new Hero(48, 42);

public:


    void createGameField() {
        display.begin();
        display.display();
        display.clearDisplay();
        this->platforms.Append(*(new Platform(0, 20, 15, 20)));
        this->stairss.Append(*(new Stairs(30, 48, 30, 28)));
    }

    void drawStairs(Stairs *stairs, Hero *hero) {


        const int betweenVertical = 7;
        const int betweenHorizontal = 4;

        int centerX = hero->getX() - display.width()/2;
        int centerY = hero->getY() - display.height();

                display.drawLine(stairs->getX0() - centerX, stairs->getY0() - centerY, stairs->getX() - centerX, stairs->getY() - centerY, BLACK);
                display.drawLine(stairs->getX0() - centerX + betweenVertical, stairs->getY0() - centerY, stairs->getX() - centerX + betweenVertical, stairs->getY() - centerY, BLACK);
            for (int i = 1; i < (stairs->getY0() - stairs->getY()) / betweenHorizontal; i++) {

                display.drawLine(stairs->getX0() - centerX, stairs->getY0() - centerY - i * betweenHorizontal, stairs->getX0() - centerX + betweenVertical,
                                 stairs->getY0() - centerY - i * betweenHorizontal, BLACK);

            }
        }

 void drawPlatform(Platform *platform, Hero *hero) {
        

        int centerX = hero->getX() - display.width()/2;
        int centerY = hero->getY() - display.height();
        
        display.drawLine(platform->getX0() - centerX, platform->getY0() - centerY, platform->getX() - centerX, platform->getY() - centerY, BLACK);
        

    }
    void drawHero() {
        display.fillRect((display.width()) / 2, display.height() - 5, 2, 2, BLACK);
    }

    void drawGameField(Hero *hero) {
        display.clearDisplay();
        display.display();
        display.setTextSize(1);
  display.setTextColor(BLACK);
  display.setCursor(0,0);
  display.println(hero->getX());
  
        if(this->stairss.moveToStart())
            do{
                this->drawStairs(&this->stairss.getCurrent(), hero);

            }while(this->stairss.next());

        if(this->platforms.moveToStart())
            do{
                this->drawPlatform(&this->platforms.getCurrent(), hero);

            }while(this->platforms.next());

        this->drawHero();
        display.display();
        
    }


};
