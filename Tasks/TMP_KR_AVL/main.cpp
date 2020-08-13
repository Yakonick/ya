#include <iostream>
#include <algorithm>

using namespace std;

int LOC_ID = 1;

class AVLNodeN;
class AVLNode
{
public:
    int key;
    int data;
    int loc_id;
    int height;
    AVLNode *left, *right, *parent;
    AVLNodeN *same;

    AVLNode(int d, int k, AVLNode *p = nullptr, int h = 1, AVLNode *l = nullptr, AVLNode *r = nullptr):
            data(d), key(k), parent(p), height(h), left(l), right(r), loc_id(LOC_ID++), same(nullptr) {}
    virtual ~AVLNode() {delete left; delete right; delete parent; delete same;}

    void correct_h() {
        if (left != nullptr && right != nullptr) {
            left->correct_h();
            right->correct_h();
            height = max(left->height, right->height) + 1;
        }
        else if (right != nullptr) {
            right->correct_h();
            height = right->height + 1;
        }
        else if (left != nullptr) {
            left->correct_h();
            height = left->height + 1;
        }
        else
            height = 1;
    }
    int deffect_h()  {
        if (left != nullptr && right != nullptr)
            return left->height - right->height;
        else if (right != nullptr)
            return -right->height;
        else if (left != nullptr)
            return left->height;
        else
            return 0;

    }
    void print()     {
        cout << this << " " << key << " " << loc_id << " " << data << " " << height << " ";
        if (parent != nullptr)
            cout << parent->key << endl;
        else
            cout << "----" << endl;
    }
};

class AVLNodeN
{
public:
    int key;
    int data;
    int loc_id;
    int height;
    AVLNodeN *left, *right, *parent;

    AVLNodeN(int d, int k, AVLNodeN *p = nullptr, int h = 1, AVLNodeN *l = nullptr, AVLNodeN *r = nullptr):
            data(d), key(k), parent(p), height(h), left(l), right(r), loc_id(LOC_ID++) {}
    virtual ~AVLNodeN() {delete left; delete right; delete parent;}

    void correct_h() {
        if (left != nullptr && right != nullptr) {
            left->correct_h();
            right->correct_h();
            height = max(left->height, right->height) + 1;
        }
        else if (right != nullptr) {
            right->correct_h();
            height = right->height + 1;
        }
        else if (left != nullptr) {
            left->correct_h();
            height = left->height + 1;
        }
        else
            height = 1;
    }
    int deffect_h()  {
        if (left != nullptr && right != nullptr)
            return left->height - right->height;
        else if (right != nullptr)
            return -right->height;
        else if (left != nullptr)
            return left->height;
        else
            return 0;

    }
    void print()     {
        cout << this << " " << key << " " << loc_id << " " << data << " " << height << " ";
        if (parent != nullptr)
            cout << parent->key << endl;
        else
            cout << "----" << endl;
    }
};

void DELETE(AVLNode*& p);
void print_1(AVLNode *r, int offset = 0);

class TreeKey
{
public:
    AVLNode *root;

    TreeKey(AVLNode *r = nullptr): root(r) {}
    TreeKey(TreeKey &r): root(r.root) {}
    TreeKey& operator=(const TreeKey& second) { root = second.root; }
    ~TreeKey() { delete root; }

