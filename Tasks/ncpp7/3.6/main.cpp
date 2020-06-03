#include <iostream>
#include <list>
#include <iterator>

using namespace std;

double Print(list<double> List)
{
    double Sum = 0;
    for (double x: List)
        Sum += x;
    return Sum/List.size();
}

int main()
{
    istream_iterator<double> b(cin), e;
    list<double> List(b, e);
    cout << Print(List) << endl;
    return 0;
}