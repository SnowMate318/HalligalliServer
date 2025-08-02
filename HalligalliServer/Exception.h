#pragma once  
#include <exception>  

class Exception : public std::exception {  
public:  
    Exception(const char* message = "An error occurred") : std::exception(message) {}  
};
#include "Exception.h"
