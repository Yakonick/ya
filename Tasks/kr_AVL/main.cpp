#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

class AVLNodeN;
int LOC_ID = 0;

class AVLNodeK
{
public:
    int key;
    int data;
    int height;
    AVLNodeK *left, *right, *parent;
    AVLNodeN *same;

    AVLNodeK(int d, AVLNodeK *p = nullptr, AVLNodeK *l = nullptr, AVLNodeK *r = nullptr, int h = 1):
            data(d), key(LOC_ID++), parent(p), height(h), left(l), right(r) {}

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
        cout << this << " " << key << " " << data << " " << height << " ";
        if (parent != nullptr)
            cout << parent->key << endl;
        else
            cout << "----" << endl;
    }
};

class AVLNodeN
{
public:
    int right_sons, left_sons;
    int data;
    int height;
    AVLNodeN *left, *right, *parent;
    AVLNodeK *same;

    AVLNodeN(int d, AVLNodeN *p = nullptr, AVLNodeN *l = nullptr, AVLNodeN *r = nullptr, int h = 1):
            data(d), parent(p), height(h), left(l), right(r), right_sons(0), left_sons(0) {}

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
    void correct_right_sons() {
        if (right == nullptr)
            right_sons = 0;
        else {
            right->correct_right_sons();
            right->correct_left_sons();
            right_sons = right->right_sons + right->left_sons + 1;
        }
    }
    void correct_left_sons() {
        if (left == nullptr)
            left_sons = 0;
        else {
            left->correct_right_sons();
            left->correct_left_sons();
            left_sons = left->right_sons + left->left_sons + 1;
        }
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
        cout << this << " " << data << " " << height << " " << left_sons << " " << right_sons << " ";
        if (parent == nullptr) {
            cout << "------" << endl;
        } else
            cout << "   par: " << parent->data << endl;
    }
};

void DELETE(AVLNodeK*& p);
void print_1(AVLNodeK *r, int offset = 0);
void DELETE(AVLNodeN*& p);
void print_1(AVLNodeN *r, int offset = 0);


class TreeNum
{
public:
    AVLNodeN *root;

    TreeNum(AVLNodeN *r = nullptr): root(r) {}
    TreeNum(TreeNum &r): root(r.root) {}
    TreeNum& operator=(const TreeNum& second) { root = second.root; }
    ~TreeNum() { DELETE(root); }

