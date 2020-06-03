#include <list>

using namespace std;

struct Set
{
    list<int> a;

    Set(list<int> aa) : a(aa) {}
};

    Set Combination(Set A, Set B)
    {
        list<int>::iterator i = A.a.end(), j, k;
        for (j = A.a.begin(); j != A.a.end(); j++)
        {
            for (k = B.a.begin(); k != B.a.end(); k++)
            {
                if (*j == *k)
                    B.a.erase(k);
            }
        }
        for (auto &x: B.a)
            A.a.insert(i ,x);
        return A;
    }

    Set Intersection(Set A, Set B)
    {
        list<int> Temp;
        list<int>::iterator i = A.a.end(), j, k;
        for (j = A.a.begin(); j != A.a.end(); j++) {
            for (k = B.a.begin(); k != B.a.end(); k++) {
                if (*j == *k)
                    Temp.insert(i, *j);
            }
        }
        A.a = Temp;
        return A;
    }

    Set Difference(Set A, Set B)
    {
        list<int>::iterator j, k;
        for (j = A.a.begin(); j != A.a.end(); j++) {
            for (k = B.a.begin(); k != B.a.end();) {
                if (*j == *k) {
                    B.a.erase(k);
                    A.a.erase(j);
                    k = B.a.begin();
                } else {
                    k++;
                }
            }
        }
    }

    Set &Create_One(int x)
    {
        list<int> Temp;
        Temp.insert(Temp.end(), x);
        Set A(Temp);
        return A;
    }

    bool Affilation_One(int x, Set A)
    {
        for (auto y: A.a)
        {
            if (x == y)
                return true;
        }
        return false;
    }

    bool Affilation_All(Set A, Set B)
    {
        list<int>::iterator j, k;
        for (j = A.a.begin(); j != A.a.end(); j++) {
            for (k = B.a.begin(); k != B.a.end();) {
                if (*j == *k) {
                    B.a.erase(k);
                    A.a.erase(j);
                    k = B.a.begin();
                } else {
                    k++;
                }
            }
        }
        return B.a.empty();
    }
