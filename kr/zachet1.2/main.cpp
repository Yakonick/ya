#include <iostream>
#include <string>

using namespace std;

struct RegExpr
{
    virtual ~RegExpr() {}
    virtual void Print() = 0;
};

struct SingleChar : RegExpr
{
    char a;
    void Print()
    {
        cout << a;
    }
};

struct Concat : RegExpr
{
    RegExpr *a, *b;
    void Print()
    {
        a->Print();
        cout << " ";
        b->Print();
    }
    ~Concat() { delete a; delete b; }
};

struct ChooseAlter : RegExpr
{
    RegExpr *a, *b;
    void Print()
    {
        a->Print();
        cout << "|";
        b->Print();
    }
    ~ChooseAlter() { delete a; delete b; }
};

struct Group : RegExpr
{
    RegExpr *b;
    void Print()
    {
        cout << "(";
        b->Print();
        cout << ")";
    }
    ~Group() { delete b; }
};

struct Star : RegExpr
{
    RegExpr *a;
    void Print()
    {
        a->Print();
        cout << "*";
    }
    ~Star() { delete a; }
};