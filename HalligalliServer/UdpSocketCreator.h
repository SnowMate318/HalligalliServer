#pragma once
#include "ISocketCreator.h"

template <typename T>
class UdpSocketCreator : ISocketCreator{

public:
	virtual Socket<T> createSocket()override;

};