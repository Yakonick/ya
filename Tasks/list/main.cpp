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
int length(Node<T> *first)
{
    int len = 0;
    while(first != nullptr)
    {
        ++len;
        first = first->n;
    }
    return len;
}


//                              2 задача ?не обязательно есть эл-ты?

template <class T>
Node<T> *second(Node<T> *first)
{
    first = first->n;
    return first;
}


//                              3 задача ?не обязательно есть эл-ты?

template <class T>
Node<T> *last(Node<T> *first)
{
    while(first->n != nullptr)
    {
        first = first->n;
    }
    return first;
}


//                              4 задача

template <class T>
Node<T> *setplace(Node<T> *first, int numplace)
{
    int temp = 0;
    while(true)
    {
        if (temp == numplace)
            break;
        first = first->n;
        ++temp;
    }
    return first;
}


//                              5 задача

template <class T>
void all_list(Node<T> *first)
{
    while(first != nullptr)
    {
        cout << first->d << " ";
        first = first->n;
    }
}


//                              6 задача

template <class T>
int countif(Node<T> *first, bool (*boolf)(T))
{
    int count = 0;
    while(first != nullptr)
    {
        if(boolf(first->d))
            ++count;
        first = first->n;
    }
    return count;
}


//надобность 7 задачи под вопросом