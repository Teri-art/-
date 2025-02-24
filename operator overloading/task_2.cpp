#include <iostream>
#include <cmath>

class Fraction
{
private:
    int numerator_;
    int denominator_;

public:
    Fraction(int numerator = 0, int denominator = 1)
    {
        while (denominator == 0)
        {
            std::cout << "Denominator cannot be zero. Enter a valid denominator: ";
            std::cin >> denominator;
        }
        numerator_ = numerator;
        denominator_ = denominator;
    }

    Fraction operator+(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_ + other.numerator_ * denominator_, denominator_ * other.denominator_);
    }

    Fraction operator-(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_ - other.numerator_ * denominator_, denominator_ * other.denominator_);
    }

    Fraction operator*(const Fraction& other) const
    {
        return Fraction(numerator_ * other.numerator_, denominator_ * other.denominator_);
    }

    Fraction operator/(const Fraction& other) const
    {
        return Fraction(numerator_ * other.denominator_, denominator_ * other.numerator_);
    }

    Fraction& operator++()
    {
        numerator_ += denominator_;
        return *this;
    }

    Fraction operator++(int)
    {
        Fraction temp = *this;
        ++(*this);
        return temp;
    }

    Fraction& operator--()
    {
        numerator_ -= denominator_;
        return *this;
    }

    Fraction operator--(int)
    {
        Fraction temp = *this;
        --(*this);
        return temp;
    }

    friend std::ostream& operator<<(std::ostream& out, const Fraction& fraction);
    friend std::istream& operator>>(std::istream& in, Fraction& fraction);
};

std::ostream& operator<<(std::ostream& out, const Fraction& fraction)
{
    out << fraction.numerator_ << "/" << fraction.denominator_;
    return out;
}

std::istream& operator>>(std::istream& in, Fraction& fraction)
{
    in >> fraction.numerator_ >> fraction.denominator_;
    while (fraction.denominator_ == 0)
    {
        std::cout << "Denominator cannot be zero. Enter a valid denominator: ";
        in >> fraction.denominator_;
    }
    return in;
}

int main()
{
    Fraction f1, f2;
    std::cout << "Enter fraction 1 (numerator and denominator): ";
    std::cin >> f1;
    std::cout << "Enter fraction 2 (numerator and denominator): ";
    std::cin >> f2;

    std::cout << f1 << " + " << f2 << " = " << (f1 + f2) << '\n';
    std::cout << f1 << " - " << f2 << " = " << (f1 - f2) << '\n';
    std::cout << f1 << " * " << f2 << " = " << (f1 * f2) << '\n';
    std::cout << f1 << " / " << f2 << " = " << (f1 / f2) << '\n';

    std::cout << "++" << f1 << " * " << f2 << " = " << (++f1 * f2) << '\n';
    std::cout << "Value of fraction 1 after prefix increment = " << f1 << '\n';

    std::cout << f1 << "-- * " << f2 << " = " << (f1-- * f2) << '\n';
    std::cout << "Value of fraction 1 after postfix decrement = " << f1 << '\n';

    return 0;
}