    void print() { print_1(root); }
    void rotate_left(AVLNodeN *&a) {
        if (a == nullptr || a->right == nullptr) return;
        AVLNodeN *b = a->right;
        a->right = b->left;
        if (b->left != nullptr) {
            a->right_sons = b->left->right_sons + b->left->left_sons + 1;
            b->left->parent = a;
        } else {
            a->right_sons = 0;
        }
        b->left = a;
        b->left_sons = a->right_sons + a->left_sons + 1;
        b->parent = a->parent;
        if (a->parent != nullptr) {
            AVLNodeN *tmp = a->parent;
            if (tmp->left == a)
                tmp->left = b;
            else
                tmp->right = b;
        } else {
            root = b;
        }
        AVLNodeN *aa = b->left;
        aa->parent = b;

        if (a->left != nullptr && a->right != nullptr)
            a->height = max(a->right->height, a->left->height) + 1;
        else if (a->left == nullptr && a->right != nullptr)
            a->height = a->right->height + 1;
        else if (a->right == nullptr && a->left != nullptr)
            a->height = a->left->height + 1;
        else
            a->height = 1;
        if (b->left != nullptr && b->right != nullptr)
            b->height = max(b->right->height, b->left->height) + 1;
        else if (b->left == nullptr && b->right != nullptr)
            b->height = b->right->height + 1;
        else if (b->right == nullptr && a->left != nullptr)
            b->height = b->left->height + 1;
        else
            b->height = 1;
    }
    void rotate_right(AVLNodeN *&a) {
        if (a == nullptr || a->left == nullptr) return;
        AVLNodeN *b = a->left;
        a->left = b->right;
        if (b->right != nullptr) {
            a->left_sons = b->right->right_sons + b->right->left_sons + 1;
            b->right->parent = a;
        } else {
            a->left_sons = 0;
        }
        b->right = a;
        b->right_sons = a->right_sons + a->left_sons + 1;
        b->parent = a->parent;
        if (a->parent != nullptr) {
            AVLNodeN *tmp = a->parent;
            if (tmp->left == a)
                tmp->left = b;
            else
                tmp->right = b;
        } else {
            root = b;
        }
        AVLNodeN *aa = b->right;
        aa->parent = b;
        if (a->left != nullptr && a->right != nullptr)
            a->height = max(a->right->height, a->left->height) + 1;
        else if (a->left == nullptr && a->right != nullptr)
            a->height = a->right->height + 1;
        else if (a->right == nullptr && a->left != nullptr)
            a->height = a->left->height + 1;
        else
            a->height = 1;
        if (b->left != nullptr && b->right != nullptr)
            b->height = max(b->right->height, b->left->height) + 1;
        else if (b->left == nullptr && b->right != nullptr)
            b->height = b->right->height + 1;
        else if (b->right == nullptr && a->left != nullptr)
            b->height = b->left->height + 1;
        else
            b->height = 1;
    }
    void correctm2(AVLNodeN *&a) {
        rotate_right(a->right);
        rotate_left(a);
    }
    void correct2(AVLNodeN *&a) {
        rotate_left(a->left);
        rotate_right(a);
    }
    void rebalance(AVLNodeN *&a) {
        if (a == nullptr)
            return;
        if (a->parent != nullptr) {
            AVLNodeN *par = a->parent;
            if (par->deffect_h() == -2) {
                if (par->right->deffect_h() == 1) {
                    correctm2(par);
                } else {
                    rotate_left(par);
                }
            } else if (par->deffect_h() == 2) {
                if (par->left->deffect_h() == -1) {
                    correct2(par);
                } else {
                    rotate_right(par);
                }
            }
            AVLNodeN *tmp = a;
            while (tmp->parent != nullptr) {
                tmp = tmp->parent;
                if (tmp->left != nullptr && tmp->right != nullptr)
                    tmp->height = max(tmp->right->height, tmp->left->height) + 1;
                else if (tmp->left == nullptr)
                    tmp->height = tmp->right->height + 1;
                else if (tmp->right == nullptr)
                    tmp->height = tmp->left->height + 1;
            }
        }
    }
    void rebalance_more2_left(AVLNodeN *&a) {
        if (a->right == nullptr)
            return;
        AVLNodeN *tmp = a->right;
        while (a->deffect_h() > 2 || a->deffect_h() < -2) {
            rotate_left(a);
        }
        if (a->deffect_h() == 2 || a->deffect_h() == -2)
            rebalance(a);
        while (tmp->parent != nullptr) {
            tmp = tmp->parent;
            if (tmp->left != nullptr && tmp->right != nullptr)
                tmp->height = max(tmp->right->height, tmp->left->height) + 1;
            else if (tmp->left == nullptr)
                tmp->height = tmp->right->height + 1;
            else if (tmp->right == nullptr)
                tmp->height = tmp->left->height + 1;
        }
    }
    AVLNodeN *search(int n) {
        AVLNodeN *ans = root;
        if (ans == nullptr) EXIT_FAILURE;
        int num = ans->left_sons;
        while (true) {
            if (n == num)
                return ans;
            else if (n > num && ans->right != nullptr) {
                ans = ans->right;
                num += ans->parent->right_sons - ans->right_sons;
            } else if (n > num && ans->right == nullptr)
                return nullptr;
            else if (n < num && ans->left != nullptr) {
                ans = ans->left;
                num += ans->left_sons - ans->parent->left_sons;
            } else if (n < num && ans->left == nullptr)
                return nullptr;
        }

    }
    void insert(int k, int d) {
        AVLNodeN *ins_tmp = root;
        int num = ins_tmp->left_sons;
        while (true) {
            if (k > num && ins_tmp->right == nullptr) {
                AVLNodeN *tmp = ins_tmp;
                ins_tmp->right = new AVLNodeN(d, ins_tmp);
                ins_tmp->right_sons++;
                ins_tmp->height++;
                if (tmp->parent != nullptr) {
                    tmp = tmp->parent;
                    while (tmp->parent != nullptr) {
                        if (tmp->parent->right == tmp) {
                            tmp->parent->right_sons++;
                        } else {
                            tmp->parent->left_sons++;
                        }
                        tmp = tmp->parent;
                    }
                }
                tmp = ins_tmp;
                while (tmp->parent != nullptr) {
                    tmp = tmp->parent;
                    if (tmp->left != nullptr && tmp->right != nullptr)
                        tmp->height = max(tmp->right->height, tmp->left->height) + 1;
                    else if (tmp->left == nullptr)
                        tmp->height = tmp->right->height + 1;
                    else if (tmp->right == nullptr)
                        tmp->height = tmp->left->height + 1;
                }
                while (true) {
                    rebalance(ins_tmp);
                    if (ins_tmp->parent == nullptr)
                        break;
                    else
                        ins_tmp = ins_tmp->parent;
                }
                break;
            } else if (k > num && ins_tmp->right != nullptr) {
                ins_tmp = ins_tmp->right;
                num += ins_tmp->parent->right_sons - ins_tmp->right_sons;
            } else if (k < num && ins_tmp->left != nullptr) {
                ins_tmp = ins_tmp->left;
                num += ins_tmp->left_sons - ins_tmp->parent->left_sons;
            } else if (k == num) {
                AVLNodeN *ins = new AVLNodeN(d, ins_tmp->parent, ins_tmp->left, ins_tmp);
                AVLNodeN *tmp = ins_tmp;
                if (ins_tmp->parent != nullptr) {
                    if (ins_tmp->parent->right == ins_tmp) {
                        ins_tmp->parent->right = ins;
                    } else {
                        ins_tmp->parent->left = ins;
                    }
                } else
                    root = ins;
                ins_tmp->parent = ins;
                if (ins_tmp->left != nullptr)
                    ins_tmp->left->parent = ins;
                ins_tmp->left = nullptr;
                ins->right_sons = ins_tmp->right_sons + 1;
                ins->left_sons = ins_tmp->left_sons;
                ins_tmp->left_sons = 0;
                //tmp->correct_h();
                while (tmp->parent != nullptr) {
                    tmp = tmp->parent;
                    if (tmp->left != nullptr && tmp->right != nullptr)
                        tmp->height = max(tmp->right->height, tmp->left->height) + 1;
                    else if (tmp->left == nullptr)
                        tmp->height = tmp->right->height + 1;
                    else if (tmp->right == nullptr)
                        tmp->height = tmp->left->height + 1;
                }
                if (ins->parent != nullptr) {
                    while (ins->parent != nullptr) {
                        if (ins->parent->right == ins) {
                            ins->parent->right_sons++;
                        } else {
                            ins->parent->left_sons++;
                        }
                        ins = ins->parent;
                    }
                }
                rebalance_more2_left(ins_tmp);
                while (true) {
                    rebalance(ins_tmp);
                    if (ins_tmp->parent == nullptr)
                        break;
                    else
                        ins_tmp = ins_tmp->parent;
                }
                break;
            }
        }
    }
    void del_root() {
        AVLNodeN *tmp = root;
        if (tmp->right == nullptr && tmp->left != nullptr) {
            root = tmp->left;
            tmp->left = nullptr;
            root->parent = nullptr;
            delete tmp;
        } else if (tmp->left == nullptr && tmp->right != nullptr) {
            root = tmp->right;
            tmp->right = nullptr;
            root->parent = nullptr;
            delete tmp;
        } else if (tmp->left == nullptr && tmp->right == nullptr) {
            root = nullptr;
            delete tmp;
        }
    }                       //когда нет правого/левого/обоих сыновей
    void del_right_son(AVLNodeN *&a) {
        AVLNodeN *tmp = a->right;
        AVLNodeN *ins_tmp = a;
        if (tmp->right == nullptr && tmp->left != nullptr) {
            AVLNodeN *b = tmp->left;
            a->right = b;
            a->right_sons = b->right_sons + b->left_sons + 1;
            b->parent = a;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            if (a->parent != nullptr) {
                while (a->parent != nullptr) {
                    if (a->parent->right == a) {
                        a->parent->right_sons = a->right_sons + a->left_sons + 1;
                    } else {
                        a->parent->left_sons = a->right_sons + a->left_sons + 1;
                    }
                    a = a->parent;
                }
            }
            tmp->parent = nullptr;
            tmp->left = nullptr;
            delete tmp;
        } else if (tmp->right != nullptr && tmp->left == nullptr) {
            AVLNodeN *b = tmp->right;
            a->right = b;
            b->parent = a;
            a->right_sons = b->right_sons + b->left_sons + 1;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            if (a->parent != nullptr) {
                while (a->parent != nullptr) {
                    if (a->parent->right == a) {
                        a->parent->right_sons = a->right_sons + a->left_sons + 1;
                    } else {
                        a->parent->left_sons = a->right_sons + a->left_sons + 1;
                    }
                    a = a->parent;
                }
            }
            tmp->parent = nullptr;
            tmp->right = nullptr;
            delete tmp;
        } else if (tmp->right == nullptr && tmp->left == nullptr) {
            tmp->parent = nullptr;
            a->right = nullptr;
            if (a->left != nullptr)
                a->height = a->left->height + 1;
            else
                a->height = 1;
            AVLNodeN *b = a;
            a->right_sons = 0;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            if (a->parent != nullptr) {
                while (a->parent != nullptr) {
                    if (a->parent->right == a) {
                        a->parent->right_sons = a->right_sons + a->left_sons + 1;
                    } else {
                        a->parent->left_sons = a->right_sons + a->left_sons + 1;
                    }
                    a = a->parent;
                }
            }
            delete tmp;
        }
        while (true) {
            rebalance(ins_tmp);
            if (ins_tmp->parent == nullptr)
                break;
            else
                ins_tmp = ins_tmp->parent;
        }
    }       //когда нет правого/левого/обоих сыновей
    void del_left_son(AVLNodeN *&a) {
        AVLNodeN *tmp = a->left;
        AVLNodeN *ins_tmp = a;
        if (tmp->right == nullptr && tmp->left != nullptr) {
            AVLNodeN *b = tmp->left;
            a->left = b;
            b->parent = a;
            a->left_sons = b->right_sons + b->left_sons + 1;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            if (a->parent != nullptr) {
                while (a->parent != nullptr) {
                    if (a->parent->right == a) {
                        a->parent->right_sons = a->right_sons + a->left_sons + 1;
                    } else {
                        a->parent->left_sons = a->right_sons + a->left_sons + 1;
                    }
                    a = a->parent;
                }
            }
            tmp->parent = nullptr;
            tmp->left = nullptr;
            delete tmp;
        } else if (tmp->right != nullptr && tmp->left == nullptr) {
            AVLNodeN *b = tmp->right;
            a->left = b;
            b->parent = a;
            a->left_sons = b->right_sons + b->left_sons + 1;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            if (a->parent != nullptr) {
                while (a->parent != nullptr) {
                    if (a->parent->right == a) {
                        a->parent->right_sons = a->right_sons + a->left_sons + 1;
                    } else {
                        a->parent->left_sons = a->right_sons + a->left_sons + 1;
                    }
                    a = a->parent;
                }
            }
            tmp->parent = nullptr;
            tmp->right = nullptr;
            delete tmp;
        } else if (tmp->right == nullptr && tmp->left == nullptr) {
            tmp->parent = nullptr;
            a->left = nullptr;
            a->left_sons = 0;
            if (a->right != nullptr)
                a->height = a->right->height + 1;
            else
                a->height = 1;
            AVLNodeN *b = a;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            if (a->parent != nullptr) {
                while (a->parent != nullptr) {
                    if (a->parent->right == a) {
                        a->parent->right_sons = a->right_sons + a->left_sons + 1;
                    } else {
                        a->parent->left_sons = a->right_sons + a->left_sons + 1;
                    }
                    a = a->parent;
                }
            }
            delete tmp;
        }
        while (true) {
            rebalance(ins_tmp);
            if (ins_tmp->parent == nullptr)
                break;
            else
                ins_tmp = ins_tmp->parent;
        }
    }        //когда нет правого/левого/обоих сыновей
    AVLNodeN *next_num(AVLNodeN *a) {
        if (a == nullptr) EXIT_FAILURE;
        if (a->right != nullptr)
            a = a->right;
        else
            return nullptr;
        while (a->left != nullptr)
            a = a->left;
        return a;
    }
    void del(AVLNodeN *&a) {
        if (a == nullptr) EXIT_FAILURE;
        if (a == root) {
            if (a->right != nullptr && a->left != nullptr) {
                AVLNodeN *tmp = next_num(a);
                AVLNodeN *par_tmp = tmp->parent;
                a->data = tmp->data;
                if (par_tmp->right == tmp)
                    del_right_son(par_tmp);
                else
                    del_left_son(par_tmp);
            } else
                del_root();
        } else if (a->right != nullptr && a->left != nullptr) {
            AVLNodeN *tmp = next_num(a);
            AVLNodeN *par_tmp = tmp->parent;
            a->data = tmp->data;
            if (par_tmp->right == tmp)
                del_right_son(par_tmp);
            else
                del_left_son(par_tmp);
        } else {
            AVLNodeN *par_a = a->parent;
            if (par_a->right == a)
                del_right_son(par_a);
            else
                del_left_son(par_a);
        }
    }
};

