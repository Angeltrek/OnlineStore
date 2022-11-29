#ifndef SELLER_H
#define SELLER_H

#pragma once
#include <string>
#include "Users.h"
#include "Product.h"

class Seller : public Users {
private:
	Product products[100];
	int index = 0;
	std::string store_address;
	float earnings;
	bool license = false;
public:

	//Builders
	Seller(): Users(), store_address(), earnings(), license(){}

	Seller(std::string _email, std::string _password, std::string _name, std::string _last_name, std::string _store_address, float _earnings, bool _license) :
		Users(_email, _password, _name, _last_name)
	{
		store_address = _store_address;
		earnings = _earnings;
		license = _license;
	}

	//Setters
	void set_license(bool);
	void set_earnings(float);
	void set_amount(int, int);

	//Getters
	float get_earnings();
	Product get_product(int);
	std::string get_name();

	//Functions
	void add_product(int, std::string, std::string, float, int);
	void show_products();
};

//Setters
void Seller::set_license(bool _license) {
	license = _license;
}

void Seller::set_earnings(float _earnings) {
	earnings += _earnings;
}

void Seller::set_amount(int _id, int _amount) {
	for (int i = 0; i < index; i++) {
		if (products[i].get_id() == _id) {
			products[i].set_amount(products[i].get_amount() - _amount);
		}
	}
}

//Getters

float Seller::get_earnings() {
	return earnings;
}

Product Seller::get_product(int _id) {
	for (int i = 0; i < index; i++) {
		if (products[i].get_id() == _id) {
			return products[i];
		}
	}
}

std::string Seller::get_name() {
	return name;
}

//Functions

void Seller::add_product(int _id, std::string _category, std::string _name, float _price, int _amount) {
	Product p(_id, _category, _name, _price, _amount);
	products[index] = p;
	index += 1;
}

void Seller::show_products() {
	for (int i = 0; i < index; i++) {
		std::cout << "ID: " << products[i].get_id() << " Producto: " << products[i].get_name() <<
			" Cantidad: " << products[i].get_amount() << " Precio: " << products[i].get_price() << "\n";
	}
}
#endif