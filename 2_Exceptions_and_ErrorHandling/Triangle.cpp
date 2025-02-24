#include "Triangle.h"
#include <iostream>

Triangle::Triangle(int a, int b, int c, int A, int B, int C)
    : a(a), b(b), c(c), A(A), B(B), C(C) {
    if (A + B + C != 180) {
        throw FigureCreationException("Сумма углов треугольника должна быть 180 градусов.");
    }
}

std::string Triangle::get_name() const {
    return "Triangle";
}

void Triangle::print_info() const {
    std::cout << get_name() << ":\n";
    std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << "\n";
    std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << "\n";
}

RectangularTriangle::RectangularTriangle(int a, int b, int c, int A, int B)
    : Triangle(a, b, c, A, B, 90) {
    if (C != 90) {
        throw FigureCreationException("Прямоугольный треугольник должен иметь угол C = 90°.");
    }
}

std::string RectangularTriangle::get_name() const {
    return "Rectangular Triangle";
}

IsoscelesTriangle::IsoscelesTriangle(int a, int b, int A, int B)
    : Triangle(a, b, a, A, B, A) {
    if (a != c || A != C) {
        throw FigureCreationException("Равнобедренный треугольник должен иметь две равные стороны и углы A, C.");
    }
}

std::string IsoscelesTriangle::get_name() const {
    return "Isosceles Triangle";
}

EquilateralTriangle::EquilateralTriangle(int a)
    : Triangle(a, a, a, 60, 60, 60) {
    if (A != 60 || B != 60 || C != 60 || a != b || b != c) {
        throw FigureCreationException("Равносторонний треугольник должен иметь все стороны и углы равными.");
    }
}

std::string EquilateralTriangle::get_name() const {
    return "Equilateral Triangle";
}
