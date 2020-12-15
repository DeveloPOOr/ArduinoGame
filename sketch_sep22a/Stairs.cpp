//
// Created by данил чикилев on 20.10.2020.
//

class Stairs{
private:

    int x0;
    int y0;
    int x;
    int y;
    const int betweenVertical = 7;
    const int betweenHorizontal = 4;
public:
    Stairs(int x0, int y0, int x, int y) : x0(x0), y0(y0), x(x), y(y) {}

    const int getBetweenVertical() const {
        return betweenVertical;
    }

    const int getBetweenHorizontal() const {
        return betweenHorizontal;
    }
    int getX0() const {
        return x0;
    }

    void setX0(int x0) {
        Stairs::x0 = x0;
    }

    int getY0() const {
        return y0;
    }

    void setY0(int y0) {
        Stairs::y0 = y0;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Stairs::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Stairs::y = y;
    }
};
