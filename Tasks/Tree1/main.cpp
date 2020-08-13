#include <iostream>

using namespace std;

template<class T>
struct BNode
{
    T data;
    BNode<T> *left, *right;
    BNode(T dd, BNode<T> *l = nullptr, BNode<T> *r = nullptr):
            data(dd), left(l), right(r) {}
};


template<class T>
void print(BNode<T> *r, int offset = 0)
{
    if(r==nullptr) return;
    print(r->right, offset+3);
    for(int i = 0; i<offset; i++)
        cout << " ";
    cout << r->data << endl;
    print(r->left, offset+3);
}


//                                      task 1  (success)
template <class T>
BNode<T> *right_gson(BNode<T> *f)
{
    if (f == nullptr) return nullptr;
    if (f->right != nullptr)
    {
        if (f->right->right != nullptr)
            return f->right->right;
        if (f->right->left != nullptr)
            return f->right->left;
    }
    if (f->left != nullptr)
    {
        if (f->left->right != nullptr)
            return f->left->right;
        if (f->left->left != nullptr)
            return f->left->left;
    }
    return nullptr;
}


//                                      task 2  (success)
template <class T>
int count_gson(BNode<T> *f)
{
    int c = 0;
    if (f == nullptr) return c;
    if (f->right != nullptr)
    {
        if (f->right->right != nullptr)
            c++;
        if (f->right->left != nullptr)
            c++;
    }
    if (f->left != nullptr)
    {
        if (f->left->right != nullptr)
            c++;
        if (f->left->left != nullptr)
            c++;
    }
    return c;
}


//                                      task 3  (success)
template <class T>
void del_root(BNode<T> *&f)
{
    BNode<T> *tmp = f;
    f = f->left;
    delete tmp;
}


//                                      task 4 (success)
template <class T>
void add_root(BNode<T> *&f, T d)
{
    BNode<T> *new_f = new BNode<T>(d, nullptr, f);
    f = new_f;
}


//                                      task 5  (success)
template <class T>
void add_lson(BNode<T> *&f, T d)
{
    BNode<T> *new_lson = new BNode<T>(d, f->left, nullptr);
    f->left = new_lson;
}


//                                      task 6  (success)
template <class T>
void add_son(BNode<T> *&f, T d)
{
    BNode<T> *new_son = new BNode<T>(d, f->left, f->right);
    f->right = nullptr;
    f->left = new_son;
}


//                                      task 7  (success)
template <class T>
void change_lson_root(BNode<T> *&f)
{
    BNode<T> *lson = f->left, *rson = f->right, *tmp = f;
    tmp->right = f->left->right;
    tmp->left = f->left->left;
    lson->left = tmp;
    lson->right = rson;
    f = lson;
}


//                                      task 8  (success)
template <class T>
void turn_left(BNode<T> *&f)
{
    BNode<T> *root = f, *r = f->right, *rl = f->right->left;
    r->left = root;
    root->right = rl;
    f = r;
}


//                                      task 9  (success)
template <class T>
BNode<T> *leftest_node(BNode<T> *f)
{
    while(f->left != nullptr)
        f = f->left;
    return f;
}


//                                      task 10 (success)
template <class T>
BNode<T> *right_left(BNode<T> *f)
{
    while (f->left != nullptr or f->right != nullptr)
    {
        if (f->right != nullptr)
            f = f->right;
        else
            break;
        if (f->left != nullptr)
            f = f->left;
        else
            break;
    }
    return f;
}


//                                      task 11 (success)
template <class T>
BNode<T> *leftest_leaf(BNode<T> *f)
{
    while (f->left != nullptr or f->right != nullptr)
    {
        if (f->left != nullptr)
            f = f->left;
        else
            f = f->right;
    }
    return f;
}


//                                      task 12 (success)
template <class T>
BNode<T> *after_leftest_leaf(BNode<T> *f)
{
    BNode<T> *tmp;
    while (f->left != nullptr or f->right != nullptr)
    {
        if (f->right != nullptr and f->left != nullptr)
            tmp = f->right;
        if (f->left != nullptr)
            f = f->left;
        else
            f = f->right;
    }
    f = leftest_leaf(tmp);
    return f;
}


//                                      task 13 (success)
template <class T>
void add_lson_at_leftest_leaf(BNode<T> *f, T d)
{
    f = leftest_leaf(f);
    BNode<T> *lson = new BNode<T>(d);
    f->left = lson;
}


//                                      task 14 (success)
template <class T>
void delete_leftest_node(BNode<T> *f)
{
    while(f->left->left != nullptr)
        f = f->left;
    BNode<T> *p = f->left;
    f->left = f->left->right;
    delete p;
}


//                                      task 15 (success)
template <class T>
void delete_leftest_leaf(BNode<T> *f)
{
    BNode<T> *p = f;
    while (f->left != nullptr or f->right != nullptr)
    {
        if (f->left != nullptr)
            f = f->left;
        else
            f = f->right;
    }
    while (p->left != f and p->right != f)
    {
        if (p->left != nullptr)
            p = p->left;
        else
            p = p->right;
    }
    if (p->left == f)
        p->left = nullptr;
    else
        p->right = nullptr;
    delete f;
}


int main()
{
    BNode<int> *tree8 = new BNode<int>(1,
                                       new BNode<int>(2,
                                                      new BNode<int>(4, nullptr,
                                                                     new BNode<int>(9)),
                                                      new BNode<int>(5)),
                                       new BNode<int>(3,
                                                      new BNode<int>(6),
                                                      new BNode<int>(7)));

    print(tree8);
    cout << "____________________________" << endl << endl;

    delete_leftest_leaf(tree8);
    print(tree8);
}