#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#pragma once
#include <string>
#include <iostream>
#include "seller.h"

class Shopping_cart {
private:
	std::string products[100];
	float cost[100];
	int quantity[100];
	int index = 0;
public:
	//Builders
	Shopping_cart() : products(), cost(), quantity(){}

	//Setters
	void set_cost(float, int);
	void set_quantity(int, int);
	void set_products(std::string, int);
	void set_index(int);

	//Getters
	float get_final();
	std::string get_products(int);
	int get_quantity(int);
	float get_cost(int);
};

//Setters
void Shopping_cart::set_cost(float _cost, int index) {
	cost[index] = _cost;
}

void Shopping_cart::set_quantity(int _quantity, int index) {
	quantity[index] = _quantity;
}

void Shopping_cart::set_products(std::string _product, int index) {
	products[index] = _product;
}

void Shopping_cart::set_index(int _index) {
	index = _index;
}

//Getters
float Shopping_cart::get_final() {
	float final_cost = 0.0;
	for (int i = 0; i < index; i++) {
		final_cost += quantity[i] * cost[i];
	}

	return final_cost;
}

std::string Shopping_cart::get_products(int index) {
	return products[index];
}

int Shopping_cart::get_quantity(int index) {
	return quantity[index];
}

float Shopping_cart::get_cost(int index) {
	return cost[index];
}
#endif