/*
 * Proyecto OnlineStore
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 01/12/2022
 */

 /*
  * Clase Customer contiene métodos para la compra de
  * productos por un vendedor (Seller), la clase
  * se compone de Credit_card y Shopping_cart y contiene
  * un indice para poder moverse entre los productos
  * que va adquiriendo el cliente.
  */

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
	//Variables iniciales
	std::string address;
	Credit_card credit_card;
	Shopping_cart shopping_cart;
	int index = 0;
public:
	//Constructor
	Customer() : Users(), address(), credit_card() {}

	Customer(std::string _email, std::string _password, std::string _name, std::string _last_name, std::string _address, 
		std::string _number, std::string _cvv, std::string _expiration, float _money) :
		Users(_email, _password, _name, _last_name), address(_address), 
		credit_card(_number, _cvv, _expiration, _money), shopping_cart() {}

	//Getters
	Shopping_cart get_shopping();
	std::string get_email();
	std::string get_password();

	//Metodos
	bool add_to_cart(Product, int);
	void show_shopping();
	float check_out();
};

//Getters

/**
 * Retorna el carrito de compras
 * del cliente
 *
 *
 * @return Objeto Shopping_cart
*/

Shopping_cart Customer::get_shopping() {
	return shopping_cart;
}

/**
 * Retorna el email del cliente,
 * la variable email es una variable
 * protegida
 *
 *
 * @return email
*/

std::string Customer::get_email() {
	return email;
}

/**
 * Retorna la contraseña del cliente,
 * la variable password es una variable
 * protegida
 *
 *
 * @return password
*/

std::string Customer::get_password() {
	return password;
}

//Metodos

/**
 * Recibe el producto que se va a adquirir y
 * su cantidad a comprar.
 * 
 * Si la cantidad a comprar es mayor a la cantidad
 * que tiene el vendedor de productos y si la 
 * cantidad de productos que tiene el vendedor
 * es mayor a 0, entonces el cliente lo agrega a
 * su carrito de compras.
 * 
 * Si no se cumplen las condiciones no se agrega
 * el producto al carrito de compras.
 *
 * @param
 * @return bool
*/

bool Customer::add_to_cart(Product product, int _quantity) {
	if (_quantity <= product.get_amount() && product.get_amount() > 0) {
		shopping_cart.set_products(product.get_name(), index);
		shopping_cart.set_cost(product.get_price(), index);
		shopping_cart.set_quantity(_quantity, index);
		index += 1;
		shopping_cart.set_index(index);
		std::cout << "Se ha agregado al carrito" << "\n\n";
		return true;
	}
	else {
		std::cout << "No hay productos disponibles" << "\n\n";
	}
	return false;
}

/**
 * Muestra todos los productos que se tienen en el carrito
 * de compras del cliente y su costo final.
 *
 * @param
 * @return
*/

void Customer::show_shopping() {
	for (int i = 0; i < index; i++) {
		std::cout << "Producto: " << shopping_cart.get_products(i) << " Cantidad: "
			<< shopping_cart.get_quantity(i) << " Precio: " << shopping_cart.get_cost(i) << "\n";
	}
	std::cout << "Total: " << shopping_cart.get_final() << "\n\n";
}

/**
 * Se realiza la compra del cliente, se borran todos los datos 
 * del carrito de compras y se le descuenta el costo final en 
 * el dinero de la tarjeta de credito
 *
 * @param
 * @return total
*/

float Customer::check_out() {
	float total = shopping_cart.get_final();
	credit_card.set_money(credit_card.get_money() - total);
	Shopping_cart s_c;
	shopping_cart = s_c;
	index = 0;
	
	return total;
}

#endif //CUSTOMER_H