class TreeKey
{
public:
    AVLNodeK *root2;

    TreeKey(AVLNodeK *r = nullptr): root2(r) {}
    TreeKey(TreeKey &r): root2(r.root2) {}
    TreeKey& operator=(const TreeKey& second) { root2 = second.root2; }
    ~TreeKey() { DELETE(root2); }

    void print() { print_1(root2); }
    void rotate_left(AVLNodeK *&a) {
        if (a == nullptr || a->right == nullptr) return;
        AVLNodeK *b = a->right;
        a->right = b->left;
        if (b->left != nullptr)
            b->left->parent = a;
        b->left = a;
        b->parent = a->parent;
        if (a->parent != nullptr) {
            AVLNodeK *tmp = a->parent;
            if (tmp->left == a)
                tmp->left = b;
            else
                tmp->right = b;
        } else {
            root2 = b;
        }
        AVLNodeK *aa = b->left;
        aa->parent = b;
        if (a->left != nullptr && a->right != nullptr)
            a->height = max(a->right->height, a->left->height) + 1;
        else if (a->left == nullptr && a->right != nullptr)
            a->height = a->right->height + 1;
        else if (a->right == nullptr && a->left != nullptr)
            a->height = a->left->height + 1;
        else
            a->height = 1;
        if (b->left != nullptr && b->right != nullptr)
            b->height = max(b->right->height, b->left->height) + 1;
        else if (b->left == nullptr && b->right != nullptr)
            b->height = b->right->height + 1;
        else if (b->right == nullptr && a->left != nullptr)
            b->height = b->left->height + 1;
        else
            b->height = 1;
    }
    void rotate_right(AVLNodeK *&a) {
        if (a == nullptr || a->left == nullptr) return;
        AVLNodeK *b = a->left;
        a->left = b->right;
        if (b->right != nullptr)
            b->right->parent = a;
        b->right = a;
        b->parent = a->parent;
        if (a->parent != nullptr) {
            AVLNodeK *tmp = a->parent;
            if (tmp->left == a)
                tmp->left = b;
            else
                tmp->right = b;
        } else {
            root2 = b;
        }
        AVLNodeK *aa = b->right;
        aa->parent = b;
        if (a->left != nullptr && a->right != nullptr)
            a->height = max(a->right->height, a->left->height) + 1;
        else if (a->left == nullptr && a->right != nullptr)
            a->height = a->right->height + 1;
        else if (a->right == nullptr && a->left != nullptr)
            a->height = a->left->height + 1;
        else
            a->height = 1;
        if (b->left != nullptr && b->right != nullptr)
            b->height = max(b->right->height, b->left->height) + 1;
        else if (b->left == nullptr && b->right != nullptr)
            b->height = b->right->height + 1;
        else if (b->right == nullptr && a->left != nullptr)
            b->height = b->left->height + 1;
        else
            b->height = 1;
    }
    void correctm2(AVLNodeK *&a) {
        rotate_right(a->right);
        rotate_left(a);
    }
    void correct2(AVLNodeK *&a) {
        rotate_left(a->left);
        rotate_right(a);
    }
    void rebalance(AVLNodeK *&a) {
        if (a->parent != nullptr) {
            AVLNodeK *par = a->parent;
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
        }
    }
    void insert(int d) {
        AVLNodeK *ins_tmp = root2;
        while (ins_tmp->right != nullptr)
            ins_tmp = ins_tmp->right;
        ins_tmp->right = new AVLNodeK(d, ins_tmp);
        ins_tmp->height++;
        AVLNodeK *tmp = ins_tmp;
        while (tmp->parent != nullptr) {
            tmp = tmp->parent;
            if (tmp->left != nullptr && tmp->right != nullptr)
                tmp->height = max(tmp->right->height, tmp->left->height) + 1;
            else if (tmp->left == nullptr)
                tmp->height = tmp->right->height + 1;
            else if (tmp->right == nullptr)
                tmp->height = tmp->left->height + 1;
        }
        while (true) {
            rebalance(ins_tmp);
            if (ins_tmp->parent == nullptr)
                break;
            else
                ins_tmp = ins_tmp->parent;
        }
    }
    void del_root() {
        AVLNodeK *tmp = root2;
        if (tmp->right == nullptr && tmp->left != nullptr) {
            root2 = tmp->left;
            tmp->left = nullptr;
            root2->parent = nullptr;
            delete tmp;
        } else if (tmp->left == nullptr && tmp->right != nullptr) {
            root2 = tmp->right;
            tmp->right = nullptr;
            root2->parent = nullptr;
            delete tmp;
        } else if (tmp->left == nullptr && tmp->right == nullptr) {
            root2 = nullptr;
            delete tmp;
        }
    }                       //когда нет правого/левого/обоих сыновей
    void del_right_son(AVLNodeK *&a) {
        AVLNodeK *tmp = a->right;
        AVLNodeK *ins_tmp = a;
        if (tmp->right == nullptr && tmp->left != nullptr) {
            AVLNodeK *b = tmp->left;
            a->right = b;
            b->parent = a;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            tmp->parent = nullptr;
            tmp->left = nullptr;
            delete tmp;
        } else if (tmp->right != nullptr && tmp->left == nullptr) {
            AVLNodeK *b = tmp->right;
            a->right = b;
            b->parent = a;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            tmp->parent = nullptr;
            tmp->right = nullptr;
            delete tmp;
        } else if (tmp->right == nullptr && tmp->left == nullptr) {
            tmp->parent = nullptr;
            a->right = nullptr;
            if (a->left != nullptr)
                a->height = a->left->height + 1;
            else
                a->height = 1;
            AVLNodeK *b = a;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            delete tmp;
        }
        while (true) {
            rebalance(ins_tmp);
            if (ins_tmp->parent == nullptr)
                break;
            else
                ins_tmp = ins_tmp->parent;
        }
    }       //когда нет правого/левого/обоих сыновей
    void del_left_son(AVLNodeK *&a) {
        AVLNodeK *tmp = a->left;
        AVLNodeK *ins_tmp = a;
        if (tmp->right == nullptr && tmp->left != nullptr) {
            AVLNodeK *b = tmp->left;
            a->left = b;
            b->parent = a;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            tmp->parent = nullptr;
            tmp->left = nullptr;
            delete tmp;
        } else if (tmp->right != nullptr && tmp->left == nullptr) {
            AVLNodeK *b = tmp->right;
            a->left = b;
            b->parent = a;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            tmp->parent = nullptr;
            tmp->right = nullptr;
            delete tmp;
        } else if (tmp->right == nullptr && tmp->left == nullptr) {
            tmp->parent = nullptr;
            a->left = nullptr;
            if (a->right != nullptr)
                a->height = a->right->height + 1;
            else
                a->height = 1;
            AVLNodeK *b = a;
            while (b->parent != nullptr) {
                b = b->parent;
                if (b->left != nullptr && b->right != nullptr)
                    b->height = max(b->right->height, b->left->height) + 1;
                else if (b->left == nullptr)
                    b->height = b->right->height + 1;
                else if (b->right == nullptr)
                    b->height = b->left->height + 1;
            }
            delete tmp;
        }
        while (true) {
            rebalance(ins_tmp);
            if (ins_tmp->parent == nullptr)
                break;
            else
                ins_tmp = ins_tmp->parent;
        }
    }        //когда нет правого/левого/обоих сыновей
    AVLNodeK *next_key(AVLNodeK *a) {
        if (a == nullptr) EXIT_FAILURE;
        if (a->right != nullptr)
            a = a->right;
        else
            return nullptr;
        while (a->left != nullptr)
            a = a->left;
        return a;
    }
    AVLNodeK *search(int k) {
        AVLNodeK *ans = root2;
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
    void del(AVLNodeK *&a) {
        if (a == nullptr) EXIT_FAILURE;
        if (a == root2) {
            if (a->right != nullptr && a->left != nullptr) {
                AVLNodeK *tmp = next_key(a);
                AVLNodeK *par_tmp = tmp->parent;
                a->key = tmp->key;
                a->data = tmp->data;
                if (par_tmp->right == tmp)
                    del_right_son(par_tmp);
                else
                    del_left_son(par_tmp);
            } else
                del_root();
        } else if (a->right != nullptr && a->left != nullptr) {
            AVLNodeK *tmp = next_key(a);
            AVLNodeK *par_tmp = tmp->parent;
            a->key = tmp->key;
            a->data = tmp->data;
            if (par_tmp->right == tmp)
                del_right_son(par_tmp);
            else
                del_left_son(par_tmp);
        } else {
            AVLNodeK *par_a = a->parent;
            if (a->parent != nullptr) {
                if (par_a->right == a)
                    del_right_son(par_a);
                else
                    del_left_son(par_a);
            } else
                del_root();
        }
    }
};


class SuperList {
public:
    TreeNum *root1;
    TreeKey *root2;
    SuperList(TreeNum *r1 = nullptr, TreeKey *r2 = nullptr): root1(r1), root2(r2) {}
    ~SuperList() { delete root1; delete root2; }
    AVLNodeN *search_num(int l) { root1->search(l); }
    AVLNodeK *search_key(int k) { root2->search(k); }
    void insert(int data, int num) {
        if (root1 == nullptr) {
            AVLNodeN *p = new AVLNodeN(data);
            root1 = new TreeNum(p);
            AVLNodeK *h = new AVLNodeK(data);
            root2 = new TreeKey(h);
        } else {
            root1->insert(num, data);
            root2->insert(data);
        }
        AVLNodeN *tmp1 = root1->search(num);
        AVLNodeK *tmp2 = root2->search(LOC_ID - 1);
        tmp1->same = tmp2;
        tmp2->same = tmp1;
    }
    void del_key(int k) {
        AVLNodeK *tmp2 = root2->search(k);
        AVLNodeN *tmp1 = tmp2->same;
        root1->del(tmp1);
        root2->del(tmp2);
    }
    void del_num(int n) {
        AVLNodeN *tmp1 = root1->search(n);
        AVLNodeK *tmp2 = tmp1->same;
        root1->del(tmp1);
        root2->del(tmp2);
    }
};

void DELETE(AVLNodeK*& p)
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
void DELETE(AVLNodeN*& p)
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
void print_1(AVLNodeK *r, int offset)
{
    if(r == nullptr) return;
    print_1(r->right, offset + 3);
    for(int i = 0; i < offset; i++)
        cout << "\t \t";
    r->print();
    print_1(r->left, offset + 3);
}
void print_1(AVLNodeN *r, int offset)
{
    if(r == nullptr) return;
    print_1(r->right, offset + 3);
    for(int i = 0; i < offset; i++)
        cout << "\t \t";
    r->print();
    print_1(r->left, offset + 3);
}

int main() {
    SuperList S;
    S.insert(-1, 0);
    vector<int> V(1,-1);

    for(int i = 0; i<10000; ++i)
    {
        int k = rand()%V.size();
        int d = rand();
        S.insert(d, k);
        V.insert(k+V.begin(), d);
    }

    for(int i = 0; i<10000; ++i)
    {
        if(V[i]!=S.search_num(i)->data)
        {
            cout<<"Error! find"<<endl;
        }
    }

    for(int i = 0; i<10000; ++i)
    {
        S.del_num(rand()%(10000-i));
    }
    return 0;
}