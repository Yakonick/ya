 #ifndef KR_MAIN_STRUCT_H
#define KR_MAIN_STRUCT_H

#include <string>

using namespace std;

struct Const;
struct Var;
struct Not;
struct Or;
struct And;


struct BoolExpr
{
    virtual ~BoolExpr() {}
    virtual void PrintInFile(string NameOfFile) = 0;
    virtual BoolExpr * Simplification() = 0;
    virtual bool operator==(const BoolExpr &) const = 0;
    virtual bool operator==(const Const &) const = 0;
    virtual bool operator==(const Var &) const = 0;
};
#endif //KR_MAIN_STRUCT_H
