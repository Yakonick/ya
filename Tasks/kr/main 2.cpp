#include <iostream>
#include <fstream>
#include <string>
#include "Main_Struct.h"

using namespace std;


struct Const : BoolExpr
{
    bool a;
    Const(bool x) : a(x) {}

    bool operator==(const BoolExpr &x) const override
    {
        return x == *this;
    }
    bool operator==(const Const &x) const override
    {
        return a == x.a;
    }
    bool operator==(const Var &x) const override
    {
        return false;
    }


    void PrintInFile(string NameOfFile) override
    {
        ofstream File(NameOfFile, ios::app | ios::out);
        File << a << " ";
        File.close();
    }
    BoolExpr * Simplification() override
    {
        if (a == 1)
            return new Const(1);
        else
            return new Const(0);
    }
};

struct Var : BoolExpr
{
    bool operator==(const BoolExpr &x) const override
    {
        return x == *this;
    }
    bool operator==(const Const &x) const override
    {
        return false;
    }
    bool operator==(const Var &x) const override
    {
        return false;
    }


    void PrintInFile(string NameOfFile) override
    {
        ofstream File(NameOfFile, ios::app | ios::out);
        File << "x ";
        File.close();
    }
    BoolExpr * Simplification() override { return new Var(); }
};

struct Not : BoolExpr
{
    BoolExpr *a;
    Not(BoolExpr *aa) : a(aa) {}

    bool operator==(const BoolExpr &x) const override
    {
        return x == *this;
    }
    bool operator==(const Const &x) const override
    {
        return false;
    }
    bool operator==(const Var &x) const override
    {
        return false;
    }


    void PrintInFile(string NameOfFile) override
    {
        char Temp = 172;
        ofstream File(NameOfFile, ios::app | ios::out);
        File << Temp;
        File.close();
        a->PrintInFile(NameOfFile);
    }
    BoolExpr * Simplification() override
    {
        if (*(a->Simplification()) == Const(1))
            return new Const(0);
        else if (*(a->Simplification()) == Const(0))
            return new Const(1);
    }
};

struct Or : BoolExpr
{
    BoolExpr *a, *b;
    Or(BoolExpr *aa, BoolExpr *bb) : a(aa), b(bb) {}

    bool operator==(const BoolExpr &x) const override
    {
        return x == *this;
    }
    bool operator==(const Const &x) const override
    {
        return false;
    }
    bool operator==(const Var &x) const override
    {
        return false;
    }


    void PrintInFile(string NameOfFile) override
    {
        char Temp = 124;
        ofstream File(NameOfFile, ios::app | ios::out);
        a->PrintInFile(NameOfFile);
        File << Temp << " ";
        File.close();
        b->PrintInFile(NameOfFile);
    }
    BoolExpr * Simplification() override
    {
        if (*(a->Simplification()) == Const(0))
            return b->Simplification();
        else if (*(b->Simplification()) == Const(0))
            return a->Simplification();
        else if ((*(a->Simplification()) == Const(1)) || (*(b->Simplification()) == Const(1)))
            return new Const(1);
    }
};

struct And : BoolExpr
{
    BoolExpr *a, *b;
    And(BoolExpr *aa, BoolExpr*bb) : a(aa), b(bb) {}

    bool operator==(const BoolExpr &x) const override
    {
        return x == *this;
    }
    bool operator==(const Const &x) const override
    {
        return false;
    }
    bool operator==(const Var &x) const override
    {
        return false;
    }


    void PrintInFile(string NameOfFile) override
    {
        char Temp = 94;
        ofstream File(NameOfFile, ios::app | ios::out);
        a->PrintInFile(NameOfFile);
        File << Temp;
        File.close();
        b->PrintInFile(NameOfFile);
    }
    BoolExpr * Simplification() override
    {
        if (*(a->Simplification()) == Const(1))
            return b->Simplification();
        else if (*(b->Simplification()) ==  Const(1))
            return a->Simplification();
        else if ((*(a->Simplification()) ==  Const(0)) || (*(b->Simplification()) == Const(0)))
            return new Const(0);
    }
};

int main()
{
    Var x;
    Const a(0);
    Var *y = &x;
    Const *b = &a;
    And z(y,b);
    z.Simplification()->PrintInFile("File.txt");

    return 0;
}