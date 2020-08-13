#include <iostream>

using namespace std;

template<class T>
struct DList
{
    T data;
    DList<T> *previous, *next;
    DList(T dd, DList<T> *pp, DList<T> *nn): data(dd), previous(pp), next(nn) {}


    void insert_ptr1(DList<T> *&p, T d)
    {
        DList<T> *tmp = new DList<T>(d, p->previous, p);
        DList<T> *pre = p->previous;
        pre->next = tmp;
        p->previous = tmp;
    }
};