#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H

#pragma once
#include <string>

class Credit_card {
private:
	std::string number;
	std::string cvv;
	std::string expiration;
	float money;

public:
	//Builders
	Credit_card() : number(), cvv(), expiration(), money(){}

	Credit_card(std::string _number, std::string _cvv, std::string _expiration, float _money) :
		number(_number), cvv(_cvv), expiration(_expiration), money(_money){}

	//Setters
	void set_money(float);

	//Getters
	float get_money();
};

//Setters
void Credit_card::set_money(float _money) {
	money = _money;
}

//Getters
float Credit_card::get_money() {
	return money;
}
#endif