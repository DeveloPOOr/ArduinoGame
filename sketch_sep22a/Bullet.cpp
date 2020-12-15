//
// Created by данил чикилев on 28.11.2020.
//

class Bullet{
private:

    int x;
    int y;

    int bulletHeight;
    int bulletWidth;

    bool crashed = false;

    char rotation;

public:

    Bullet(int x, int y, char r) : x(x), y(y), rotation(r) {}

    bool isCrushed() const {
        return crashed;
    }

    char getRotation() const {
        return rotation;
    }


    void setCrushed(bool crushed) {
        Bullet::crashed = crushed;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Bullet::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Bullet::y = y;
    }

    int getBulletHeight() const {
        return bulletHeight;
    }

    void setBulletHeight(int bulletHeight) {
        Bullet::bulletHeight = bulletHeight;
    }

    int getBulletWidth() const {
        return bulletWidth;
    }

    void setBulletWidth(int bulletWidth) {
        Bullet::bulletWidth = bulletWidth;
    }

    void moves() {
        if(rotation == 'l') {
            x--;
        }else{
            x++;
        }
    }
};
