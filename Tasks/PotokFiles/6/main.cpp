#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int SumInFile(string NameOfFile)
{
    ifstream File(NameOfFile);
    int Num, Sum;

    while (File >> Num)
        Sum += Num;

    return Sum;
}

int main()
{
    cout << SumInFile("File.txt") << endl;
    return 0;
}