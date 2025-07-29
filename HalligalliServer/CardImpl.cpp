#include "CardImpl.h"
CardImpl::CardImpl(int card_num) {

	this->card_num = card_num;

	// 1~5 사과, 6~10 바나나, 11~15 포도, 16~20 수박
	switch ((card_num-1) / 5) {
	case 0:
		this->fruit = Fruit::APPLE;
		break;
	case 1:
		this->fruit = Fruit::BANANA;
		break;
	case 2:
		this->fruit = Fruit::GRAPE;
		break;
	default:
		this->fruit = Fruit::WATERMELON;
		break;
	}
	this->fruit_cnt = ((card_num - 1) % 5) + 1;

}
CardImpl::~CardImpl() {}

Fruit
CardImpl:: getFruit() {
	return this->fruit;
}

int
CardImpl:: getFruitCnt() {
	return this->fruit_cnt;
}

int
CardImpl::getCardNum() {

	return this->card_num;

}