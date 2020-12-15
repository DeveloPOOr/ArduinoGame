//
// Created by данил чикилев on 20.10.2020.
//


class Platform {     //x0 < x please
private:            // if x0 = x then y0 < y
    int x0;
    int y0;
    int x;
    int y;
    char type = whatType();
    int length1 = whatLength();
    


    char whatType()  {
        if( x0 == x ) {
            return 'v';
        } else {
            return 'h';
        }
    }

    int whatLength() {
        if( type == 'h') {      
            return x - x0;
        }else {
            return y0 - y;
        }
    }


public:


    Platform(int x0, int y0, int x, int y) : x0(x0), y0(y0), x(x), y(y) {}

    int getX0() const {
        return x0;
    }

    void setX0(int x0) {
        Platform::x0 = x0;
    }

    int getY0() const {
        return y0;
    }

    void setY0(int y0) {
        Platform::y0 = y0;
    }

    int getX() const {
        return x;
    }

    void setX(int x) {
        Platform::x = x;
    }

    int getY() const {
        return y;
    }

    void setY(int y) {
        Platform::y = y;
    }

    char &getType()  {
        return type;
    }

    int getLength()  {
        return lengthh;
    }

    


};
