#include <iostream>

using namespace std;

int main()
{
    int base[20];
    for (int i = 0; i < 20; i++)
        cin >> base[i];
    int temp[10] {0};


    for (int i = 0; i < 20; i++)
    {
        temp[base[i]]++;
    }


    int k = 0;
    for (int i = 0; i < 10; i++)
    {
        for (int j = k; j < temp[i] + k; j++)
        {
            base[j] = i;
        }
        k = temp[i] + k;
    }
    for (int i = 0; i < 20; i++)
        cout << base[i] << " ";
    cout << endl;

    return 0;
}