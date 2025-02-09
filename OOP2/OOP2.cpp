////////////////////////////             1           //////////////////// ///

/*#include <iostream>
#include <string>

using namespace std;

class Figure {
public:
    virtual int get_sides_count() const {
        return 0; 
    }
    virtual std::string get_name() const {
        return "Figure:";
    }
    virtual ~Figure() {}

};

class Triangle : public Figure {
public:
    int get_sides_count() {
        return 3;
    }
    std::string get_name() const override {
        return "Triangle:";
    }
};
class Quadrangle : public Figure {

public:
    int get_sides_count() {
        return 4;
    }
    std::string get_name() const override {
        return "Quadrangle:";
    }
};

int main()
{
    cout << "Number of sides:" << endl;

    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;
    
    std::cout << figure.get_name()  << figure.get_sides_count() << std::endl;
    std::cout << triangle.get_name()  << triangle.get_sides_count() << std::endl;
    std::cout << quadrangle.get_name()  << quadrangle.get_sides_count() << std::endl;

    return 0;
}*/

 

////////////////////////////             2            //////////////////// ///



/*#include <iostream>
#include <string>

using namespace std;

class Figure {
public:
    virtual std::string get_name() const {
        return "Фигура";
    }
    virtual void print_info () const {
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
        : Triangle (a, b, c, A, B, 90) {}
    
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
}*/


////////////////////////////             3            //////////////////// ///





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
