/*
 * Proyecto OnlineStore
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 01/12/2022
 */

 /*
  * Clase Shopping_cart contiene métodos para 
  * el registro de los productos que va adquiriendo
  * el cliente (Customer), considerando que
  * el ciente solo puede añadir 100 productos
  */

#ifndef SHOPPING_CART_H
#define SHOPPING_CART_H

#pragma once
#include <string>
#include <iostream>
#include "Seller.h"

class Shopping_cart {
private:
	//Variables iniciales
	std::string products[100];
	float cost[100];
	int quantity[100];
	int index = 0;
public:
	//Constructor
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

/**
 * Asigna el costo de un producto en el 
 * arreglo de cost[]
 *
 * @param
 * @return
*/

void Shopping_cart::set_cost(float _cost, int index) {
	cost[index] = _cost;
}

/**
 * Asigna la cantidad de un producto a comprar
 * en el arreglo de quantity[]
 *
 * @param
 * @return
*/

void Shopping_cart::set_quantity(int _quantity, int index) {
	quantity[index] = _quantity;
}

/**
 * Asigna el nombre del producto
 * a comprar en el arreglo
 * products[]
 *
 * @param
 * @return
*/

void Shopping_cart::set_products(std::string _product, int index) {
	products[index] = _product;
}

/**
 * Asigna el indice de 
 * los productos
 *
 * @param
 * @return
*/

void Shopping_cart::set_index(int _index) {
	index = _index;
}

//Getters

/**
 * Calcula el precio final de todos
 * los productos adquiridos, el metodo
 * multiplica la cantidad de los productos 
 * del mismo tipo y los multiplica por su costo,
 * al final retorna un costo final.
 *
 * @return final_cost
*/

float Shopping_cart::get_final() {
	float final_cost = 0.0;
	for (int i = 0; i < index; i++) {
		final_cost += quantity[i] * cost[i];
	}

	return final_cost;
}

/**
 * Obtiene el nombre del producto en el 
 * id indicado
 *
 * @param
 * @return products[param]
*/

std::string Shopping_cart::get_products(int index) {
	return products[index];
}

/**
 * Obtiene la cantidad que se tiene
 * en el carrito de un producto en 
 * el indice indicado
 *
 * @param
 * @return quantity[param]
*/

int Shopping_cart::get_quantity(int index) {
	return quantity[index];
}

/**
 * Obtiene el costo que se tiene
 * en el carrito de un producto en
 * el indice indicado
 *
 * @param
 * @return cost[param]
*/

float Shopping_cart::get_cost(int index) {
	return cost[index];
}
#endif //SHOPPING_CART_H