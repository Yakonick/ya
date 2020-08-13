#include <iostream>

using namespace std;

template <class T>
struct DNode
{
    T d;
    DNode<T> *p, *n;

    DNode<T> *findXY(T x, T y)
    {
        DNode<T> *flag1 = n, *flag_y = n;
        if (flag1->n == nullptr)
            return nullptr;

        while(flag1 != nullptr)
        {
            if (flag1->d == y)
                flag_y = flag1;
            flag1 = flag1->n;
        }

        while(flag_y->d != x)
        {
            flag_y = flag_y->n;
            if (flag_y == nullptr)
                return nullptr;
        }
        return flag_y;
    }
};


