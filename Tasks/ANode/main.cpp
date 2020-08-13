#include <iostream>

using namespace std;

template<class T>
struct ANode
{
    T data;
    ANode<T> *down, *right;
    ANode(T dd, ANode<T> *d = nullptr, ANode<T> *r = nullptr):
        data(dd), down(d), right(r) {}
};


template<class T>
void print(ANode<T> *r, int offset = 0)
{
    if(r==nullptr) return;
    for(int i = 0; i < offset; i++)
        cout << " ";
    cout<< r->data <<endl;
    print(r->down,  offset + 3);
    print(r->right, offset);
}


//                                      task 1 (success)
template <class T>
int count_gson(ANode<T> *f)
{
    int count = 0;
    if (f == nullptr or f->down == nullptr) return count;
    f = f->down;
    ANode<T> *son_f = f;
    while (son_f != nullptr)
    {
        f = son_f->down;
        while (f != nullptr)
        {
            ++count;
            f = f->right;
        }
        son_f = son_f->right;
    }
    return count;
}


//                                      task 3 (success)  2-nd task too easy make from 3-d
template <class T>
ANode<T> *function2(ANode<T> *f, T d1, T d2)
{
    if (f == nullptr or f->down == nullptr) return nullptr;
    ANode<T> *son = f->down;
    while (son != nullptr)
    {
        if (son->data == d1)
        {
            ANode<T> *g_son = son->down;
            while (g_son != nullptr)
            {
                if (g_son->data == d2)
                    return son;
                else
                    g_son = g_son->right;
            }
        }
        else
            son = son->right;
    }
    return nullptr;
}


//                                      task 4 ()
template <class T>
ANode<T> *down_number(ANode<T> *f, int *mass)
{
    if (f == nullptr) return nullptr;
    int i = 0;
    while (f->down != nullptr)
    {
        f = f->down;
        for (int j = 0; j < mass[i]; j++)
        {
            f = f->right;
        }
        ++i;
    }
}


//                                      task 6 (success)
template <class T>
void add_son(ANode<T> *&f, T d)
{
    f->down = new ANode<T>(d, nullptr, f->down);
}


//                                      task 7 (success)
template <class T>
void add_root(ANode<T> *&f, T d)
{
    ANode<T> *tmp = new ANode<T>(d, f, nullptr);
    f = tmp;
}


//                                      task 8 (success)
template <class T>
void delete_son(ANode<T> *&f)
{
    ANode<T> *del_son = f->down;
    f->down = f->down->down;
    ANode<T> *tmp = f->down;
    while (tmp->right != nullptr)
        tmp = tmp->right;
    tmp->right = del_son->right;
    delete del_son;
}


//                                      task 9 (success)
template <class T>
void del_all_sons(ANode<T> *&f)
{
    ANode<T> *tmp1 = f->down, *tmp2 = tmp1;
    f->down = f->down->down;
    ANode<T> *tmp_gson = tmp1->down;
    while (tmp2->right != nullptr)
    {
        tmp2 = tmp1->right;
        while (tmp_gson->right != nullptr)
            tmp_gson = tmp_gson->right;
        tmp_gson->right = tmp2->down;
        delete tmp1;
        tmp1 = tmp2;
    }
}


int main()
{
    ANode<int> *tree =  new ANode<int>(1,
                                       new ANode<int>(2,
                                                      new ANode<int>(5, nullptr,
                                                      new ANode<int>(6, nullptr,
                                                      new ANode<int>(7))),
                                       new ANode<int>(3,
                                                      new ANode<int>(8),
                                       new ANode<int>(4,
                                                      new ANode<int>(9, nullptr,
                                                      new ANode<int>(10))))));
    cout << endl;
    print(tree);
    cout << "_________________________" << endl << endl;

    del_all_sons(tree);
    print(tree);
}