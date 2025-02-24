#pragma once
#pragma once
#include <iostream>
#include <string>

class Figure {
public:
    virtual std::string get_name() const;
    virtual void print_info() const;
    virtual ~Figure() = default;
};