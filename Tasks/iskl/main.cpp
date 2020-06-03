#include <iostream>

using namespace std;

class OutOfMemory {};
class OutOfRange {};

class Vector
{
    int size;
    double *p;
public:
    Vector(int n)try: size(n), p(new double[n]) {} catch (bad_alloc) { throw OutOfMemory(); }
    double &operator[](int num)
    {
        if (num < 0 or num > size) throw OutOfRange();
        return p[num];
    };
    ~Vector(){delete [] p;}
};


int main()
{
    int size, n;
    cin >> size >> n;
    Vector temp(size);
    try { temp[n]; }
    catch(OutOfRange)
    {
        cerr << "Out of range" << endl;
        return EXIT_FAILURE;
    }
}