    void print() { print_1(root); }
    void rotate_left(AVLNode *&a) {
        if (a == nullptr || a->right == nullptr) return;
        AVLNode *b = a->right;
        a->right = b->left;
        if (b->left != nullptr)
            b->left->parent = a;
        b->left = a;
        b->parent = a->parent;
        if (a->parent != nullptr) {
            AVLNode *tmp = a->parent;
            if (tmp->left == a)
                tmp->left = b;
            else
                tmp->right = b;
        } else {
            root = b;
        }
        AVLNode *aa = b->left;
        aa->parent = b;
        b->correct_h();
    }
    void rotate_right(AVLNode *&a) {
        if (a == nullptr || a->left == nullptr) return;
        AVLNode *b = a->left;
        a->left = b->right;
        if (b->right != nullptr)
            b->right->parent = a;
        b->right = a;
        b->parent = a->parent;
        if (a->parent != nullptr) {
            AVLNode *tmp = a->parent;
            if (tmp->left == a)
                tmp->left = b;
            else
                tmp->right = b;
        } else {
            root = b;
        }
        AVLNode *aa = b->right;
        aa->parent = b;
        b->correct_h();
    }
    void correctm2(AVLNode *&a) {
        rotate_right(a->right);
        rotate_left(a);
    }
    void correct2(AVLNode *&a) {
        rotate_left(a->left);
        rotate_right(a);
    }
    void rebalance(AVLNode *&a) {
        if (a->parent != nullptr) {
            AVLNode *par = a->parent;
            if (par->deffect_h() == -2) {
                if (par->right->deffect_h() == 1) {
                    correctm2(par);
                } else {
                    rotate_left(par);
                }
            } else if (par->deffect_h() == 2) {
                if (par->left->deffect_h() == -1)
                    correct2(par);
                else
                    rotate_right(par);
            }
            root->correct_h();
        }
    }
    void insert(int k, int d) {
        AVLNode *ins_tmp = root;
        if (ins_tmp == nullptr) {
            root = new AVLNode(d, k);
            return;
        }
        while (true) {
            if (k > ins_tmp->key && ins_tmp->right == nullptr) {
                ins_tmp->right = new AVLNode(d, k, ins_tmp);
                root->correct_h();
                while (true) {
                    rebalance(ins_tmp);
                    if (ins_tmp->parent == nullptr)
                        break;
                    else
                        ins_tmp = ins_tmp->parent;
                }
                break;
            } else if (k > ins_tmp->key && ins_tmp->right != nullptr) {
                ins_tmp = ins_tmp->right;
            } else if (k < ins_tmp->key && ins_tmp->left == nullptr) {
                ins_tmp->left = new AVLNode(d, k, ins_tmp);
                ins_tmp->correct_h();
                //rebalance(ins_tmp);
                break;
            } else if (k < ins_tmp->key && ins_tmp->left != nullptr) {
                ins_tmp = ins_tmp->left;
            } else if (k == ins_tmp->key) break;
        }
    }
    void del_root() {
        AVLNode *tmp = root;
        if (tmp->right == nullptr && tmp->left != nullptr) {
            root = tmp->left;
            tmp->left = nullptr;
            root->parent = nullptr;
            root->correct_h();
            delete tmp;
        } else if (tmp->left == nullptr && tmp->right != nullptr) {
            root = tmp->right;
            tmp->right = nullptr;
            root->parent = nullptr;
            root->correct_h();
            delete tmp;
        } else if (tmp->left == nullptr && tmp->right == nullptr) {
            root = nullptr;
            delete tmp;
        }
    }                       //когда нет правого/левого/обоих сыновей
    void del_right_son(AVLNode *&a) {
        AVLNode *tmp = a->right;
        if (tmp->right == nullptr && tmp->left != nullptr) {
            AVLNode *b = tmp->left;
            a->right = b;
            b->parent = a;
            tmp->parent = nullptr;
            tmp->left = nullptr;
            delete tmp;
        } else if (tmp->right != nullptr && tmp->left == nullptr) {
            AVLNode *b = tmp->right;
            a->right = b;
            b->parent = a;
            tmp->parent = nullptr;
            tmp->right = nullptr;
            delete tmp;
        } else if (tmp->right == nullptr && tmp->left == nullptr) {
            tmp->parent = nullptr;
            a->right = nullptr;
            delete tmp;
        }
    }       //когда нет правого/левого/обоих сыновей
    void del_left_son(AVLNode *&a) {
        AVLNode *tmp = a->left;
        if (tmp->right == nullptr && tmp->left != nullptr) {
            AVLNode *b = tmp->left;
            a->left = b;
            b->parent = a;
            tmp->parent = nullptr;
            tmp->left = nullptr;
            delete tmp;
        } else if (tmp->right != nullptr && tmp->left == nullptr) {
            AVLNode *b = tmp->right;
            a->left = b;
            b->parent = a;
            tmp->parent = nullptr;
            tmp->right = nullptr;
            delete tmp;
        } else if (tmp->right == nullptr && tmp->left == nullptr) {
            tmp->parent = nullptr;
            a->left = nullptr;
            delete tmp;
        }
    }        //когда нет правого/левого/обоих сыновей
    AVLNode *next_key(AVLNode *a) {
        if (a == nullptr) EXIT_FAILURE;
        if (a->right != nullptr)
            a = a->right;
        else
            return nullptr;
        while (a->left != nullptr)
            a = a->left;
        return a;
    }
    AVLNode *search(int k) {
        AVLNode *ans = root;
        while (true) {
            if (k > ans->key) {
                if (ans->right != nullptr)
                    ans = ans->right;
                else
                    return nullptr;
            } else if (k < ans->key) {
                if (ans->left != nullptr)
                    ans = ans->left;
                else
                    return nullptr;
            } else if (k == ans->key)
                return ans;
        }
    }
    void del(int k) {
        AVLNode *a = search(k);
        if (a == nullptr) EXIT_FAILURE;
        if (a == root) {
            if (a->right != nullptr && a->left != nullptr) {
                AVLNode *tmp = next_key(a);
                AVLNode *par_tmp = tmp->parent;
                a->key = tmp->key;
                a->data = tmp->data;
                a->loc_id = tmp->loc_id;
                if (par_tmp->right == tmp)
                    del_right_son(par_tmp);
                else
                    del_left_son(par_tmp);
            } else
                del_root();
        } else if (a->right != nullptr && a->left != nullptr) {
            AVLNode *tmp = next_key(a);
            AVLNode *par_tmp = tmp->parent;
            a->key = tmp->key;
            a->data = tmp->data;
            a->loc_id = tmp->loc_id;
            if (par_tmp->right == tmp)
                del_right_son(par_tmp);
            else
                del_left_son(par_tmp);
        } else {
            AVLNode *par_a = a->parent;
            if (par_a->right == a)
                del_right_son(par_a);
            else
                del_left_son(par_a);
        }
    }
};

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
void print_1(AVLNode *r, int offset)
{
    if(r == nullptr) return;
    print_1(r->right, offset + 3);
    for(int i = 0; i < offset; i++)
        cout << "\t \t";
    r->print();
    print_1(r->left, offset + 3);
}

int main() {
    TreeKey S;
    S.insert(1, 0);
    for (int i = 0; i < 100; i++) {
        S.insert(i + 2, i * 10);
    }
    S.print();
    for (int i = 1; i < 102; i++)
        S.del(i);
    if (S.root != nullptr)
        S.print();
    else
        cout << "ijuytrdesdfcgvhbjnkloiuytf" << endl;

    return 0;
}