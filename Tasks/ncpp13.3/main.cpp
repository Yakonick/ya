#include <iostream>
#include <algorithm>

using namespace std;

int LOC_ID = 1;

class AVLNode
{
public:
    int key;
    int data;
    int loc_id;
    int height;
    AVLNode *left, *right, *parent;

    AVLNode(int d, int k, AVLNode *p = nullptr, int h = 1, AVLNode *l = nullptr, AVLNode *r = nullptr):
            data(d), key(k), parent(p), height(h), left(l), right(r), loc_id(LOC_ID++) {}

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
    ~TreeKey() { DELETE(root); }

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
                if (par->right->deffect_h() == 1)
                    correctm2(par);
                else
                    rotate_left(par);
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
        if (ins_tmp == nullptr)
            root = new AVLNode(d, k);
        while (true) {
            if (k > ins_tmp->key && ins_tmp->right == nullptr) {
                ins_tmp->right = new AVLNode(d, k, ins_tmp);
                ins_tmp->correct_h();
                rebalance(ins_tmp);
                break;
            } else if (k > ins_tmp->key && ins_tmp->right != nullptr) {
                ins_tmp = ins_tmp->right;
            } else if (k < ins_tmp->key && ins_tmp->left == nullptr) {
                ins_tmp->left = new AVLNode(d, k, ins_tmp);
                ins_tmp->correct_h();
                rebalance(ins_tmp);
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

class TreeLocId
{
public:
    AVLNode *root;

    TreeLocId(AVLNode *r = nullptr): root(r) {}
    TreeLocId(TreeLocId &r): root(r.root) {}
    TreeLocId& operator=(const TreeLocId& second) { root = second.root; }
    ~TreeLocId() { DELETE(root); }

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
                if (par->right->deffect_h() == 1)
                    correctm2(par);
                else
                    rotate_left(par);
            } else if (par->deffect_h() == 2) {
                if (par->left->deffect_h() == -1)
                    correct2(par);
                else
                    rotate_right(par);
            }
            root->correct_h();
        }
    }
    void insert(int l, int d) {
        AVLNode *ins_tmp = root;
        if (ins_tmp == nullptr)
            root = new AVLNode(d, l);
        while (true) {
            if (l > ins_tmp->loc_id && ins_tmp->right == nullptr) {
                ins_tmp->right = new AVLNode(d, l, ins_tmp);
                ins_tmp->correct_h();
                rebalance(ins_tmp);
                break;
            } else if (l > ins_tmp->loc_id && ins_tmp->right != nullptr) {
                ins_tmp = ins_tmp->right;
            } else if (l < ins_tmp->loc_id && ins_tmp->left == nullptr) {
                ins_tmp->left = new AVLNode(d, l, ins_tmp);
                ins_tmp->correct_h();
                rebalance(ins_tmp);
                break;
            } else if (l < ins_tmp->loc_id && ins_tmp->left != nullptr) {
                ins_tmp = ins_tmp->left;
            } else if (l == ins_tmp->loc_id) break;
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
    AVLNode *search(int l) {
        AVLNode *ans = root;
        if (l > ans->loc_id) {
            if (ans->right != nullptr)
                ans = ans->right;
            else
                return nullptr;
        } else if (l < ans->loc_id) {
            if (ans->left != nullptr)
                ans = ans->left;
            else
                return nullptr;
        } else if (l == ans->loc_id)
            return ans;
    }
    AVLNode *next_loc_id(AVLNode *a) {
        return search(a->loc_id + 1);
    }
    void del(int l) {
        AVLNode *a = search(l);
        if (a == nullptr) EXIT_FAILURE;
        if (a == root) {
            if (a->right != nullptr && a->left != nullptr) {
                AVLNode *tmp = next_loc_id(a);
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
            AVLNode *tmp = next_loc_id(a);
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


class SuperList {
    TreeKey *root1;
    TreeLocId *root2;
    AVLNode *search_loc_id(int l) { root2->search(l); }
    AVLNode *search_key(int k) { root1->search(k); }
    void insert(int k, int data) {
        root1->insert(k, data);
        root2->insert(k, data);
    }
    void del_key(int k) {
        int l = search_key(k)->loc_id;
        root1->del(k);
        root2->del(l);
    }
    void del_loc_id(int l) {
        int k = search_loc_id(l)->key;
        root1->del(k);
        root2->del(l);
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
    AVLNode *root = new AVLNode(123456, 5);
    TreeKey *tree = new TreeKey(root);
    tree->insert(6, 67890);


    tree->print();
    tree->insert(7, 7688);
    cout << endl << endl;
    tree->del(6);
    tree->print();
    cout << endl << endl;
    return 0;
}