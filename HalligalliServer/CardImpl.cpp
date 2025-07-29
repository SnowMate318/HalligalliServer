#include "CardImpl.h"

CardImpl::CardImpl(int card_num) {

	// 1~5 사과, 6~10 바나나, 11~15 포도, 16~20 수박
	switch ((card_num-1) / 5) {
	case 3:
		this->fruit = Fruit::APPLE;
		break;
	case 2:
		this->fruit = Fruit::BANANA;
		break;
	case 1:
		this->fruit = Fruit::GRAPE;
		break;
	default:
		this->fruit = Fruit::WATERMELON;
		break;
	}
	this->fruit_cnt = ((card_num - 1) % 5) + 1;
}
CardImpl::~CardImpl() {}

int
CardImpl::getCardNum() {

	int ret = this->fruit_cnt;
	ret += this->fruit;
	return ret;

}