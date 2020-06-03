#include <iostream>

using namespace std;

class OffTheField {};
class IllegalCommand {};

class Robot
{
    int x;
    int y;
    Robot(int xx, int yy): x(xx), y(yy) {}

    void get_right()
    {
        if (x + 1 > 10) throw OffTheField();
        ++x;
    }

    void get_left()
    {
        if (x - 1 < 1) throw OffTheField();
        --x;
    }

    void get_up()
    {
        if (y + 1 > 10) throw OffTheField();
        ++y;
    }

    void get_down()
    {
        if (y - 1 < 1) throw OffTheField();
        --y;
    }
};