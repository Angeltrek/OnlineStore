/*
 * Proyecto OnlineStore
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 01/12/2022
 */

 /*
  * Clase Product contiene métodos para crear
  * productos con un id, una categoria, su nombre,
  * su precio y su cantidad
  */

#ifndef PRODUCT_H
#define PRODUCT_H

#pragma once
#include <string>

class Product {
private:
	//Variables iniciales
	int id = 0;
	std::string category = "";
	std::string name = "";
	float price = 0.0;
	int amount = 0;
public:
	//Constructor
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

/**
 * Asigna un nuevo ID a la variable
 * id
 *
 * @param
 * @return
*/

void Product::set_id(int _id) {
	id = _id;
}

/**
 * Asigna una nueva categoria a la
 * variable category
 *
 * @param
 * @return
*/

void Product::set_category(std::string _category) {
	category = _category;
}

/**
 * Asigna un nuevo nombre al 
 * producto en la variable
 * name
 *
 * @param
 * @return
*/

void Product::set_name(std::string _name) {
	name = _name;
}

/**
 * Asigna un nuevo precio al producto
 * en la variable price
 *
 * @param
 * @return
*/

void Product::set_price(float _price) {
	price = _price;
}

/**
 * Asigna una nueva cantidad
 * del mismo producto en la variable
 * amount
 *
 * @param
 * @return
*/

void Product::set_amount(int _amount) {
	amount = _amount;
}

//Getters

/**
 * Obtiene el id del producto
 *
 * @param
 * @return id
*/

int Product::get_id() {
	return id;
}

/**
 * Obtiene la categoria 
 * del producto
 *
 * @param
 * @return category
*/

std::string Product::get_category() {
	return category;
}

/**
 * Obtiene el nombre
 * del producto
 *
 * @param
 * @return name
*/

std::string Product::get_name() {
	return name;
}

/**
 * Obtiene el precio
 * del producto
 *
 * @param
 * @return price
*/

float Product::get_price() {
	return price;
}

/**
 * Obtiene la cantidad
 * del producto
 *
 * @param
 * @return amount
*/

int Product::get_amount() {
	return amount;
}
#endif //PRODUCT_H