#pragma once
#include <string>

class Users
{
	private:
		std::string name = ""; //Name of the user
		std::string last_name = ""; //Last name of the user
		std::string email = ""; //Email of the user
		//cc is the abbreviation of "Credit Card"
		std::string cc_number = ""; //Credit card back numbers
		std::string cc_cvv = ""; //Credit card CVV
		std::string cc_expiration = ""; //Credit card expiration

	public:
		//Builder
		Users();
		Users(std::string nam, std::string last_nam, std::string em, std::string cc_num, std::string cc_cv, std::string cc_exp) : name(nam), last_name(last_nam), email(em), cc_number(cc_num), cc_cvv(cc_cv), cc_expiration(cc_exp) {};

		//Getters
		std::string get_name();
		std::string get_last_name();
		std::string get_email();
		std::string get_cc_number();
		std::string get_cc_cvv();
		std::string get_cc_expiration();

		void set_name(std::string);
		void set_last_name(std::string);
		void set_email(std::string);
		void set_cc_number(std::string);
		void set_cc_cvv(std::string);
		void set_cc_expiration(std::string);
};

//Getters
std::string Users::get_name() {
	return name;
}

std::string Users::get_last_name() {
	return last_name;
}

std::string Users::get_email() {
	return email;
}

std::string Users::get_cc_number() {
	return cc_number;
}

std::string Users::get_cc_cvv() {
	return cc_cvv;
}

std::string Users::get_cc_expiration() {
	return cc_expiration;
}

//Setters
void Users::set_name(std::string nam) {
	name = nam;
}

void Users::set_last_name(std::string last_nam) {
	last_name = last_nam;
}

void Users::set_email(std::string em) {
	email = em;
}

void Users::set_cc_number(std::string cc_num) {
	cc_number = cc_num;
}

void Users::set_cc_cvv(std::string cc_cv) {
	cc_cvv = cc_cv;
}

void Users::set_cc_expiration(std::string cc_exp) {
	cc_expiration = cc_exp;
}