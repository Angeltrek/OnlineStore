#ifndef PRODUCT_H
#define PRODUCT_H

#pragma once
#include <string>

class Product {
private:
	int id = 0;
	std::string category = "";
	std::string name = "";
	float price = 0.0;
	int amount = 0;
public:
	//Builders
	Product() : id(), category(), name(), price(), amount() {}

	Product(int _id, std::string _category, std::string _name, float _price, int _amount): 
		id(_id), category(_category), name(_name), price(_price), amount(_amount){}

	//Setters
	void set_id(int);
	void set_category(std::string);
	void set_name(std::string);
	void set_price(float);
	void set_amount(int);

	//Getters
	int get_id();
	std::string get_category();
	std::string get_name();
	float get_price();
	int get_amount();
};

//Setters
void Product::set_id(int _id) {
	id = _id;
}

void Product::set_category(std::string _category) {
	category = _category;
}

void Product::set_name(std::string _name) {
	name = _name;
}

void Product::set_price(float _price) {
	price = _price;
}

void Product::set_amount(int _amount) {
	amount = _amount;
}

//Getters

int Product::get_id() {
	return id;
}

std::string Product::get_category() {
	return category;
}

std::string Product::get_name() {
	return name;
}

float Product::get_price() {
	return price;
}

int Product::get_amount() {
	return amount;
}
#endif