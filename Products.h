#pragma once
#include <string>

class Products
{
	private:
		float price = 0.0; //Price of the product
		float discount = 0.0; //Just if there's a discount
		std::string name = ""; //Name of the product
		std::string store = ""; //Name of the store
		std::string address = ""; //address of the store
		int amount = 0; //Amount of the product

	public:
		//Builder
		Products();
		Products(float prc, float disc, std::string nam, std::string stre, std::string addrs, int amnt) : price(prc), discount(disc), name(nam), store(stre), address(addrs), amount(amnt) {};

		//Getters
		float get_price();
		float get_discount();
		std::string get_name();
		std::string get_store();
		std::string get_address();
		int get_amount();

		//Setters
		void set_price(float);
		void set_discount(float);
		void set_name(std::string);
		void set_store(std::string);
		void set_address(std::string);
		void set_amount(int);

};

//Getters
float Products::get_price() {
	return price;
}

float Products::get_discount() {
	return discount;
}

std::string Products::get_name() {
	return name;
}

std::string Products::get_store() {
	return store;
}

std::string Products::get_address() {
	return address;
}

int Products::get_amount() {
	return amount;
}

//Setters
void Products::set_price(float prc) {
	price = prc;
}

void Products::set_discount(float disc) {
	discount = disc;
}

void Products::set_name(std::string nam) {
	name = nam;
}

void Products::set_store(std::string stre) {
	store = stre;
}

void Products::set_address(std::string addrs) {
	address = addrs;
}

void Products::set_amount(int amnt) {
	amount = amnt;
}