#ifndef USERS_H
#define USERS_H

#pragma once
#include <string>

class Users
{
private:
	std::string email;
	std::string password;
	std::string name;
	std::string last_name;
	bool login = false;
public:

	Users() : email(), password(), name(), last_name() {}

	Users(std::string _email, std::string _password, std::string _name, std::string _last_name) {
		email = _email;
		password = _password;
		name = _name;
		last_name = _last_name;
	}

	 void check_login(bool);
};

void Users::check_login(bool _login) {
	login = _login;
}

#endif