/*
 * Proyecto OnlineStore
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 01/12/2022
 */

 /*
  * Descripcion: En este proyecto trata de 
  simular el proceso lógico que tiene que 
  seguir una tienda en linea para poder manejar 
  un inventario de productos y así poder manejar 
  de forma ordenada la venta de los productos a 
  los clientes.
  */


#include <iostream>
#include "Seller.h"
#include "Customer.h"

using namespace std;

Seller sellers[100];
int index_sellers = 0;

Customer customers[100];
int index_customers = 0;

int customer_id = -1;

/**
 * Agrega un cliente a la variable customers[],
 * considerando que solo pueden haber 100 clientes
 *
 * @param
 * @return
*/

void add_customer(string email, string password, string name,
	string last_name, string address, string number, string cvv, string expiration, float money) {
	Customer c(email, password, name, last_name, address, number, cvv, expiration, money);
	customers[index_customers] = c;
	index_customers += 1;
}

/**
 * Registra todos los datos necesarios
 * para registrar a un nuevo cliente
 *
 * @return
*/

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
	getline(cin, name);
	getline(cin, name);
	cout << "Apellido: " << "\n";
	getline(cin, last_name);
	cout << "Dirección: " << "\n";
	getline(cin, address);
	cout << "Numero de tarjeta de credito: " << "\n";
	cin >> number;
	cout << "cvv: " << "\n";
	cin >> cvv;
	cout << "Expiración: " << "\n";
	cin >> expiration;

	// Solo se pueden poner numeros
	cout << "Dinero en la cuenta: " << "\n";
	cin >> money;

	// Manda a llamar la funcion add_customer() para
	// agregar un nuevo cliente
	add_customer(email, password, name, last_name, address, number, cvv, expiration, money);
	cout << "Te has registrado!" << "\n\n";
}

/**
 * Imprime todos los productos 
 * disponibles que tiene cada vendedor
 *
 * @return
*/

void print_products() {
	for (int i = 0; i < index_sellers; i++) {
		cout << "Nombre del vendedor: " << sellers[i].get_name() << "\n";
		sellers[i].show_products();
		cout << "\n";
	}
}

