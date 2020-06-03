#include <iostream>

using namespace std;

class Error {};

class Foo
{
    static int quantity;
    int number = 0;
public:
    Foo(): number(quantity++){cout << "Создаётся объект №" << number << endl;}
    ~Foo() {cout << "Удаляется объект №" << number << endl;}
};
int Foo::quantity = 0;

int main()
{
    try {  Foo mass[5]; Foo *p = new Foo[5]; throw Error();}
    catch(Error)
    {
        cerr << "Error" << endl;
    }
    Foo mass[5];
    Foo *p = new Foo[5];
    return EXIT_SUCCESS;
}