//
// Created by данил чикилев on 27.11.2020.
//

class Automat{
private:
    int x;
    int y;

    int automatWidth = 16;
    int automatHeight = 5;

    char rotation = 'r';

public:

    Automat(int x, int y) : x(x), y(y) {}

    int getX() const {
        return x;
    }

    void setX(int x) {
        Automat::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Automat::y = y;
    }

    char getRotation() const {
        return rotation;
    }

    int getMonsterWidth() const {
        return automatWidth;
    }

    int getMonsterHeight() const {
        return automatHeight;
    }



    void setRotation(char rotation) {
        Automat::rotation = rotation;
    }
};
