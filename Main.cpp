#include <iostream>
#include "Products.h"
#include "Users.h"
#include "Carts.h"

int main() {

	Products mouse(57.7, 0, "Logitech g203", "Liverpool", "Queretaro", 30);
	std::cout << mouse.get_price() << "\n";
	std::cout << mouse.get_discount() << "\n";
	std::cout << mouse.get_name() << "\n";
	std::cout << mouse.get_store() << "\n";
	std::cout << mouse.get_address() << "\n";
	std::cout << mouse.get_amount() << "\n";

	Products laptop(599.0, 0, "Asus Tuf gaming", "MrRobot", "Ohio", 20);
	laptop.set_price(777.4);

	std::cout << laptop.get_price() << "\n";
	std::cout << laptop.get_discount() << "\n";
	std::cout << laptop.get_name() << "\n";
	std::cout << laptop.get_store() << "\n";
	std::cout << laptop.get_address() << "\n";
	std::cout << laptop.get_amount() << "\n";

	Users user_1("Angel", "Ramirez", "A01710158@tec.mx", "1234-5678-3129-1342", "123", "22/26");
	std::cout << user_1.get_name() << "\n";
	std::cout << user_1.get_last_name() << "\n";
	std::cout << user_1.get_email() << "\n";
	std::cout << user_1.get_cc_number() << "\n";
	std::cout << user_1.get_cc_cvv() << "\n";
	std::cout << user_1.get_cc_expiration() << "\n";

	Carts cart_1(mouse.get_name(), 3, mouse.get_price());
	std::cout << cart_1.get_product() << "\n";
	std::cout << cart_1.get_quantity() << "\n";
	std::cout << cart_1.get_cost() << "\n";
	std::cout << cart_1.final_cost() << "\n";

	mouse.set_amount(mouse.get_amount() - cart_1.get_quantity());
	std::cout << "New mouse amount: " << mouse.get_amount() << "\n";

	return 0;
}