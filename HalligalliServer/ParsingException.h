#pragma once
#include <exception>  

class ParsingException : public std::exception {
public:
    ParsingException(const char* message = "[Parsing] �߸��� json �����Դϴ�.") : std::exception(message) {}
};
