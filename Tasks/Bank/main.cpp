#include <iostream>
#include <list>
#include <iterator>

using namespace std;


int main()
{
    istream_iterator<int> b(cin), e;
    list<int> List(b, e);
    list<int>::iterator i;

    for (i = List.begin(); i != List.end(); ++i) {
        cout << *i << " ";
    }
    cout << endl;
    return 0;

}