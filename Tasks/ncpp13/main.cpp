#include <iostream>

using namespace std;


//                                       0 (success)

int digit(int x, unsigned int n)
{
    return (x >> n) & 1;
}

unsigned int num_of_digits(int x)
{
    unsigned int i = 0;
    while (x != 0) {
        x = x >> 1;
        ++i;
    }
    return i;
}


//                                       1 (success)

template<class T>
class DSNode
{
public:
    unsigned int key;
    T data;
    DSNode<T> *s0, *s1;
    DSNode(T dd, DSNode<T> *l = nullptr, DSNode<T> *r = nullptr, unsigned int k = 0):
            data(dd), s0(l), s1(r), key(k) {}
};


//                                       2 (success)

template<class T>
class DSTree
{
public:
    DSNode<T> *root;
    DSTree(DSNode<T> *r = nullptr): root(r) {}
    ~DSTree() { delete root; }

    void print() { print1(root); };
    DSNode<T>* search(int k) { return search_1(k, root, num_of_digits(k) - 1);};
    void insert(int k, T data) { if (search(k) == nullptr) insert_1(k, data, root); };
    void del(int k) { del_1(k, root); };
};


//                                       3 (success)

template<class T>
void print1(DSNode<T> *r, int offset = 0)
{
    if(r == nullptr) return;
    print1(r->s1, offset + 3);
    for(int i = 0; i < offset; i++)
        cout << " ";
    cout << "(" << r->data << ", key: " << r->key << ")" <<endl;
    print1(r->s0, offset + 3);
}


//                                       4 (success)

template<class T>
DSNode<T>* search_1(int k, DSNode<T>* p, unsigned int i)
{
    if (p == nullptr) return nullptr;
    if (k == p->key) return p;
    if (digit(k, i - 1)) return search_1(k, p->s1, i - 1);
    else return search_1(k, p->s0, i - 1);
}


//                                       5 (success)

template<class T>
void insert_1(int k, T data, DSNode<T>*& p, int i = 0)
{
    if (p->key == k) return;
    if (digit(k, i) == 0)
        if (p->s0 != nullptr) insert_1(k, data, p->s0, i + 1);
        else p->s0 = new DSNode<T>(data, nullptr, nullptr, k);
    else
        if (p->s1 != nullptr) insert_1(k, data, p->s1, i + 1);
        else p->s1 = new DSNode<T>(data, nullptr, nullptr, k);
}


//                                       6 (success)

template<class T>
DSNode<T> *leftest_leaf(DSNode<T> *f)
{
    while (f->s0 != nullptr or f->s1 != nullptr) {
        if (f->s0 != nullptr)
            f = f->s0;
        else
            f = f->s1;
    }
    return f;
}

template<class T>
void del_1(int k, DSNode<T> *p)
{
    int const_1 = k >> 1;
    DSNode<T> *delete_node = search_1(k, p, num_of_digits(k) - 1);
    if (search_1(k, p, num_of_digits(k) - 1) == nullptr) return;
    if (p->key == k && p->s0 == nullptr && p->s1 == nullptr) {
        DSNode<T> *tmp = p;
        p = nullptr;
        delete tmp;
    } else if (delete_node->s0 != nullptr || delete_node->s1 != nullptr) {
        DSNode<T> *leaf = leftest_leaf(delete_node);
        int const_2 = (leaf->key) >> 1;
        DSNode<T> *tmp_1 = search_1(const_2, p, num_of_digits(const_2) - 1);
        if (tmp_1->s1 == leaf)
            tmp_1->s1 = nullptr;
        else
            tmp_1->s0 = nullptr;
        delete_node->data = leaf->data;
        delete_node->key = leaf->key;
        delete leaf;
    } else {
        DSNode<T> *new_leaf = search_1(const_1, p, num_of_digits(const_1) - 1);
        if (new_leaf->s1 == delete_node)
            new_leaf->s1 = nullptr;
        else
            new_leaf->s0 = nullptr;
        delete delete_node;
    }
}


//                                       7


int main()
{
    DSTree<int> tree1(new DSNode<int>(1111,
                                       new DSNode<int>(2222,
                                                      new DSNode<int>(4444, nullptr, nullptr, 4),
                                                      new DSNode<int>(5555, nullptr, nullptr, 5), 2),
                                       new DSNode<int>(3333,
                                                      new DSNode<int>(6666, nullptr, nullptr ,6), nullptr, 3), 1));
    tree1.print();
    cout << endl << "_____________________" << endl << endl;
    tree1.insert(7, 7777);
    tree1.del(8);
    tree1.print();
}