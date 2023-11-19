#pragma once
//#include <string>
#include <vector>
#include "User.h"
#include "IDataRepository.h"
class IUserRepository : public IDataRepository<User>
{
public:
    virtual void add(User data) override = 0;
    virtual void remove(User data) override = 0;
    virtual void update(User data) override = 0;
    virtual User getById(int id) const = 0;
    virtual User getByName(std::string name) const = 0;
    virtual std::vector<User> getAll() const override = 0;
};

