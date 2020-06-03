#include <iostream>

using namespace std;

template<class T>
struct Matrix {
    T a11, a12, a21, a22;
    Matrix(T a111, T a121, T a211, T a221) : a11(a111), a12(a121), a21(a211), a22(a221) {}

    Matrix operator*(Matrix x)
    {
        return Matrix(a11 * x.a11 + a12 * x.a21, a11 * x.a12 + a12 * x.a22, a21 * x.a11 + a22 * x.a21, a21 * x.a12 + a22 * x.a22);
    }

    Matrix operator^(T x)
    {
        Matrix A(a11, a12, a21, a22);
        if (x == 1)
            return A;
        else if (x % 2 == 0)
            return operator^(x / 2) * operator^(x / 2);
        else
            return A * operator^(x - 1);
    }
};

long long int fib(long long int n)
{
    Matrix<long long int> P(0,1,1,1);
    P = P^n;
    long long int f = P.a21;
    return f;
}

long long int fibfinal(long long int n, int m)
{
    return fib(n) % m;
}

int main()
{
    long long int n;
    int m;
    cin >> n >> m;
    cout << fibfinal(n, m) << endl;

    return 0;
}