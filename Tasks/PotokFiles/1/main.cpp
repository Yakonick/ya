#include "fstream"
#include "cmath"
#include "string"

using namespace std;

int main()
{
    double x = 0;
    ofstream F("f.txt");
    F << "x     sin(x)" << endl;
    for (int i = 0; i < 11; i++)
    {
        F << x << "     " << sin(x) << endl;
        x += 0.1;
    }
    return 0;
}