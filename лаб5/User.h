#include "string"
#pragma once
class User
{
private:
	int id;
	std::string name;
	std::string login;
	std::string password;
public:
	User(std::string name, std::string login, std::string password, int id = 0) {
		this->id = id;
		this->name = name;
		this->login = login;
		this->password = password;
	}

	int getId() const {
		return id;
	}

	std::string getName() const {
		return name;
	}

	std::string getLogin() const {
		return login;
	}

	std::string getPassword() const {
		return password;
	}

	void setId(int id) {
		this->id = id;
	}

	void setName(std::string name) {
		this->name = name;
	}

	void setLogin(std::string login) {
		this->login = login;
	}

	void setPassword(std::string password) {
		this->password = password;
	}
};

