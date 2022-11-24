#include <iostream>
#include "Seller.h"
#include "Customer.h";

using namespace std;

int main() {
	Seller seller_1("razer@gmail.com", "razer123", "Razer", "", "Ohio", 0.0, true);
	seller_1.add_product(1, "electronicos", "Razer viper mini", 50, 23);
	seller_1.add_product(2, "electronicos", "Razer huntsman mini", 200, 15);
	seller_1.show_products();

	Customer customer_1("angel@gmail.com", "1234", "Angel Mauricio", "Ramirez Herrera", "Parque privado #92",
		"1234-1234-1234-1234", "123", "10/26", 33000.0);

	customer_1.add_to_cart(seller_1.get_product(1), 3);
	seller_1.set_amount(1, 3);
	customer_1.add_to_cart(seller_1.get_product(2), 3);
	seller_1.set_amount(2, 3);

	cout << seller_1.get_product(1).get_amount() << "\n";
	cout << seller_1.get_product(2).get_amount() << "\n";

	seller_1.set_earnings(customer_1.check_out());
	cout << customer_1.check_out() << "\n";
	cout << seller_1.get_earnings() << "\n";


}