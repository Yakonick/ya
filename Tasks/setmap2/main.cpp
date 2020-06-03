#include <iostream>
#include <map>

using namespace std;

int main()
{
    map<int, int> num;
    int temp = 1;
    while (temp != 0)
    {
        cin >> temp;
        num[temp]++;
    }

    map<int, int>::iterator i;
    for(i = num.begin(); i != num.end(); i++)
    {
        if (i->second > 1)
            cout<<i->first<<" ";
    }
}