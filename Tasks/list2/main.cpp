#include <iostream>

using namespace std;

template <class T>
struct Node
{
    T d;
    Node<T> *n;
    Node(T dd, Node<T> *nn = nullptr): d(dd), n(nn) {}
};


//                              1 задача

template <class T>
void add_first(Node<T> *&first, int value)
{
    first = new Node<T>(value, first);
}


//                              2 задача ?наличие эл-ов?

template <class T>
void add_last(Node<T> *first, int value)
{
    while(first->n != nullptr)
    {
        first = first->n;
    }
    first->n = new Node<T>(value, nullptr);
}


//                              3 задача ?а если рассмотреть случаи, когда в начало надо вставить эл-т?

template <class T>
void add_unknwn(Node<T> *&first, int num_place, int value)
{
    int temp = 0;
    Node<T> *prep;
    while(true)
    {
        if (temp == num_place)
            break;
        prep = first;
        first = first->n;
        ++temp;
    }
    Node<T> *p;
    p = new Node<T>(value, first);
    prep->n = p;
}


//                              4 задача

