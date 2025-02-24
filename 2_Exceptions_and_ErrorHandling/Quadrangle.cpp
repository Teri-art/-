#include "Quadrangle.h"
#include <iostream>

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
    : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
    if (A + B + C + D != 360) {
        throw FigureCreationException("Сумма углов четырёхугольника должна быть 360 градусов.");
    }
}

std::string Quadrangle::get_name() const {
    return "Quadrangle";
}

void Quadrangle::print_info() const {
    std::cout << get_name() << ":\n";
    std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
    std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
}

Rectangle::Rectangle(int a, int b)
    : Quadrangle(a, b, a, b, 90, 90, 90, 90) {}

std::string Rectangle::get_name() const {
    return "Rectangle";
}

Square::Square(int a)
    : Quadrangle(a, a, a, a, 90, 90, 90, 90) {}

std::string Square::get_name() const {
    return "Square";
}

Parallelogram::Parallelogram(int a, int b, int A, int B)
    : Quadrangle(a, b, a, b, A, B, A, B) {
    if (A != C || B != D) {
        throw FigureCreationException("У параллелограмма противоположные углы должны быть равны.");
    }
}

std::string Parallelogram::get_name() const {
    return "Parallelogram";
}

Rhombus::Rhombus(int a, int A, int B)
    : Quadrangle(a, a, a, a, A, B, A, B) {
    if (a != b || a != c || a != d) {
        throw FigureCreationException("У ромба все стороны должны быть равны.");
    }
}

std::string Rhombus::get_name() const {
    return "Rhombus";
}
