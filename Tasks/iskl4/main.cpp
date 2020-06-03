#include <iostream>

using namespace std;

class Ex
{
    double x;
public:
    Ex(double xx): x(xx) {}
};

class Bar
{
    double y;
    Bar(): y(0) {}

    void set(double a)
    {
        if (y + a > 100) throw Ex(y);
        y = a;
    }
};





int main() {
    return 0;
}