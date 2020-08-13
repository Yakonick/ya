#include <iostream>

using namespace std;


//                                      1 (success)

template <class T, class P>
class DNode
{
public:
    unsigned int key;
    T data;
    DNode<T, P> *left, *right;
    DNode(T dd, P k, DNode<T, P> *l = nullptr, DNode<T, P> *r = nullptr):
            data(dd), key(k), left(l), right(r) {}
};


template <class T, class P>
class DTree
{
public:
    DNode<T, P> *root;
    DTree(DNode<T, P> *r = nullptr): root(r) {}
    ~DTree() { delete root; }

    void print() { print_1(root); };
    DNode<T, P> *search(P k) { return search_1(root, k); };
    P searchMaxKey() { return searchMax_1(root); };
    P search2Key() { return search2Key_1(root); };
    void insert(P k, T d) { insert_1(root, k, d); };
};


template <class T, class P>
void print_1(DNode<T, P> *r, int offset = 0)
{
    if(r == nullptr) return;
    print_1(r->right, offset + 3);
    for(int i = 0; i < offset; i++)
        cout << " ";
    cout << "(" << r->data << ", key: " << r->key << ")" <<endl;
    print_1(r->left, offset + 3);
}


//                                      2 (success)

template <class T, class P>
DNode<T, P> *search_1(DNode<T, P> *r, P k)
{
    if (r == nullptr) return nullptr;
    if (r->key == k)
        return r;
    else if (r->key < k)
        return search_1(r->right, k);
    else
        return search_1(r->left, k);
}


//                                      3 (success)

template <class T, class P>
P searchMax_1(DNode<T, P> *r)
{
    if (r == nullptr) EXIT_FAILURE;
    while (r->right != nullptr)
        r = r->right;
    return r->key;
}


//                                      4 (success)

template <class T, class P>
P search2Key_1(DNode<T, P> *f)
{
    if (f == nullptr || (f->left == nullptr && f->right == nullptr)) EXIT_FAILURE;
    if (f->left == nullptr)
        return f->right->key;
    else if (f->left->left == nullptr && f->left->right == nullptr)
        return f->key;
    else
        return search2Key_1(f->left);
}


//                                      5 (success)

template <class T, class P>
void insert_1(DNode<T, P> *&r, P k, T d)
{
    if (r == nullptr)
        r = new DNode<T, P>(d, k);
    else if (k > r->key)
        insert_1(r->right, k, d);
    else
        insert_1(r->left, k, d);
}


//
//
// another tasks are not so hard so they have done in my mind
//
//


int main()
{
    DTree<int, int> tree1(new DNode<int, int>(1111, 4,
                                      new DNode<int, int>(2222, 2,
                                                      new DNode<int, int>(4444, 1),
                                                      new DNode<int, int>(5555, 3)),
                                      new DNode<int, int>(3333, 6,
                                                      new DNode<int, int>(6666, 5))));
    tree1.print();
    cout << "______________________" << endl << endl;
    tree1.insert(8, 8888);
    tree1.insert(7, 7777);
    tree1.print();

    return 0;
}