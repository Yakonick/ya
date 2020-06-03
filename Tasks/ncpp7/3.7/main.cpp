#include <iostream>
#include <list>
#include <iterator>

using namespace std;

double Print(list<int> List)
{
    double Sum = 0;
    int Num = 0, Amount = 0;
    for (int x: List)
    {
        ++Num;
        if (x == 5)
        {
            Sum += Num;
            ++Amount;
        }
    }
    return Sum/Amount;
}

int main()
{
    istream_iterator<int> b(cin), e;
    list<int> List(b, e);
    cout << Print(List) << endl;
    return 0;
}