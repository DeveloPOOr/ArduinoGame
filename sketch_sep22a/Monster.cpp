class Monster{
private:
    bool alive;
    int x;
    int y;

    int monsterWidth = 12;
    int monsterHeight = 8;   

    int monsterRange = 48;
    int i;
    int speeds;
    int crushed = 0;         //  где ударил справа(1) слева (2)

public:

    void setCrushed(bool crushed) {
        Monster::crushed = crushed;
    }

    int getMonsterWidth() const {
        return monsterWidth;
    }

    int getMonsterHeight() const {
        return monsterHeight;
    }

    Monster(int x, int y) : x(x), y(y) {
      i = 0;
      speeds = 0;
     }

    int getX() const {
        return x;
    }

    int getY() const {
        return y;
    }

    void moveRight() {
        x++;
    }
    void moveLeft() {
        x--;
    }

    void moves() {
         

        if(speeds % 2 == 0){
          if(i <= monsterRange/2) {
            moveLeft();
        }
        if(i >monsterRange/2 && i <= monsterRange) {
            moveRight();
        }
        if(i == monsterRange)
            i = 0;

        if(crushed) {
          i = monsterRange - i;
          crushed = 0;
        }
        i++;
        }
        speeds++;

        


    }
};
