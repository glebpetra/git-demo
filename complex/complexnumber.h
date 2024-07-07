#ifndef COMPLEXNUMBER_H
#define COMPLEXNUMBER_H
#include <QString>
using namespace std;

// bool is_symb(QChar a)
// {
//     QString symb = "+-=*/^";
//     unsigned int i = 0;
//     while (i != symb.size())
//     {
//         if (a == symb[i])
//             return 1;
//         i = i+1;
//     }
//     return 0;
// }



class ComplexNumber
{
public:
    ComplexNumber(double real, double imaginary) : m_real(real), m_imaginary(imaginary) {}
    ComplexNumber() : m_real(0), m_imaginary(0) {}
    ComplexNumber(double real) : m_real(real), m_imaginary(0) {}

    double getReal() const { return m_real; }
    double getImaginary() const { return m_imaginary; }
    void setReal(double real);
    void setImaginary(double imaginary);

    ComplexNumber operator+(const ComplexNumber& other) const;
    ComplexNumber operator-(const ComplexNumber& other) const;
    ComplexNumber operator*(const ComplexNumber& other) const;
    // friend QString& operator>>(QString& in, ComplexNumber& any)
    // {
    //     unsigned int i = 0;
    //     while (!is_symb())

    //     return in;
    // }
    QString toString() const;

private:
    double m_real;
    double m_imaginary;
};

#endif // COMPLEXNUMBER_H
