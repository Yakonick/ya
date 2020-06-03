#include <iostream>
#include <list>
#include <sstream>
#include <string>
#include <iterator>

using namespace std;

int main()
{
    istream_iterator<int> b(cin), e;
    list<int> List(b,e);
    char Char; int Answer = 0;

    stringstream Temp;

    for (int x: List)
        Temp << x;

    while (Temp >> Char)
    {
        if (Char == '1')
            ++Answer;
    }

    cout << Answer << endl;
    return 0;
}