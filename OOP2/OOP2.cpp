
#include <iostream>
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
}
