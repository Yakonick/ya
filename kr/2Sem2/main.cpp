#include <iostream>

using namespace std;

template<class T>
struct Matrix
{
    T a11, a12, a21, a22;
    Matrix(T a111, T a121, T a211, T a221): a11(a111), a12(a121), a21(a211), a22(a221) {}
    Matrix operator+(Matrix x)
    {
        return x(a11 + x.a11, a12 + x.a12, a21 + x.a21, a22 + x.a22);
    }
    Matrix operator-(Matrix x)
    {
        return x(a11 - x.a11, a12 - x.a12, a21 - x.a21, a22 - x.a22);
    }
    Matrix operator*(Matrix x)
    {
        return x(a11 * x.a11 + a12 * x.a21, a11 * x.a12 + a12 * x.a22, a21 * x.a11 + a22 * x.a21, a21 * x.a12 + a22 * x.a22);
    }
    Matrix operator*(T x)
    {
        return Matrix(a11 * x, a12 * x, a21 * x, a22 * x);
    }
    T Det()
    {
        return (a11 * a22 - a12 * a21);
    }
    void Trans()
    {
        T temp = a12; a12 = a22; a22 = temp;
    }
    Matrix Inverse()
    {
        Matrix A(a22, -a12, -a21, a11);
        T x = a11 * a22 - a12 * a21;
        return (A * (1/x));
    }
    void Cin()
    {
        cin >> a11 >> a12 >> a21 >> a22;
    }
    void Cout()
    {
        cout << a11 << " " << a12 << endl;
        cout << a21 << " " << a22 << endl;
    }
};

int main()
{
    Matrix<double> A(1.0,2.0,3.0,4.0);
    A = A * 5.0;
    A.Cout();
    A.Cin();
    A.Inverse().Cout();
    return 0;
}