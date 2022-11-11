#pragma once
#include <string>

class Carts
{
	private:
		std::string product = "";
		int quantity = 0;
		float cost = 0.0;

	public:
		//Builder
		Carts();
		Carts(std::string prdct, int quant, float cst) : product(prdct), quantity(quant), cost(cst) {};

		//Getters
		std::string get_product();
		int get_quantity();
		float get_cost();

		//Setters
		void set_product(std::string);
		void set_quantity(int);
		void set_cost(float);

		//Functions
		float final_cost();
};

//Getters
std::string Carts::get_product() {
	return product;
}

int Carts::get_quantity() {
	return quantity;
}

float Carts::get_cost() {
	return cost;
}

//Setters
void Carts::set_product(std::string prdct) {
	product = prdct;
}

void Carts::set_quantity(int amnt) {
	quantity = amnt;
}

void Carts::set_cost(float cst) {
	cost = cst;
}

//Functions
float Carts::final_cost() {
	return cost * quantity;
}