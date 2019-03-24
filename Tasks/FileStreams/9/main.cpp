#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void Load(int A[15], string NameOfFile)
{
    ifstream File(NameOfFile, ios::binary | ios::in);
    int Num, i = 0;
    while (File >> Num)
    {
        A[i] = Num; ++i;
    }
    File.close();
}

void Save(int A[15], string NameOfFile)
{
    ofstream File(NameOfFile, ios::binary | ios::out | ios::app);
    for (int i = 0; i < 15; i++)
        File << " " << A[i];
    File.close();
}

int main()
{
    int A[15];
    string NameOfFile1, NameOfFile2;
    cin >> NameOfFile1 >> NameOfFile2;
    Load(A, NameOfFile1);
    Save(A, NameOfFile2);
    return 0;
}