/*
 * Proyecto OnlineStore
 * Angel Mauricio Ramirez Herrera
 * A01710158
 * 01/12/2022
 */

 /*
  * Clase Users es una clase 
  * padre que tiene las propiedades de 
  * un usuario
  */

#ifndef USERS_H
#define USERS_H

#pragma once
#include <string>

class Users
{
protected:
	//Variables iniciales
	//Las variables son protegidas por lo que
	//las clases hijas pueden acceder a su informacion
	std::string email;
	std::string password;
	std::string name;
	std::string last_name;
	bool login = false;
public:

	//Constructor
	Users() : email(), password(), name(), last_name() {}

	Users(std::string _email, std::string _password, std::string _name, std::string _last_name) {
		email = _email;
		password = _password;
		name = _name;
		last_name = _last_name;
	}

	 //Setters
	 void set_login(bool);

	 //Getters
	 bool get_login();
};

//Setters

/**
 * Asigna un nuevo valor a la
 * variable login (true, false)
 *
 * @param
 * @return
*/

void Users::set_login(bool _login) {
	login = _login;
}

//Getters

/**
 * Obtiene el estatus de 
 * la variable login (true, false)
 *
 * @return login
*/

bool Users::get_login() {
	return login;
}

#endif //USERS_H