#include <iostream>

using namespace std;

class Foo
        {
    static int quantity;
    int number = 0;
public:
    Foo(): number(quantity++){cout << "Создаётся объект №" << number << endl;}
    ~Foo() {cout << "Удаляется объект №" << number << endl;}
        };
int Foo::quantity = 0;

Foo a, b[3];

int main()
{
    Foo c;
    static Foo d;
    static Foo e[2];
    return EXIT_SUCCESS;
}