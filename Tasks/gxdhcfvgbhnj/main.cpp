#include <iostream>
#include <algorithm>

using namespace std;

struct AVLNode
{
    int key;
    bool data;
    int size;
    AVLNode* right;
    AVLNode* left;
    AVLNode* father;
    AVLNode(int k, bool d, int s, AVLNode* f = nullptr, AVLNode* r = nullptr, AVLNode* l = nullptr) : key(k), data(d), size(s), father(f), right(r), left(l) {}
    void correct_h()
    {
        int n = -1, m = -1;
        if (right != nullptr) m = right->size;
        if (left != nullptr) n = left->size;
        size = max(m, n) + 1;
    }
    int defect_h()
    {
        int n = -1, m = -1;
        if (right != nullptr) m = right->size;
        if (left != nullptr) n = left->size;
        return m - n;
    }
    void print() { cout << key << " " << data << " " << size << " " << this << endl; }
};

void DELETE(AVLNode*& p);
void print_1(AVLNode* r, int offset = 0);
void correct_h_1(AVLNode*& p);
void insert_1(int key, bool data, AVLNode*& p);
void del_1(int key, AVLNode*& p);

struct AVLTree
{
    AVLNode* root;

    AVLTree(AVLNode* r) : root(r) {}
    void print() { print_1(root); }
    void correct_h() { correct_h_1(root); }
    void correct_h(AVLNode*& p) { correct_h_1(p); }
    void rotate_right(AVLNode*& p)
    {
        if (p->right == nullptr || p == nullptr) return;
        AVLNode* tmp = p->father;
        AVLNode* tmp1 = p;
        AVLNode* tmp2 = p->right;
        AVLNode* tmp3 = p->right->left;
        p->right = tmp3;
        if(p->right != nullptr) p->right->father = p;
        if (p->father != nullptr)
        {
            if (p->father->left == p) p->father->left = tmp2;
            else p->father->right = tmp2;
            tmp2->father = p->father;
        }
        else tmp2->father = nullptr;
        tmp2->left = tmp1;
        tmp2->left->father = tmp2;
        tmp2->father = tmp;
    }
    void rotate_left(AVLNode*& p)
    {
        if (p->left == nullptr || p == nullptr) return;
        AVLNode* tmp = p->father;
        AVLNode* tmp1 = p;
        AVLNode* tmp2 = p->left;
        AVLNode* tmp3 = p->left->right;
        p->left = tmp3;
        if(p->left != nullptr) p->left->father = p;
        if (p->father != nullptr)
        {
            if (p->father->left == p) p->father->left = tmp2;
            else p->father->right = tmp2;
            tmp2->father = p->father;
        }
        else tmp2->father = nullptr;
        tmp2->right = tmp1;
        tmp2->right->father = tmp2;
        tmp2->father = tmp;
    }
    void correctm2(AVLNode*& p) //левый большой поворот
    {
        if (p->left->right == nullptr)
        {
            rotate_left(p);
            return;
        }
        if (p->left->left == nullptr)
        {
            rotate_right(p->left);
            rotate_left(p);
            return;
        }
        if (p->left->left->size < p->left->right->size)
        {
            rotate_right(p->left);
            rotate_left(p);
        }
        else rotate_left(p);
    }
    void correct2(AVLNode*& p) //правый большой поворот
    {
        if (p->right->left == nullptr)
        {
            rotate_right(p);
            return;
        }
        if (p->right->right == nullptr)
        {
            rotate_left(p->right);
            rotate_right(p);
            return;
        }
        if (p->right->right->size < p->right->left->size)
        {
            rotate_left(p->right);
            rotate_right(p);
        }
        else rotate_right(p);
    }
    void rebalance(AVLNode*& p)
    {
        if (p == nullptr) return;
        rebalance(p->left);
        rebalance(p->right);
        if (p->defect_h() >= 2) correct2(p);
        if (p->defect_h() <= -2) correctm2(p);
        correct_h(p);
        if (p->father != nullptr) p->father->correct_h();
    }
    void insert(int k, bool d)
    {
        insert_1(k, d, root);
        rebalance(root);
    }
    void del_root_noleft()
    {
        if (root == nullptr) return;
        if (root->right == nullptr)
        {
            AVLNode* tmp = root;
            root = nullptr;
            delete tmp;
            return;
        }
        AVLNode* tmp = root;
        AVLNode* tmp1 = root->right;
        tmp1->father = nullptr;
        root->right = nullptr;
        root = tmp1;
        delete tmp;
        correct_h();
        rebalance(root);
    }
    void del_root_noright()
    {
        if (root == nullptr) return;
        if (root->left == nullptr)
        {
            AVLNode* tmp = root;
            root = nullptr;
            delete tmp;
            return;
        }
        AVLNode* tmp = root;
        AVLNode* tmp1 = root->left;
        tmp1->father = nullptr;
        root->left = nullptr;
        root = tmp1;
        delete tmp;
        correct_h();
        rebalance(root);
    }
    void del_uzel_noleft(AVLNode*& p)
    {
        if (p == nullptr) return;
        if (p->father == nullptr)
        {
            del_root_noleft();
            return;
        }
        if (p->right == nullptr)
        {
            AVLNode* tmp = p;
            p->father = nullptr;
            delete tmp;
            return;
        }
        AVLNode* tmp = p;
        AVLNode* tmp1 = p->right;
        p->right = nullptr;
        tmp1->father = tmp->father;
        if (p->father->left == p) p->father->left = tmp1;
        else p->father->right = tmp1;
        delete tmp;
        correct_h();
        rebalance(root);
    }
    void del_uzel_noright(AVLNode*& p)
    {
        if (p == nullptr) return;
        if (p->father == nullptr)
        {
            del_root_noright();
            return;
        }
        if (p->left == nullptr)
        {
            AVLNode* tmp = p;
            p->father = nullptr;
            delete tmp;
            return;
        }
        AVLNode* tmp = p;
        AVLNode* tmp1 = p->left;
        p->left = nullptr;
        tmp1->father = tmp->father;
        if (p->father->left == p) p->father->left = tmp1;
        else p->father->right = tmp1;
        delete tmp;
        correct_h();
        rebalance(root);
    }

