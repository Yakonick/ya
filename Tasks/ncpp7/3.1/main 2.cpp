#include <iostream>
#include <fstream>
#include <list>
#include <string>
#include <iterator>

using namespace std;

template<class T>

void print(T List)
{
    string NameOfFile;
    cin.clear();
    cin >> NameOfFile;

    ofstream File(NameOfFile);

    for (auto x: List)
    {
        File << x*x << "   ";
    }
}

int main()
{
    istream_iterator<int> b(cin),e;
    list<int> List(b, e);
    print(List);

    return 0;
}