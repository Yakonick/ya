#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T d;
    Node<T> *n;
    Node(T dd, Node<T> *nn = nullptr): d(dd), n(nn) {}
};


//                                  1 task

template <class T>
void del_first(Node<T> *&f)
{
    Node<T> *p;
    if (f == nullptr) return;
    p = f;
    f = f->n;
    delete p;
}


//                                  2 task

template <class T>
void del_last(Node<T> *f)
{
    Node<T> *p;
    if (f == nullptr) return;
    while(f != nullptr)
    {
        p = f;
        f = f->n;
    }
    p->n = nullptr;
    delete f;
}


//                                  3 task

template <class T>
void del_num(Node<T> *f, int num)
{
    int tmp = 0;
    Node<T> *p;
    if (f == nullptr) return;
    if (num == 0) del_first(f);
    while(tmp != num)
    {
        p = f;
        f = f->n;
        ++tmp;
    }
    p->n = f->n;
    delete f;
}


//                                  4 task

template <class T>
void del_all(Node<T> *f)
{
    Node<T> *p;
    if (f == nullptr) return;
    while (f != nullptr)
    {
        p = f;
        f = f->n;
        delete p;
    }
    delete p;
}