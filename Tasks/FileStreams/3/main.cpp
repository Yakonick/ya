#include <fstream>
#include <string>
#include <iostream>

using namespace std;

int main()
{
    string name1, name2;
    cin >> name1 >> name2;

    ifstream G(name1);
    ofstream F(name2);
    F << G.rdbuf();
    return 0;
}