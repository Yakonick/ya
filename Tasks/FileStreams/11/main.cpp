#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

void ChangeNumbers(string NameOfFile)
{
    fstream File(NameOfFile, ios::binary | ios::in);
    vector<int> A; int Num, Temp; vector<int>::iterator i, j;
    while (File >> Num)
        A.push_back(Num);

    for (j = A.end(); j != A.begin(); j--)
    {
        for (i = A.begin(); i != (j+1); i++)
            Temp += *i;
        *j = Temp; Temp = 0;
    }
    File.close();
    File.open(NameOfFile, ios::binary | ios::out);
    for (i = A.begin(); i != A.end(); i++)
        File << *i << " ";
    File.close();
}

int main()
{
    string NameOfFile;
    cin >> NameOfFile;
    ChangeNumbers(NameOfFile);
    return 0;
}