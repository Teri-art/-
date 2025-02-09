#include <iostream>
#include <string>

using namespace std;

class Figure {
protected:
    int side_Triangle = 3;
    int side_Quadrangle = 4;
public:
    virtual int get_sides_count() = 0;
};

class Triangle : public Figure {
public:
    void get_sides_count Triangle() {
        return 3;
    }
};
class Quadrangle : public Figure {

public:
    void get_sides_count Quadrangle() {
                return 4;
    }
};

int main()
{
    cout << "Number of sides:" << endl;

    Figure figure;
    Triangle triangle;
    Quadrangle quadrangle;
    std::cout << "Number of triangle sides: " << triangle.get_sides_count() << std::endl;
    std::cout << "Number of sides of a quadrilateral " << quadrangle.get_sides_count() << std::endl;
    return 0;
}
