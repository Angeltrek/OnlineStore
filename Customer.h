#ifndef CUSTOMER_H
#define CUSTOMER_H

#pragma once
#include <string>
#include <iostream>
#include "Users.h"
#include "Credit_card.h"
#include "Shopping_cart.h"

class Customer: public Users{
private:
	std::string address;
	Credit_card credit_card;
	Shopping_cart shopping_cart;
	int index = 0;
public:
	//Builders
	Customer() : Users(), address(), credit_card() {}

	Customer(std::string _email, std::string _password, std::string _name, std::string _last_name, std::string _address, 
		std::string _number, std::string _cvv, std::string _expiration, float _money) :
		Users(_email, _password, _name, _last_name), address(_address), 
		credit_card(_number, _cvv, _expiration, _money), shopping_cart() {}

	//Getters
	Shopping_cart get_shopping();
	std::string get_email();
	std::string get_password();

	//Functions
	void add_to_cart(Product, int);
	void show_shopping();
	float check_out();
};

//Getters
Shopping_cart Customer::get_shopping() {
	return shopping_cart;
}

std::string Customer::get_email() {
	return email;
}

std::string Customer::get_password() {
	return password;
}

//Functions
void Customer::add_to_cart(Product product, int _quantity) {
	if (_quantity <= product.get_amount() && product.get_amount() > 0) {
		shopping_cart.set_products(product.get_name(), index);
		shopping_cart.set_cost(product.get_price(), index);
		shopping_cart.set_quantity(_quantity, index);
		index += 1;
		shopping_cart.set_index(index);
	}
	else {
		std::cout << "No hay productos disponibles";
	}
}

void Customer::show_shopping() {
	for (int i = 0; i < index; i++) {
		std::cout << "Producto: " << shopping_cart.get_products(i) << " Cantidad: "
			<< shopping_cart.get_quantity(i) << " Precio: " << shopping_cart.get_cost(i) << "\n";
	}
	std::cout << "Total: " << shopping_cart.get_final() << "\n";
}

float Customer::check_out() {
	float total = shopping_cart.get_final();
	credit_card.set_money(credit_card.get_money() - total);
	return total;
}

#endif