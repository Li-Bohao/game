#ifndef MULTITON_H
#define MULTITON_H
#include <utility>
#include <stdexcept>
#include <format>
#include <typeinfo>
class MultitonOutOfRange : public std::logic_error
{
public:
    explicit MultitonOutOfRange(const std::string &msg) : std::logic_error(msg) {}
};
template <typename T, size_t max>
    requires(max != 0)
class Multiton
{
private:
    inline static T m_instances[max]{};

protected:
    Multiton() = default;

public:
    Multiton(const Multiton &) = delete;

    Multiton &operator=(const Multiton &) = delete;
    Multiton(Multiton &&) = delete;
    Multiton &operator=(Multiton &&) = delete;

    static T &GetInstance(size_t order)
    {
        if (order >= max)
        {
            throw MultitonOutOfRange(std::format("Attempting to get an object \
                at index {} from class {} exceeds the index limit of {}.",
                                                 order, typeid(T).name(), max));
        }

        return m_instances[order];
    }
};
#endif