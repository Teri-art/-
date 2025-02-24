#pragma once
#include "Figure.h"
#include "FigureException.h"

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;
public:
    Triangle(int a, int b, int c, int A, int B, int C);
    std::string get_name() const override;
    void print_info() const override;
};

class RectangularTriangle : public Triangle {
public:
    RectangularTriangle(int a, int b, int c, int A, int B);
    std::string get_name() const override;
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B);
    std::string get_name() const override;
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a);
    std::string get_name() const override;
};
#pragma once
