
#pragma once
#include <stdexcept>
#include <string>

class FigureCreationException : public std::runtime_error {
public:
    explicit FigureCreationException(const std::string& message)
        : std::runtime_error("Ошибка создания фигуры: " + message) {}
};
