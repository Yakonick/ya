#include <iostream>
#include <set>

using namespace std;

template<class T>
set<T> f(set<T> a, set<T> b)
{
    set<int>::iterator i;
    for (i = b.begin(); i != b.end(); i++)
        a.insert(*i);
    return a;
}

int main()
{
    set<int> a, b;
    int i = 1;
    while (i != 0)
    {
        cin >> i;
        a.insert(i);
    }
    i = 1;
    while (i != 0)
    {
        cin >> i;
        b.insert(i);
    }
    a = f(a, b);
    set<int>::iterator j;

    for (j = a.begin(); j != a.end(); j++)
        cout << *j << " ";
}