int main() {

	// Cliente predeterminado para pruebas email: admin@gmail.com contraseña: admin
	add_customer("admin", "admin", "ADMIN", "ADMIN", "Africa", "1234-1234-1234-1234", "123", "07/26", 1234);

	int num = 0;

	//Vendedor 1 predeterminado
	Seller seller_1("razer@gmail.com", "razer123", "Razer", "", "Ohio", true);

	sellers[index_sellers] = seller_1;
	sellers[index_sellers].add_product(1, "electronicos", "Razer viper mini", 50, 23);
	sellers[index_sellers].add_product(2, "electronicos", "Razer huntsman mini", 200, 15);

	index_sellers += 1;

	//Vendedor 2 predeterminado
	Seller seller_2("asus@gmail.com", "asus321", "Asus", "", "Sinaloa", true);

	sellers[index_sellers] = seller_2;
	sellers[index_sellers].add_product(3, "electronicos", "Asus tuf gaming", 1250, 30);
	sellers[index_sellers].add_product(4, "electronicos", "RTX 3080", 1500, 38);

	index_sellers += 1;

	//El while solo se detiene si la variable num es igual a 8
	while (num != 8) {
		cout << "(1) Registrarse " << "\n";
		cout << "(2) Ingresar " << "\n";
		cout << "(3) Ver productos " << "\n";
		cout << "(4) Agregar al carrito " << "\n";
		cout << "(5) Ver carrito" << "\n";
		cout << "(6) Check out" << "\n";
		cout << "(7) Cerrar sesion" << "\n";
		cout << "(8) Salir del programa" << "\n";
		//Se obtiene un nuevo valor para num;
		cin >> num;

		switch(num) {
			// Registrarse
			case 1: {
				// Llama a la funcion sign_in()
				sign_in();
				break;
				
			}
			// Ingresar
			case 2: {
				string email;
				string password;

				// Si no hay clientes no se puede ingresar a ninguna cuenta
				if (index_customers == 0) {
					cout << "No se encuentra nadie registrado!" << "\n\n";
					break;
				}

				// Pide el email y la contraseña
				cout << "Proporciona tu email" << "\n";
				cin >> email;
				cout << "Proporciona tu contraseña: " << "\n";
				cin >> password;

				// Realiza un recorrido por la variable customers[]
				for (int i = 0; i < index_customers; i++) {
					if (customers[i].get_email() == email) {
						// Si existe un usuario con el mismo email y contraseña
						// entonces se obtiene el indice del usuario con esos
						// datos y login se pone como verdadero
						if (customers[i].get_password() == password) {
							customers[i].set_login(true);
							customer_id = i;
							cout << "Has iniciado sesion!" << "\n\n";
						}
						else {
							// Manda un mensaje si la contraseña es incorrecta
							cout << "Contraseña incorrecta!" << "\n\n";
						}
					}
				}
				break;
			}
			// Ver productos
			case 3: {
				// Se llama a la funcion print_products()
				print_products();
				break;
			}
			// Agregar al carrito
			case 4: {
				// Si no hay nadie logeado, se rompe el switch
				if (!customers[customer_id].get_login()) {
					cout << "Debes de iniciar sesion!" << "\n\n";
					break;
				}
				int id = 0;
				int quantity = 0;
				bool found = false; // Sirve para saber si se encontro a el vendedor
				string name;

				// Se llama a la funcion print_products()
				print_products();

				// Pide el nombre del vendedor al que el cliente va a comprar
				cout << "Proporciona el nombre del vendedor: " << "\n";
				cin >> name;

				// Realiza un recorrido por la variable sellers[]
				for (int i = 0; i < index_sellers; i++) {
					// Si el nombre del vendedor proporcionado coincide
					// con el nombre de un vendedor dentro de la lista
					// se pide el id del producto y la cantidad a añadir al carrito
					if (name == sellers[i].get_name()) {
						cout << "Proporciona el ID del producto a comprar: " << "\n";
						cin >> id;
						cout << "Porporciona la cantidad del producto a comprar: " << "\n";
						cin >> quantity;

						// Si se encuentra hay la cantidad de productos demandados
						// entonces se restan al stock que tiene el vendedor
						if (customers[customer_id].add_to_cart(sellers[i].get_product(id), quantity)) {
							sellers[i].set_amount(id, quantity);
						}
						found = true;
					}
				}

				// Si no se encuentra al vendedor entonces manda un mensaje
				if (!found) {
					cout << "No se encuentra ese vendedor!" << "\n\n";
				}
				break;
			}
			// Ver carrito
			case 5: {
				// Si no hay nadie logeado no se muestra el carrito
				if (customers[customer_id].get_login()) {
					customers[customer_id].show_shopping();;
				} 
				else {
					cout << "Debes iniciar sesion!" << "\n\n";
				}
				break;
			}
			// Check out
			case 6: {
				string password;

				// Si no hay nadie logeado no se pueden comprar los productos
				if (customers[customer_id].get_login()) {
					// Pide la contraseña
					cout << "Proporciona tu contraseña: " << "\n";
					cin >> password;

					// Si la contraseña pedida coincide con la contraseña 
					// registrada en esa posicion de usuario
					// entonces se realiza la compra
					if (password == customers[customer_id].get_password()) {
						customers[customer_id].show_shopping();
						customers[customer_id].check_out();
						cout << "Compra realizada!" << "\n\n";
					}
					else {
						cout << "Contraseña incorrecta!" << "\n\n";
					}
				} 
				else {
					cout << "Debes iniciar sesion!" << "\n\n";
				}
				break;
			}
			// Cerrar sesion
			case 7: {
				// Si se encuentra alguien logeado
				// cierra sesion
				if (customers[customer_id].get_login()) {
					customers[customer_id].set_login(false);
					cout << "Has cerrado sesion!" << "\n\n";
				}
				break;
			}
		}
	}
	return 0;
}