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
    AVLNode(int k, bool d, int s, AVLNode* f = nullptr, AVLNode* r = nullptr, AVLNode* l = nullptr) :
            key(k), data(d), size(s), father(f), right(r), left(l) {}

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

void correct_h_1(AVLNode*& p);
AVLNode* search_1(int key, AVLNode* p);
void rotate_right_1(AVLNode*& p);
void rotate_left_1(AVLNode*& p);
void rebalance_1(AVLNode*& p);
void correctm2_1(AVLNode*& p);
void correct2_1(AVLNode*& p);
void insert_1(int key, bool data, AVLNode*& p);
void del_root_noleft_1(AVLNode*& p);
void del_root_noright_1(AVLNode*& p);
void del_uzel_noleft_1(AVLNode*& p);
void del_uzel_noright_1(AVLNode*& p);
void del_1(int key, AVLNode*& p);
void DELETE(AVLNode*& p);
AVLNode* search_data_true_1(AVLNode* p);

struct AVLTree
{
    AVLNode* root;

    AVLTree(AVLNode* r) : root(r) {}
    void correct_h() { correct_h_1(root); }
    void correct_h(AVLNode*& p) { correct_h_1(p); }
    AVLNode* search(int k) { return search_1(k, root); } // 1 ПУНКТ ЗАДАЧИ
    void rotate_right(AVLNode*& p) { rotate_right_1(p); }
    void rotate_left(AVLNode*& p) { rotate_left_1(p); }
    void correctm2(AVLNode*& p) { correctm2_1(p); } //левый большой поворот
    void correct2(AVLNode*& p) { correct2_1(p); } //правый большой поворот
    void rebalance(AVLNode*& p) { rebalance_1(p); }
    void insert(int k, bool d) { insert_1(k, d, root); }  // 2 ПУНКТ ЗАДАЧИ
    void del_root_noleft() { del_root_noleft_1(root); }
    void del_root_noright() { del_root_noright_1(root); }
    void del_uzel_noleft(AVLNode*& p) { del_uzel_noleft_1(p); }
    void del_uzel_noright(AVLNode*& p) { del_uzel_noright_1(p); }
    void del(int k) { del_1(k, root); } // 3 ПУНКТ ЗАДАЧИ
    AVLNode* search_data_true() { search_data_true_1(root); } // 4 ПУНКТ ЗАДАЧИ
    ~AVLTree() { DELETE(root); }
};

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

AVLNode* search_1(int key, AVLNode* p)
{
    if (p == nullptr) EXIT_FAILURE;
    if (p->key == key) return p;
    if (p->key > key) return search_1(key, p->right);
    return search_1(key, p->left);
}

void rotate_right_1(AVLNode*& p)
{
    if (p->right == nullptr || p == nullptr) return;
    AVLNode* tmp = p->father;
    AVLNode* tmp1 = p;
    AVLNode* tmp2 = p->right;
    AVLNode* tmp3 = p->right->left;
    p->right = tmp3;
    if (p->right != nullptr) p->right->father = p;
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

void rotate_left_1(AVLNode*& p)
{
    if (p->left == nullptr || p == nullptr) return;
    AVLNode* tmp = p->father;
    AVLNode* tmp1 = p;
    AVLNode* tmp2 = p->left;
    AVLNode* tmp3 = p->left->right;
    p->left = tmp3;
    if (p->left != nullptr) p->left->father = p;
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

void correctm2_1(AVLNode*& p)
{
    if (p->left->right == nullptr)
    {
        rotate_left_1(p);
        return;
    }
    if (p->left->left == nullptr)
    {
        rotate_right_1(p->left);
        rotate_left_1(p);
        return;
    }
    if (p->left->left->size < p->left->right->size)
    {
        rotate_right_1(p->left);
        rotate_left_1(p);
    }
    else rotate_left_1(p);
}

void correct2_1(AVLNode*& p)
{
    if (p->right->left == nullptr)
    {
        rotate_right_1(p);
        return;
    }
    if (p->right->right == nullptr)
    {
        rotate_left_1(p->right);
        rotate_right_1(p);
        return;
    }
    if (p->right->right->size < p->right->left->size)
    {
        rotate_left_1(p->right);
        rotate_right_1(p);
    }
    else rotate_right_1(p);
}

void rebalance_1(AVLNode*& p)
{
    if (p == nullptr) return;
    if (p->father != nullptr)
    {
        rebalance_1(p->father);
        return;
    }
    rebalance_1(p->left);
    rebalance_1(p->right);
    if (p->defect_h() >= 2) correct2_1(p);
    if (p->defect_h() <= -2) correctm2_1(p);
    correct_h_1(p);
    if (p->father != nullptr) p->father->correct_h();
}

void insert_2(int key, bool data, AVLNode*& p)
{
    if (p->key == key) return;
    if (p->key > key)
        if (p->right == nullptr) p->right = new AVLNode(key, data, 0, p->right);
        else insert_2(key, data, p->right);
    else
        if (p->left == nullptr) p->left = new AVLNode(key, data, 0, p->left);
        else insert_2(key, data, p->left);
}

void insert_1(int k, bool d, AVLNode*& p)
{
    insert_2(k, d, p);
    rebalance_1(p);
}

void del_root_noleft_1(AVLNode*& p)
{
    if (p == nullptr) return;
    if (p->right == nullptr)
    {
        AVLNode* tmp = p;
        p = nullptr;
        delete tmp;
        return;
    }
    AVLNode* tmp = p;
    AVLNode* tmp1 = p->right;
    tmp1->father = nullptr;
    p->right = nullptr;
    p = tmp1;
    delete tmp;
    rebalance_1(p);
}

void del_root_noright_1(AVLNode*& p)
{
    if (p == nullptr) return;
    if (p->left == nullptr)
    {
        AVLNode* tmp = p;
        p = nullptr;
        delete tmp;
        return;
    }
    AVLNode* tmp = p;
    AVLNode* tmp1 = p->left;
    tmp1->father = nullptr;
    p->left = nullptr;
    p = tmp1;
    delete tmp;
    rebalance_1(p);
}

void del_uzel_noleft_1(AVLNode*& p)
{
    if (p == nullptr) return;
    if (p->father == nullptr)
    {
        del_root_noleft_1(p);
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
    rebalance_1(p);
}

void del_uzel_noright_1(AVLNode*& p)
{
    if (p == nullptr) return;
    if (p->father == nullptr)
    {
        del_root_noright_1(p);
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
    rebalance_1(p);
}

void del_2(int key, AVLNode*& p)
{
    if (p == nullptr) return;
    if (p->key == key)
    {
        if (p->right == nullptr)
        {
            del_uzel_noright_1(p);
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
    del_2(k, p);
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


AVLNode* search_data_true_1(AVLNode* p)
{
    if (p == nullptr) EXIT_FAILURE;
    if (p->data) return p;
    if (p->right != nullptr) return search_data_true_1(p->right);
    else if (p->left != nullptr) return search_data_true_1(p->left);
    else EXIT_FAILURE;
}
