#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void GetStat(string NameOfFile)
{
    char Symb;
    int Stat[257] {0};
    ifstream File(NameOfFile);

    while (File >> Symb)
        Stat[(unsigned char)Symb]++;

    for (int i = 0; i < 257; i++)
        cout << i << ".     " << Stat[i] << endl;
}


int main()
{
    string NameOfFile;
    cin >> NameOfFile;
    GetStat(NameOfFile);

    return 0;
}