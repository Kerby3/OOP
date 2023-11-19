#pragma once
#include "IUserRepository.h"
//#include "FileUserManager.h"
#include "string"
#include <vector>
#include <iostream>
class FileUserRepository : public IUserRepository
{
public:
    FileUserRepository() {
        users.push_back(User{ "admin", "admin", "admin" });
    }
    void add(User data) override{
        bool found = false;
        for (int i = 1; i < this->users.size(); i++) {
            if (users[i].getLogin() == data.getLogin() && users[i].getName() == data.getName()) {
                found = true;
                std::cout << "ѕользователь с таким логином или именем уже существует!" << std::endl;
            }
        }
        if (!found) {
            data.setId(users.size());
            users.push_back(data);
        }
    }
    
    void remove(User data) override {
        bool removed = false;
        for (int i = 1; i < this->users.size(); i++) {
            if (users[i].getId() == data.getId()) {
                auto iter = this->users.cbegin();
                users.erase(iter + i);
                removed = true;
            }
            if (removed && users.size() >= i+1) {
                users[i].setId(i);
            }
        }
    }
    
    void update(User data) override {
        bool canUpdate = true;
        for (int i = 1; i < this->users.size(); i++) {
            if (data.getId() == 0 || data.getLogin() == this->users[i].getLogin() || data.getName() == this->users[i].getName()) {
                canUpdate = false;
                std::cout << "Ќевозможно обновить данные!" << std::endl;
            }
        }
        if (canUpdate) {
            this->users.at(data.getId()).setLogin(data.getLogin());
            this->users.at(data.getId()).setName(data.getName());
            this->users.at(data.getId()).setPassword(data.getPassword());
            std::cout << "ƒанные успешно обновлены!" << std::endl;
        }
    }
    
    User getById(int id) const override {
        for (int i = 1; i < this->users.size(); i++) {
            if (users[i].getId() == id && id > 0) {
                return users[i];
            }
        }
        std::cout << "ѕользовател€ с таким id не существует!";
        return users[0];
    }
    
    User getByName(std::string name) const override {
        for (int i = 1; i < this->users.size(); i++) {
            if (users[i].getName() == name && name != "") {
                return users[i];
            }
        }
        std::cout << "ѕользовател€ с таким id не существует или задано неверное им€!";
        return users[0];
    }

    std::vector<User> getAll() const {
        return this->users;
    }
private:
    std::vector<User> users;
};

