#pragma once
#include <exception>  

class ParsingException : public std::exception {
public:
    ParsingException(const char* message = "[Parsing] 잘못된 json 형식입니다.") : std::exception(message) {}
};
