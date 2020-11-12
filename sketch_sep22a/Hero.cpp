//
// Created by данил чикилев on 20.10.2020.
//

class Hero {
private:
    int x;
    int y;
    bool alive;
    int lives;

    int heroHeight;
    int leftBoard = this->getX() - 84 / 2;
    int rightBoard = this->getX() + 84 / 2 - 1;

    int topBoard = this->getY() - 48 + 3;
    int bottomBoard = this->getY() + 2;

public:
    int getLeftBoard() const {
        return leftBoard;
    }

    int getRightBoard() const {
        return rightBoard;
    }

    int getTopBoard() const {
        return topBoard;
    }

    int getBottomBoard() const {
        return bottomBoard;
    }

    Hero(int x, int y) : x(x), y(y) {}

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
        if (moves > 400) {
            this->x += 2;
        } else {
            if (moves < 200) {
                this->x -= 2;
            }
        }
    }

};
