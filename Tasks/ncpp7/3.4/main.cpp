#include <iostream>
#include <list>
#include <iterator>
#include <fstream>

using namespace std;

int main()
{
    fstream File_In("FileIn.txt");
    ofstream File_Odd("FileOdd.txt");
    ofstream File_Even("FileEven.txt");

    istream_iterator<int> b(File_In), e;
    list<int> List(b, e);

    for (int x: List)
    {
        if (x % 2 == 0)
            File_Even << x << " ";
        else
            File_Odd << x << " ";
    }

    return 0;
}