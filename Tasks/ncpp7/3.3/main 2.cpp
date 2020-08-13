#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    istream_iterator<int> b(cin), e;
    list<int> List(b, e);

    for (int x: List)
    {
        if (x % 2 == 0)
            cout << x/2 << " ";
        else
            cout << x << " ";
    }
    return 0;
}