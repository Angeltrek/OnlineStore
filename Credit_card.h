/*
 * Proyecto OnlineStore
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 01/12/2022
 */

 /*
  * Clase Credit_card contiene los datos
  * necesarios para una tarjeta de credito.
  */

#ifndef CREDIT_CARD_H
#define CREDIT_CARD_H

#pragma once
#include <string>

class Credit_card {
private:
	//Variables iniciales
	std::string number;
	std::string cvv;
	std::string expiration;
	float money;

public:
	//Constructor
	Credit_card() : number(), cvv(), expiration(), money(){}

	Credit_card(std::string _number, std::string _cvv, std::string _expiration, float _money) :
		number(_number), cvv(_cvv), expiration(_expiration), money(_money){}

	//Setters
	void set_money(float);

	//Getters
	float get_money();
};

//Setters

/**
 * Actualiza el dinero que se tiene 
 * en la tarjeta de credito
 *
 * @param
 * @return
*/

void Credit_card::set_money(float _money) {
	money = _money;
}

/**
 * Retorna el dinero que se tiene
 * registrado en la tarjeta de credito
 *
 *
 * @return money
*/

//Getters
float Credit_card::get_money() {
	return money;
}
#endif //CREDIT_CARD_H