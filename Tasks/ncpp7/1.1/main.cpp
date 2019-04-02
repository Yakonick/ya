#include <iostream>

using namespace std;

template <class T>
class Complex
{
    T Real, Imagine;
public:
    Complex(T x = 0, T y = 0): Real(x), Imagine(y) {}
    Complex<T> operator+(Complex<T> c)
    {
        return Complex<T>(Real + c.Real, Imagine + c.Imagine);
    }
    Complex<T> operator-()
    {
        return Complex<T>(-Real, -Imagine);
    }
    Complex<T> operator-(Complex<T> c)
    {
        return Complex<T>(Real - c.Real, Imagine - c.Imagine);
    }
    Complex<T> operator!()
    {
        return Complex<T>(Real, -Imagine);
    }
    Complex<T> operator*(Complex<T> c)
    {
        return Complex<T>(Real * c.Real - Imagine * c.Imagine, Real * c.Imagine + Imagine * c.Real);
    }
    Complex<T> operator/(Complex<T> c)
    {
        return Complex<T>((Real * c.Real + Imagine * c.Imagine) / (c.Real * c.Real + c.Imagine * c.Imagine), (Real * c.Imagine - Imagine * c.Real) / (c.Real * c.Real + c.Imagine * c.Imagine));
    }
};
