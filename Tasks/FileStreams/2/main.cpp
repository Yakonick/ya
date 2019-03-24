#include "fstream"
#include "iostream"

using namespace std;

int main()
{
    ifstream G("g.txt");
    string a; int b; int c;
    G >> a >> a >> a;
    while (G >> a >> b >> c)
        cout << a << " " << b + c << endl;
    return 0;
}