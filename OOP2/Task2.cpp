#include <iostream>
#include <string>

using namespace std;

class Figure {
public:
    virtual std::string get_name() const {
        return "Фигура";
    }
    virtual void print_info() const {
        std::cout << get_name() << std::endl;
    }
    virtual ~Figure() = default;

};

/// <summary>
/// /треугольники  
/// </summary>
/// 
class Triangle : public Figure {     // общий
private:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {}
    string get_name() const override {
        return "Triangle:";
    }
    void print_info() const override {
        std::cout << get_name() << ":\n";
        std::cout << "Side: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << "\n";
    }
};
class RectangularTriangle : public Triangle {         ////////// 1

public:
    RectangularTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {}

    std::string get_name() const override {
        return "Rectangular Triangle";
    }
};
class IsoscelesTriangle : public Triangle {  ///////////////// 2

public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {}

    std::string get_name() const override {
        return "Isosceles Triangle";
    }
};
class EquilateralTriangle : public Triangle {        ////////// 3

public:
    EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60) {}

    std::string get_name() const override {
        return "Equilateral Triangle";
    }
};

/// <summary>
/// /квадраты 
/// </summary>

class Quadrangle : public Figure {       ////////// общий
protected:
    int a, b, c, d;
    int A, B, C, D;
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    std::string get_name() const override {
        return "Quadrangle";
    }

    void print_info() const override {
        std::cout << get_name() << ":\n";
        std::cout << "Side: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }
};

class Rectangle : public Quadrangle {       /////////// 1
public:
    Rectangle(int a, int b)
        : Quadrangle(a, b, a, b, 90, 90, 90, 90) {}

    std::string get_name() const override {
        return "Rectangle";
    }
};

class Square : public Quadrangle {                         ////////// 2
public:
    Square(int a)
        : Quadrangle(a, a, a, a, 90, 90, 90, 90) {}

    std::string get_name() const override {
        return "Square";
    }
};

class Parallelogram : public Quadrangle {              ////////// 3
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrangle(a, b, a, b, A, B, A, B) {}

    std::string get_name() const override {
        return "Parallelogram";
    }
};

class Rhombus : public Quadrangle {                        ////////// 4
public:
    Rhombus(int a, int A, int B)
        : Quadrangle(a, a, a, a, A, B, A, B) {}

    std::string get_name() const override {
        return "Rhombus";
    }
};

//  ФУНКЦИЯ ВЫВОДА ДАННЫХ 

void print_info(const Figure* figure) {
    figure->print_info();
    std::cout << std::endl;
}

//  MAIN
int main() {
    Triangle t(10, 20, 30, 50, 60, 70);
    RectangularTriangle rt(10, 20, 25, 50, 40);
    IsoscelesTriangle it(10, 20, 50, 60);
    EquilateralTriangle et(30);

    Quadrangle q(10, 20, 30, 40, 50, 60, 70, 80);
    Rectangle r(10, 20);
    Square s(20);
    Parallelogram p(20, 30, 30, 40);
    Rhombus rh(30, 30, 40);

    print_info(&t);
    print_info(&rt);
    print_info(&it);
    print_info(&et);

    print_info(&q);
    print_info(&r);
    print_info(&s);
    print_info(&p);
    print_info(&rh);

    return 0;
}