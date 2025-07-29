#pragma once
#include "ISocketCreator.h"

template <typename T>
class TcpSocketCreator : ISocketCreator {

public:
	virtual Socket<T> createSocket()override;

};