/*
 * Proyecto OnlineStore
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 01/12/2022
 */

 /*
  * Clase Seller contiene métodos para el manejo de porductos
  * vendidos por un vendedor, se toma en cuenta que cada 
  * vendedor solo puede vender 100 productos maximos
  */

#ifndef SELLER_H
#define SELLER_H

#pragma once
#include <string>
#include "Users.h"
#include "Product.h"

class Seller : public Users {
private:
	//Variables iniciales
	Product products[100];
	int index = 0;
	std::string store_address;
	bool license = false;
public:
	//Constructor
	Seller(): Users(), store_address(), license(){}

	Seller(std::string _email, std::string _password, std::string _name, std::string _last_name, std::string _store_address, bool _license) :
		Users(_email, _password, _name, _last_name)
	{
		store_address = _store_address;
		license = _license;
	}

	//Setters
	void set_license(bool);
	void set_earnings(float);
	void set_amount(int, int);

	//Getters
	Product get_product(int);
	std::string get_name();

	//Metodos
	void add_product(int, std::string, std::string, float, int);
	void show_products();
};

//Setters

/**
 * Actualiza la licencia del vendedor
 * Solo acepta true o false
 *
 * @param
 * @return
*/

void Seller::set_license(bool _license) {
	license = _license;
}

/**
 * Actualiza la cantidad de productos 
 * que tiene el vendedor,
 * recibe el id del producto y la cantidad
 * que esta adquiriendo el cliente
 * 
 *
 * @param
 * @return
*/

void Seller::set_amount(int _id, int _amount) {
	for (int i = 0; i < index; i++) {
		if (products[i].get_id() == _id) {
			products[i].set_amount(products[i].get_amount() - _amount);
		}
	}
}

//Getters

/**
 * Obtiene el producto mediante su id,
 * si encuentra un producto con un id
 * similar retorna su valor.
 * 
 * Si no encuentra un producto con el id
 * requerido devuelve un producto con datos
 * vacios.
 * 
 *
 * @param
 * @return Objeto Product
*/

Product Seller::get_product(int _id) {
	Product p;
	for (int i = 0; i < index; i++) {
		if (products[i].get_id() == _id) {
			return products[i];
		}
	}
	return p;
}

std::string Seller::get_name() {
	return name;
}

//Metodos

/**
 * El vendedor agrega un nuevo producto en la 
 * lista products, la funcion requiere de todos
 * los parametros para llenar un objeto
 * de tipo Product.
 * 
 * Existe un indice que indica que tantos
 * productos tiene el vendedor registrados
 *
 *
 * @param
 * @return
*/

void Seller::add_product(int _id, std::string _category, std::string _name, float _price, int _amount) {
	Product p(_id, _category, _name, _price, _amount);
	products[index] = p;
	index += 1;
}

/**
 * Se muestran todos los productos que el vendedor tiene
 * registrados, muestra el ID, el nombre del producto,
 * su cantidad y su precio.
 *
 * @param
 * @return
*/

void Seller::show_products() {
	for (int i = 0; i < index; i++) {
		std::cout << "ID: " << products[i].get_id() << " Producto: " << products[i].get_name() <<
			" Cantidad: " << products[i].get_amount() << " Precio: " << products[i].get_price() << "\n";
	}
}
#endif // SELLER_H