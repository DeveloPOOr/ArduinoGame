

//
// Created by данил чикилев on 20.10.2020.
//
#include "Automat.cpp"
class Hero {
private:
    int x;
    int y;
    bool alive = true;
    int lives = 3;
    int pos = 1;
    bool isGrounded = false;
    bool jump = false;
    bool inJump = false;
    bool finished = false;

    bool aimed = false;
    char automatRot = 'r';

    
    int heroHeight = 13;
    int heroWidth = 4;
    
    int heroCrashed = 0;
    bool blockedLeft = false;
    bool blockedRight = false;
    bool blockedUp = false;
    bool onStair = false;

public:

    char getRotation() const {
        return automatRot;
    }

    bool isAimed() const {
        return aimed;
    }

    void setAimed(bool aimed) {
        Hero::aimed = aimed;

    }

int getLives() const {
        return lives;
    }
    void setLives(int aimed) {
        Hero::lives = aimed;
        alive = true;
    }

 void setHeroCrashed(int heroCrashed) {
        Hero::heroCrashed = heroCrashed;
    }

    int getHeroCrashed() const {
        return heroCrashed;
    }
    bool isOnStair() const {
        return onStair;
    }
    
    bool isBlockedUp() const {
        return blockedUp;
    }

    int getHeroHeight() const {
        return heroHeight;
    }

    int getHeroWidth() const {
        return heroWidth;
    }

    bool isBlockedLeft() const {
        return blockedLeft;
    }

    bool isBlockedRight() const {
        return blockedRight;
    }

    void setBlockedLeft(bool blockedLeft) {
        Hero::blockedLeft = blockedLeft;
    }

    void setBlockedRight(bool blockedRight) {
        Hero::blockedRight = blockedRight;
    }

    void setBlockedUp(bool blockedUp) {
        Hero::blockedUp = blockedUp;
    }

    int getPos() const {
        return pos;
    }

    bool isJump() const {
        return jump;
    }

    void setJump(bool jump) {
        Hero::jump = jump;
    }
    void setOnStair(bool isGrounded) {
        Hero::onStair = isGrounded;
    }
    void setIsGrounded(bool isGrounded) {
        Hero::isGrounded = isGrounded;
    }

    bool isGrounded1() const {
        return isGrounded;
    }

    void setIsFinished(bool isGrounded) {
        Hero::finished = isGrounded;
    }

    bool isFinished() const {
        return finished;
    }


    Hero(int x, int y) : x(x), y(y) { }

    int getX() {
        return x;
    }

    void setX(int x) {
        Hero::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Hero::y = y;
    }

     void moves(int moves) {
        static int i = 1;
        if (moves > 500 && !blockedRight && !heroCrashed) {
            if(aimed && automatRot == 'l') {
                automatRot = 'r';
            }
            this->x += 1;
            i+=1;
            if(i%6 == 0) {
                this->pos *=-1;
            }
        } else {
            if (moves < 150 && !blockedLeft && !heroCrashed) {
                if(aimed && automatRot == 'r') {
                    automatRot = 'l';
                }
                this->x -= 1;
                i+=1;
                if(i%6 == 0) {
                    this->pos *=-1;
                }
            }else {
                this->pos = 1; //то есть он стоит
            }
        }
    }

    void movesUp(int moves) {
        if (moves > 500 && onStair && !blockedUp && !heroCrashed) {
            this->y -= 1;
        }
    }

    void movesDown(int moves) {
        if (moves < 150 && onStair && !isGrounded && !heroCrashed) {
            this->y += 1;
        }
    }

    void fall() {
        if(!isGrounded && !onStair && !heroCrashed){
            y ++;
        }
    }

    void oneJump(){
        static int i = 0;

        if(i<12 && jump && !inJump && !heroCrashed && !blockedUp) {
            y-=2;
            i++;
        }else{
            i = 0;
            jump = false;
            inJump = true;
        }
        if(isGrounded || onStair){
            jump = false;
            inJump = false;
        }
    }

    void heroCrash() {
        static int i = 0;
        int otskok = 10;
        if(heroCrashed > 0) {
            if(i < otskok){
                if(i%2 == 0){
                    y--;
                }else{
                    if(heroCrashed == 1){
                        x--;
                    } else{
                        x++;
                    }
                }
                i++;
            }else{
                heroCrashed = 0;
                i = 0;
                lives--;
                if(lives == 0) {
                    alive = false;
                }
            }
        }
    }

    bool isHeroAlive() {
        return alive;
    }


};
