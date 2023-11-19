//#include "string"
#pragma once
template <typename T>
class IDataRepository
{
public:
    virtual void add(T data) = 0;
    virtual void remove(T data) = 0;
    virtual void update(T data) = 0;
    virtual std::vector<T> getAll() const = 0;
};

