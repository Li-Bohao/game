#ifndef MULTITON_H
#define MULTITON_H
#include <utility>
#include <stdexcept>
#include <format>
#include <typeinfo>
#include "utils.h"
class MultitonOutOfRange : public std::logic_error
{
public:
    explicit MultitonOutOfRange(const std::string &msg) : std::logic_error(msg) {}
};
template <typename T, size_t max>
    requires(max != 0)
class Multiton : public NonTransferable
{
protected:
    Multiton() = default;

public:
    static T &GetInstance(size_t order)
    {
        if (order >= max)
        {
            throw MultitonOutOfRange(std::format("Attempting to get an object \
                at index {} from class {} exceeds the index limit of {}.",
                                                 order, typeid(T).name(), max));
        }
        static T instances[max];
        return instances[order];
    }
};
#endif