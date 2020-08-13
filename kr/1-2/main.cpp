#include <iostream>

using namespace std;

class CheckFailed {};

template <class T>
struct SList
{
    T d;
    SList<T> *n;
    SList(T dd, SList<T> *nn = nullptr): d(dd), n(nn) {}

    void remove_3_if(bool (*function)(T))
    {
        SList<T> *first = n, *first_bool = n;
        int count = 0;
        if (first == nullptr) return;
        while (first_bool != nullptr)
        {
            try {function(first_bool->d);}
            catch(CheckFailed) { return; }
            first_bool = first_bool->n;
        }

        first_bool = first;
        if (function(first_bool->d) == 1)
        {
            del_first(first_bool);
        }

        while (first_bool != nullptr)
        {
            if (function(first_bool->n->d) == 1)
            {
                SList<T> *tmp = first_bool->n;
                first_bool->n = first_bool->n->n;
                delete tmp;
                ++count;
            }
            if (count == 3) return;
            first_bool = first_bool->n;
        }
    }
};


template <class T>
void del_first(SList<T> *&f)
{
    SList<T> *p;
    if (f == nullptr) return;
    p = f;
    f = f->n;
    delete p;
}
