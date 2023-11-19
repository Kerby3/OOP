#include "string"
#pragma once
class IUserManager
{
public:
	virtual bool login(std::string login, std::string password) = 0;
    virtual void logout() = 0;
    virtual int isAuthenticated(std::string login) = 0;
};

