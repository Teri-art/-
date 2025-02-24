#pragma once
#ifndef INVALID_FIGURE_EXCEPTION_H
#define INVALID_FIGURE_EXCEPTION_H

#include <stdexcept>
#include <string>

class InvalidFigureException : public std::domain_error {
public:
    explicit InvalidFigureException(const std::string& message)
        : std::domain_error("Invalid Figure: " + message) {}
};

#endif // INVALID_FIGURE_EXCEPTION_H
