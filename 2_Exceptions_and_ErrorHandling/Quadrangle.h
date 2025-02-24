#pragma once
#pragma once
#include "Figure.h"
#include "FigureException.h"

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D);
    std::string get_name() const override;
    void print_info() const override;
};

class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b);
    std::string get_name() const override;
};

class Square : public Quadrangle {
public:
    Square(int a);
    std::string get_name() const override;
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B);
    std::string get_name() const override;
};

class Rhombus : public Quadrangle {
public:
    Rhombus(int a, int A, int B);
    std::string get_name() const override;
};

