#include <iostream>
#include <list>
#include <iterator>

using namespace std;

int main()
{
    istream_iterator<int> b(cin), e;
    list<int> List(b, e);
    list<int>::iterator i;

    for (i = List.begin(); i != List.end(); i++)
    {
        if (*i == 1)
        {
            for (; i != List.end(); i++)
                cout << *i << " ";
            break;
        }
    }
    return 0;
}