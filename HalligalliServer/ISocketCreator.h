#pragma once  
#include "ISocket.h"  

template <typename T>  
class ISocketCreator {  

public:
	virtual ISocket<T> createSocket() = 0;  

};