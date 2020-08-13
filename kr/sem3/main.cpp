#include <iostream>
#include <stack>

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


template<class T>
BNode<T> *search2(BNode<T> *p, T d1, T d2)
{
    if (p == nullptr) return p;
    stack<BNode<T>*> S;
    BNode<T> *t;
    S.push(p);
    while(!S.empty())
    {
        t = S.top();
        S.pop();
        if (t->left != nullptr and t->data == d1 and t->left->data == d2) return t;
        if(t->left!=nullptr) S.push(t->left);
        if(t->right!=nullptr) S.push(t->right);
    }
    return nullptr;
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

    BNode<int> *p = search2(tree, 5, 7);
    cout << p->data << endl;
}