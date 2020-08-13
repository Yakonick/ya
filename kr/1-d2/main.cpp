#include <iostream>

using namespace std;

template <class T>
struct DNode
{
    T d;
    DNode<T> *p, *n;

    DNode<T> *findXY(T x, T y)
    {
        DNode<T> *flag1 = n, *flag_y = nullptr;
        if (flag1->n == nullptr or flag1 == nullptr)
            return nullptr;

        while (flag1 != nullptr)
        {
            if (flag1->d == y)
            {
                flag_y = flag1;
                break;
            }
            flag1 = flag1->n;
        }

        if (flag_y == nullptr) return nullptr;

        while (flag_y->p != nullptr)
        {
            flag_y = flag_y->p;
            if (flag_y->d == x) return flag_y;
        }
        return nullptr;
    }
};