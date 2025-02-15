#include <iostream>
#include <string>

class Figure {
public:
    virtual int get_sides_count() const {
        return 0;
    }
    virtual std::string get_name() const {
        return "Figure";
    }
    virtual bool is_valid() const {
        return true;
    }
    virtual void print_info() const {
        std::cout << get_name() << ":\n";
        std::cout << (is_valid() ? "Correct" : "Incorrect") << "\n";
        std::cout << "Number of sides: " << get_sides_count() << "\n";
    }
    virtual ~Figure() = default;
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;

public:
    Triangle(int a, int b, int c, int A, int B, int C)
        : a(a), b(b), c(c), A(A), B(B), C(C) {}

    int get_sides_count() const override {
        return 3;
    }
    std::string get_name() const override {
        return "Triangle";
    }
    bool is_valid() const override {
        return (A + B + C) == 180;
    }
    void print_info() const override {
        Figure::print_info();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << "\n";
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << "\n";
    }
};

class RectangularTriangle : public Triangle {
public:
    RectangularTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {}

    std::string get_name() const override {
        return "Rectangular Triangle";
    }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {}

    std::string get_name() const override {
        return "Isosceles Triangle";
    }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60) {}

    std::string get_name() const override {
        return "Equilateral Triangle";
    }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;

public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D)
        : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {}

    int get_sides_count() const override {
        return 4;
    }
    bool is_valid() const override {
        return (A + B + C + D) == 360;
    }
    std::string get_name() const override {
        return "Quadrangle";
    }
    void print_info() const override {
        Figure::print_info();
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << "\n";
        std::cout << "Angles: A=" << A << " B=" << B << " C=" << C << " D=" << D << "\n";
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b)
        : Quadrangle(a, b, a, b, 90, 90, 90, 90) {}

    std::string get_name() const override {
        return "Rectangle";
    }
};

class Square : public Rectangle {
public:
    Square(int a)
        : Rectangle(a, a) {}

    std::string get_name() const override {
        return "Square";
    }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B)
        : Quadrangle(a, b, a, b, A, B, A, B) {}

    std::string get_name() const override {
        return "Parallelogram";
    }
};

class Rhombus : public Parallelogram {
public:
    Rhombus(int a, int A, int B)
        : Parallelogram(a, a, A, B) {}

    std::string get_name() const override {
        return "Rhombus";
    }
};

int main() {
    Figure* figures[] = {
        new Triangle(10, 20, 30, 50, 60, 70),
        new RectangularTriangle(10, 20, 30, 50, 40),
        new IsoscelesTriangle(10, 20, 50, 60),
        new EquilateralTriangle(30),
        new Quadrangle(10, 20, 30, 40, 50, 60, 70, 80),
        new Rectangle(10, 20),
        new Square(20),
        new Parallelogram(20, 30, 30, 40),
        new Rhombus(30, 30, 40)
    };

    for (Figure* f : figures) {
        f->print_info();
        std::cout << "\n";
        delete f;
    }

    return 0;
}
