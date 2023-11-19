#pragma once
#include <iostream>
#include "IUserManager.h"
#include "FileUserRepository.h"

class FileUserManager : public IUserManager
{
public:
    FileUserRepository userRepository;
    std::vector<int> authenticatedUsers;
    std::vector<int> entries;
    FileUserManager(FileUserRepository& userRepository) {
        this->userRepository = userRepository;
    }

    bool login(std::string login, std::string password) override {
        std::vector<User> tmp = userRepository.getAll();
        for (int i = 0; i < tmp.size(); i++) {
            if (tmp[i].getLogin() == login && tmp[i].getPassword() == password) {
                std::cout << "Вход с авторизацией\n" << "Логин: " << tmp[i].getLogin() << "\nИмя: " << tmp[i].getName() << std::endl;
                this->authenticatedUsers.push_back(tmp[i].getId());
                this->entries.push_back(tmp[i].getId());
                return true;
            }
        }
        std::cout << "Неверный логин или пароль!" << std::endl;
        return false;
    }

    void logout() override {
        int logoutId = this->entries[this->entries.size()-1];
        auto iter = std::find(this->authenticatedUsers.cbegin(), this->authenticatedUsers.cend(), logoutId);
        if (iter != this->authenticatedUsers.cend()) {
            std::cout << "Выход из профиля" << std::endl;
            this->authenticatedUsers.erase(iter);
            this->entries.pop_back();
        }
        
    }

    int isAuthenticated(std::string login) override {
        for (int i = 0; i < this->authenticatedUsers.size(); i++) {
            if (this->userRepository.getById(this->authenticatedUsers[i]).getLogin() == login) {
                std::cout << "Вход без авторизации\n" << "Логин: " << this->userRepository.getById(this->authenticatedUsers[i]).getLogin() << "\nИмя: " << this->userRepository.getById(this->authenticatedUsers[i]).getName() << std::endl;
                auto tmpId = this->userRepository.getById(this->authenticatedUsers[i]).getId();
                entries.push_back(tmpId);
                return this->authenticatedUsers[i];
            }
        }
        return -1;
    }

private:
    
    
};

