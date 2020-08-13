#include <iostream>

using namespace std;

class SmallList {};

template <class T>
struct SList
{
    T d;
    SList<T> *n;

    SList(T dd, SList<T> *nn = nullptr) : d(dd), n(nn) {}

    SList<T> *prelast()
    {
        SList<T> *f = n;
        if (f == nullptr or f->n == nullptr) throw SmallList();
        while (f->n->n != nullptr)
        {
            f = f->n;
        }
        return f;
    }
};