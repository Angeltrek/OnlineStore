#ifndef USERS_H
#define USERS_H

#pragma once
#include <string>

class Users
{
protected:
	std::string email;
	std::string password;
	std::string name;
	std::string last_name;
	bool login = false;
public:

	//Builders
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
void Users::set_login(bool _login) {
	login = _login;
}

//Getters
bool Users::get_login() {
	return login;
}

#endif