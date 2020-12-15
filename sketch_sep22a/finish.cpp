//
// Created by данил чикилев on 06.12.2020.
//

class Finish{
private:
    int x;
    int y;
    const int finishHeight = 15;
    const int finishWidth = 16;

public:
    Finish(int x, int y) : x(x), y(y) {}

    int getX() {
        return x;
    }
    

    int getY() const {
        return y;
    }

    int getWidth() {
        return finishWidth;
    }
    

    int getHeight() const {
        return finishHeight;
    }
};