    void del(int k) { del_1(k, root); }
    ~AVLTree() { DELETE(root); }
};

void print_1(AVLNode* r, int offset)
{
    if (r == nullptr) return;
    print_1(r->left, offset + 9);
    for (int i = 0; i < offset; i++) cout << " ";
    cout << r->key << " " << r->data << " " << r->size << endl;
    print_1(r->right, offset + 9);
}

void correct_h_1(AVLNode*& p)
{
    if (p == nullptr) return;
    correct_h_1(p->right);
    correct_h_1(p->left);
    int n = -1, m = -1;
    if (p->right != nullptr) m = p->right->size;
    if (p->left != nullptr) n = p->left->size;
    p->size = max(m, n) + 1;
}

void insert_1(int key, bool data, AVLNode*& p)
{
    if (p->key == key) return;
    if (p->key > key)
        if (p->right == nullptr) p->right = new AVLNode(key, data, 0, p->right);
        else insert_1(key, data, p->right);
    else
    if (p->left == nullptr) p->left = new AVLNode(key, data, 0, p->left);
    else insert_1(key, data, p->left);
}

void del_2(int key, AVLNode*& p)
{
    if (p == nullptr) return;
    if (p->key == key)
    {
        if (p->right == nullptr)
        {
            del_uzel_noright_1();
            return;
        }
        if (p->left == nullptr)
        {
            del_uzel_noleft_1(p);
            return;
        }
        p->key = p->left->key;
        p->data = p->left->data;
        del_2(p->key, p->left);
        return;
    }
    if (p->key > key) del_2(key, p->right);
    else del_2(key, p->left);
}

void del_1(int k, AVLNode*& p)
{
    del_1(k, p);
    rebalance_1(p);
}

void DELETE(AVLNode*& p)
{
    if (p->left != nullptr)
    {
        DELETE(p->left);
        p->left = nullptr;
    }
    if (p->right != nullptr)
    {
        DELETE(p->right);
        p->right = nullptr;
    }
    delete p;
}

int main()
{
    AVLNode* root = new AVLNode(5, 101, 0);
    root->right = new AVLNode(3, 111, 0, root);
    root->right->left = new AVLNode(4, 411, 0, root->right);
    root->right->right = new AVLNode(2, 611, 0, root->right);
    root->left = new AVLNode(6, 211, 0, root);
    root->left->left = new AVLNode(11, 1111, 0, root->left);
    root->left->left->left = new AVLNode(21, 3211, 0, root->left->left);
    root->left->left->right = new AVLNode(9, 4681, 0, root->left->left);
    AVLTree* tree = new AVLTree(root);

    tree->correct_h();
    tree->print();
    cout << endl;

    tree->rebalance(tree->root);
    tree->print();
    cout << endl;

    tree->del_uzel_noleft(tree->root->right);
    tree->print();
    cout << endl;

    //system("pause");
    return 0;
}