#include "complexnumber.h"

ComplexNumber ComplexNumber::operator+(const ComplexNumber& other) const
{
    return ComplexNumber(m_real + other.m_real, m_imaginary + other.m_imaginary);
}

ComplexNumber ComplexNumber::operator-(const ComplexNumber& other) const
{
    return ComplexNumber(m_real - other.m_real, m_imaginary - other.m_imaginary);
}

ComplexNumber ComplexNumber::operator*(const ComplexNumber& other) const
{
    return ComplexNumber(m_real * other.m_real - m_imaginary * other.m_imaginary,
                         m_real * other.m_imaginary + m_imaginary * other.m_real);
}

QString ComplexNumber::toString() const
{
    if (m_imaginary == 0)
        return QString("%1").arg(m_real);
    else if (m_imaginary < 0)
        return QString("%1%2i").arg(m_real).arg(m_imaginary);
    else
        return QString("%1+%2i").arg(m_real).arg(m_imaginary);
}

void ComplexNumber::setReal(double real)
{
    this->m_real = real;
}

void ComplexNumber::setImaginary(double imaginary)
{
    this->m_imaginary = imaginary;
}
