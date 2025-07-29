#include "CardImpl.h"

CardImpl::CardImpl(int card_num) {

	// 1~5 ���, 6~10 �ٳ���, 11~15 ����, 16~20 ����
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