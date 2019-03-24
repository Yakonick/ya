#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    fstream File("f.dat", ios::binary | ios::in | ios::out);
    int Num, A[10], i = 0;
    while (File >> Num)
    {
        if (Num == 0)
            A[i] = 5;
        else
            A[i] = Num;
        ++i;
    }
    File.close();
    File.open("f.dat", ios::binary | ios::out);
    for (int j = 0; j < 10; j++)
    {
        File << A[j] << " ";
        cout << A[j] << " ";
    }
    cout << endl;

    return 0;
}