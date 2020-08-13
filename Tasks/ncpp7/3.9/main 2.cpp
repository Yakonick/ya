#include <iostream>
#include <list>
#include <iterator>

using namespace std;

template<class T>
T Sqr(T List)
{
    for (auto &x: List)
        x *= x;
    return List;
}

int main()
{
    istream_iterator<int> b(cin), e;
    list<int> List(b, e);
    List = Sqr(List);
    for (int x: List)
        cout << x << " ";
    cout << endl;
}