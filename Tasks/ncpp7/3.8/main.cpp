#include <iostream>
#include <list>
#include <iterator>

using namespace std;

template<class T>
T Am(list<T> List, T n)
{
    T Amount = 0;
    for (auto x: List)
    {
        if (x == n)
            ++Amount;
    }
    return Amount;
}

int main()
{
    istream_iterator<int> b(cin), e;
    list<int> List(b, e);
    cout << Am(List, 5) << endl;
    return 0;
}