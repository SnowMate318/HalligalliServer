#pragma once
#include "ICard.h"

class IFrontCards {
	
private:

	virtual void updateCard(int playerId, ICard* card) = 0;
	virtual void resetCard(int playerId) = 0;
	virtual bool checkFiveFruit() = 0;

};