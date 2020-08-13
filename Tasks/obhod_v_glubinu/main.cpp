#include <iostream>
#include <stack>
#include <queue>

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
    for(int i = 0; i < offset; i++)
        cout << " ";
    cout << r->data << endl;
    print(r->left, offset+3);
}


//                                      task 1 (success)
template <class T>
int total(BNode<T> *p)
{
    int c = 0;
    stack<BNode<T>*> S;
    BNode<T> *t;
    if(p == nullptr) return 0;
    S.push(p);
    while(!S.empty())
    {
        t = S.top();
        c += t->data;
        S.pop();
        if(t->left!=nullptr) S.push(t->left);
        if(t->right!=nullptr) S.push(t->right);
    }
    return c;
}


//                                      task 2 (success)
template <class T>
int height(BNode<T> *p, int i = 0)
{
    if (p == nullptr) return i;
    if (height(p->left, i + 1) > height(p->right, i + 1)) return height(p->left, i + 1);
    else return height(p->right, i + 1);
}


//                                      task 3 (success)
template <class T>
T min(BNode<T> *p)
{
    T c = 0;
    if (p == nullptr) return c;
    c = p->data;
    stack<BNode<T>*> S;
    BNode<T> *t;
    S.push(p);
    while(!S.empty())
    {
        t = S.top();
        cout << t->data << "\t" << c << endl;
        if (c > t->data) c = t->data;
        S.pop();
        if(t->left!=nullptr) S.push(t->left);
        if(t->right!=nullptr) S.push(t->right);
    }
    return c;
}


//                                      task 4 (success)
int eval(BNode<int>* p)
{
    if (p->left == nullptr && p->right == nullptr) return p->data;
    if (p->data == 1) return eval(p->left) + eval(p->right);
    if (p->data == 2) return eval(p->left) - eval(p->right);
    if (p->data == 3) return eval(p->left) * eval(p->right);
    if (p->data == 4) return eval(p->left) / eval(p->right);
}


//                                      task 5 (success)
template <class T>
BNode<T> *find(BNode<T> *p, T d)
{
    if (p == nullptr) return nullptr;
    if (p->data == d) return p;
    if (find(p->right) == nullptr) return find(p->left);
    else return find(p->right);
}


//                                      task 6 (success)
template <class T>
void delete_nodes(BNode<T> *&p)
{
    if (p == nullptr) return;
    delete_nodes(p->right);
    delete_nodes(p->left);
    delete p;
}


//                                      task 7 (success)
template <class T>
BNode<T> *copy(BNode<T> *p)
{
    BNode<T> *tmp = p;
    if (p == nullptr) return p;
    tmp->left = copy(p->left);
    tmp->right = copy(p->right);
    return tmp;
}


//                                      task 8 (success)
template <class T>
void reflect(BNode<T> *&p)
{
    if (p == nullptr) return;
    BNode<T> *tmp = p->left;
    p->left = p->right; p->right = tmp;
    reflect(p->right);
    reflect(p->left);
}


//                                      task 9 (success)
template <class T>
void del_leaves(BNode<T> *&p)
{
    if (p->left != nullptr)
        if (p->left->left == nullptr && p->left->right == nullptr)
        {
            BNode<T>* tmp = p->left;
            p->left = nullptr;
            delete tmp;
        }
        else del_leaves(p->left);
    if (p->right != nullptr)
        if (p->right->left == nullptr && p->right->right == nullptr)
        {
            BNode<T>* tmp = p->right;
            p->right = nullptr;
            delete tmp;
        }
        else del_leaves(p->right);
}


//                                      task 10 (success)
template <class T>
void del_leaves0(BNode<T> *&p)
{
    if (p->left != nullptr)
        if (p->left->left == nullptr && p->left->right == nullptr && p->left->data == 0)
        {
            BNode<T>* tmp = p->left;
            p->left = nullptr;
            delete tmp;
        }
        else del_leaves0(p->left);
    if (p->right != nullptr)
        if (p->right->left == nullptr && p->right->right == nullptr && p->right->data == 0)
        {
            BNode<T>* tmp = p->right;
            p->right = nullptr;
            delete tmp;
        }
        else del_leaves0(p->right);
}


//                                      task 11 (success)
template <class T>
void del0(BNode<T> *&p)
{
    if (p == nullptr) return;
    if (p->data == 0)
        delete_nodes(p);
    if (p->left != nullptr) {
        if (p->left->data == 0) {
            delete_nodes(p->left);
            p->left = nullptr;
        } else
            del0(p->left);
    }
    if (p->right != nullptr)
    {
        if (p->right->data == 0)
        {
            delete_nodes(p->right);
            p->right = nullptr;
        } else
            del0(p->right);
    }
}


//                                      task 12 (success)
template <class T>
void del1(BNode<T> *&p)
{
    if (p == nullptr) return;
    if (p->data == 0)
        delete_nodes(p);
    if (p->left != nullptr)
    {
        if (p->left->data == 1)
        {
            BNode<T> *tmp = p->left->right;
            delete_nodes(p->left->left);
            BNode<T> *tmp2 = p->left;
            p->left = tmp;
            delete tmp2;
        } else
            del0(p->left);
    }
    if (p->right != nullptr)
    {
        if (p->right->data == 1)
        {
            BNode<T> *tmp = p->right->right;
            delete_nodes(p->right->left);
            BNode<T> *tmp2 = p->right;
            p->right = tmp;
            delete tmp2;
        } else
            del0(p->right);
    }
}


//                                      task 13 (не понял)


//                                      task 14 (success)
template <class T>
BNode<T> *deepest_leaf(BNode<T> *p)
{
    queue<BNode<T>*> S;
    BNode<T> *t;
    if(p==nullptr) return nullptr;
    S.push(p);
    while(!S.empty())
    {
        t = S.front();
        S.pop();
        if(t->left!=nullptr) S.push(t->left);
        if(t->right!=nullptr) S.push(t->right);
    }
    return t;
}


//                                      task 15 (success)
template <class T>
T alt_sum(BNode<T> *p)
{
    queue<BNode<T>*> S;
    BNode<T> *t;
    T sum = 0;
    if(p==nullptr) return sum;
    S.push(p);
    while(!S.empty())
    {
        t = S.front();
        S.pop();
        if(t->left!=nullptr)
        {
            S.push(t->left);
            sum += t->left->data;
        }
        if(t->right!=nullptr)
        {
            S.push(t->right);
            sum -= t->right->data;
        }
    }
    return sum;
}


int main()
{
    BNode<int> *tree = new BNode<int>(2,
                                       new BNode<int>(1,
                                                      new BNode<int>(4),
                                                      new BNode<int>(5,
                                                                     new BNode<int>(7))),
                                       new BNode<int>(3,
                                                      new BNode<int>(6)));
    print(tree);
    cout << endl << "___________________" << endl << endl;

    cout << alt_sum(tree) << endl;
}