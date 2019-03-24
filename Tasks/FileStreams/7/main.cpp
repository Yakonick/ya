#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void TransferSum(string NameOfFile1, string NameOfFile2)
{
    ifstream GetFile(NameOfFile1);
    ofstream GiveFile(NameOfFile2);
    char Symb;
    int Num, SumOfLine = 0;

    while (GetFile >> Num)
    {
        SumOfLine += Num;
        Symb = GetFile.get();
        if (Symb == 10)
        {
            GiveFile << SumOfLine << " ";
            SumOfLine = 0;
        }
    }

    GiveFile << SumOfLine << " ";
}

int main()
{
    int a[10];
    string NameOfFile1, NameOfFile2;
    cin >> NameOfFile1 >> NameOfFile2;
    TransferSum(NameOfFile1, NameOfFile2);
    cout << a[1];

    return 0;
}