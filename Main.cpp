#include <iostream>
#include "Seller.h"
#include "Customer.h"

using namespace std;

Seller sellers[100];
int index_sellers = 0;

Customer customers[100];
int index_customers = 0;

int customer_id = -1;

// Sirve para agregar un cliente a la variable customers[]
void add_customer(string email, string password, string name,
	string last_name, string address, string number, string cvv, string expiration, float money) {
	Customer c(email, password, name, last_name, address, number, cvv, expiration, money);
	customers[index_customers] = c;
	index_customers += 1;
}

// Sirve para registrarse como cliente
void sign_in() {
	int num = 0;
	string email;
	string password;
	string name;
	string last_name;
	string address;
	string number; // Numero de la tarjeta de credito
	string cvv; // Cvv de la tarjeta de credito
	string expiration; // Expiracion de la tarjeta de credito
	float money; // Dinero en la tarjeta de credito

	cout << "Email: " << "\n";
	cin >> email;
	cout << "Contraseña: " << "\n";
	cin >> password;
	cout << "Nombre: " << "\n";
	cin >> name;
	cout << "Apellido: " << "\n";
	cin >> last_name;
	cout << "Dirección: " << "\n";
	cin >> address;
	cout << "Numero de tarjeta de credito: " << "\n";
	cin >> number;
	cout << "cvv: " << "\n";
	cin >> cvv;
	cout << "Expiración: " << "\n";
	cin >> expiration;
	cout << "Dinero en la cuenta: " << "\n";
	cin >> money;

	add_customer(email, password, name, last_name, address, number, cvv, expiration, money);

	cout << "Te has registrado!" << "\n\n";
}

// Sirve para imprimir todos los productos por vendedor
void print_products() {
	for (int i = 0; i < index_sellers; i++) {
		cout << sellers[i].get_name() << "\n";
		sellers[i].show_products();
		cout << "\n";
	}
}

int main() {

	// Cliente predeterminado para pruebas email: admin@gmail.com contraseña: admin
	add_customer("admin", "admin", "ADMIN", "ADMIN", "Africa", "1234-1234-1234-1234", "123", "07/26", 1234);

	int num = 0;

	Seller seller_1("razer@gmail.com", "razer123", "Razer", "", "Ohio", 0.0, true);

	sellers[index_sellers] = seller_1;
	sellers[index_sellers].add_product(1, "electronicos", "Razer viper mini", 50, 23);
	sellers[index_sellers].add_product(2, "electronicos", "Razer huntsman mini", 200, 15);

	index_sellers += 1;

	Seller seller_2("asus@gmail.com", "asus321", "Asus", "", "Sinaloa", 0.0, true);

	sellers[index_sellers] = seller_2;
	sellers[index_sellers].add_product(3, "electronicos", "Asus tuf gaming", 1250, 30);
	sellers[index_sellers].add_product(4, "electronicos", "RTX 3080", 1500, 38);

	index_sellers += 1;

	while (num != 6) {
		cout << "(1) Registrarse " << "\n";
		cout << "(2) Ingresar " << "\n";
		cout << "(3) Ver productos " << "\n";
		cout << "(4) Agregar al carrito " << "\n";
		cout << "(5) Ver carrito" << "\n";
		cout << "(9) Cerrar sesion" << "\n";
		cin >> num;

		switch(num) {
			// Registrarse
			case 1: {
				sign_in();
				break;
				
			}
			// Ingresar
			case 2: {
				string email;
				string password;

				if (index_customers == 0) {
					cout << "No se encuentra nadie registrado!" << "\n\n";
					break;
				}

				cout << "Proporciona tu email" << "\n";
				cin >> email;
				cout << "Proporciona tu contraseña: " << "\n";
				cin >> password;

				for (int i = 0; i < index_customers; i++) {
					if (customers[i].get_email() == email) {
						if (customers[i].get_password() == password) {
							customers[i].set_login(true);
							customer_id = i;
							cout << "Has iniciado sesion!" << "\n\n";
						}
						else {
							cout << "Contraseña incorrecta!" << "\n\n";
						}
					}
				}
				break;
			}
			// Ver productos
			case 3: {
				print_products();
				break;
			}
			// Agregar al carrito
			case 4: {
				if (!customers[customer_id].get_login()) {
					cout << "Debes de iniciar sesion!" << "\n\n";
					break;
				}
				int id = 0;
				int quantity = 0;
				string name;

				print_products();

				cout << "Proporciona el nombre del vendedor: " << "\n";
				cin >> name;

				for (int i = 0; i < index_sellers; i++) {
					if (name == sellers[i].get_name()) {
						cout << "Proporciona el ID del producto a comprar: " << "\n";
						cin >> id;
						cout << "Porporciona la cantidad del producto a comprar: " << "\n";
						cin >> quantity;

						customers[customer_id].add_to_cart(sellers[i].get_product(id), quantity);
						sellers[i].set_amount(id, quantity);
					}
				}
				break;
			}
			// Ver carrito
			case 5: {
				if (customers[customer_id].get_login()) {
					customers[customer_id].show_shopping();
				}
				break;
			}
			// Cerrar sesion
			case 9: {
				customers[customer_id].set_login(false);
				cout << "Has cerrado sesion!" << "\n\n";
				break;
			}
		}
	}

	/*seller_1.set_earnings(customer_1.check_out());
	cout << customer_1.check_out() << "\n";
	cout << seller_1.get_earnings() << "\n";*/
	return 0;
}