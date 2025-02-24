
#include <iostream>
#include <stdexcept>
#include <string>

class InvalidFigureException : public std::runtime_error {
public:
    explicit InvalidFigureException(const std::string& message)
        : std::runtime_error("Invalid Figure: " + message) {}
};

class Figure {
public:
    virtual std::string get_name() const = 0;
    virtual void print_info() const = 0;
    virtual ~Figure() = default;
};

class Triangle : public Figure {
protected:
    int a, b, c;
    int A, B, C;
public:
    Triangle(int a, int b, int c, int A, int B, int C) : a(a), b(b), c(c), A(A), B(B), C(C) {
        if (A + B + C != 180) {
            throw InvalidFigureException("Sum of angles in a triangle must be 180");
        }
    }
    std::string get_name() const override { return "Triangle"; }
    void print_info() const override {
        std::cout << get_name() << ": a=" << a << " b=" << b << " c=" << c;
        std::cout << " A=" << A << " B=" << B << " C=" << C << std::endl;
    }
};

class RectangularTriangle : public Triangle {
public:
    RectangularTriangle(int a, int b, int c, int A, int B)
        : Triangle(a, b, c, A, B, 90) {
        if (C != 90) {
            throw InvalidFigureException("A right triangle must have one 90-degree angle.");
        }
    }
    std::string get_name() const override { return "Rectangular Triangle"; }
};

class IsoscelesTriangle : public Triangle {
public:
    IsoscelesTriangle(int a, int b, int A, int B)
        : Triangle(a, b, a, A, B, A) {
        if (a != c || A != C) {
            throw InvalidFigureException("An isosceles triangle must have two equal sides and two equal angles.");
        }
    }
    std::string get_name() const override { return "Isosceles Triangle"; }
};

class EquilateralTriangle : public Triangle {
public:
    EquilateralTriangle(int a)
        : Triangle(a, a, a, 60, 60, 60) {
        if (a != b || b != c || A != 60 || B != 60 || C != 60) {
            throw InvalidFigureException("An equilateral triangle must have all sides and angles equal to 60 degrees.");
        }
    }
    std::string get_name() const override { return "Equilateral Triangle"; }
};

class Quadrangle : public Figure {
protected:
    int a, b, c, d;
    int A, B, C, D;
public:
    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : a(a), b(b), c(c), d(d), A(A), B(B), C(C), D(D) {
        if (A + B + C + D != 360) {
            throw InvalidFigureException("Sum of angles in a quadrangle must be 360");
        }
    }
    std::string get_name() const override { return "Quadrangle"; }
    void print_info() const override {
        std::cout << get_name() << ": a=" << a << " b=" << b << " c=" << c << " d=" << d;
        std::cout << " A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
};

class Rectangle : public Quadrangle {
public:
    Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
        if (A != 90 || B != 90 || C != 90 || D != 90 || a != c || b != d) {
            throw InvalidFigureException("A rectangle must have opposite sides equal and all angles 90 degrees.");
        }
    }
    std::string get_name() const override { return "Rectangle"; }
};

class Square : public Quadrangle {
public:
    Square(int a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
        if (a != b || b != c || c != d || A != 90 || B != 90 || C != 90 || D != 90) {
            throw InvalidFigureException("A square must have all sides equal and all angles 90 degrees.");
        }
    }
    std::string get_name() const override { return "Square"; }
};

class Parallelogram : public Quadrangle {
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
        if (a != c || b != d || A != C || B != D) {
            throw InvalidFigureException("A parallelogram must have opposite sides and opposite angles equal.");
        }
    }
    std::string get_name() const override { return "Parallelogram"; }
};

class Rhombus : public Quadrangle {
public:
    Rhombus(int a, int A, int B) : Quadrangle(a, a, a, a, A, B, A, B) {
        if (a != b || b != c || c != d || A != C || B != D) {
            throw InvalidFigureException("A rhombus must have all sides equal and opposite angles equal.");
        }
    }
    std::string get_name() const override { return "Rhombus"; }
};

int main() {
    try {
        Triangle t(10, 20, 30, 50, 60, 70);
        t.print_info();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    try {
        Rectangle r(10, 20);
        r.print_info();
    }
    catch (const std::exception& e) {
        std::cerr << e.what() << std::endl;
    }

    return 0;
}
int main() {
    Figure* figures[] = {
        new Triangle(10, 20, 30, 50, 60, 70),
        new RectangularTriangle(10, 20, 25, 50, 40),
        new IsoscelesTriangle(10, 20, 50, 60),
        new EquilateralTriangle(30),
        new Quadrangle(10, 20, 30, 40, 50, 60, 70, 80),
        new Rectangle(10, 20),
        new Square(20),
        new Parallelogram(20, 30, 30, 40),
        new Rhombus(30, 30, 40)
    };

    std::cout << "=== Creating Figures ===\n";

    for (Figure* fig : figures) {
        try {
            fig->print_info();
            std::cout << "Successfully created: " << fig->get_name() << "\n\n";
        }
        catch (const std::exception& e) {
            std::cerr << "Error: " << e.what() << "\n\n";
        }
    }

    // Очистка памяти
    for (Figure* fig : figures) {
        delete fig;
    }

    return 0;
}
