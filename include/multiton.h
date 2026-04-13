#ifndef MULTITON_H
#define MULTITON_H
#include <memory>
#include <utility>
#include <stdexcept>
#include <format>
#include <typeinfo>
#include <mutex>
class MultitonOverLimit : public std::logic_error
{
public:
    explicit MultitonOverLimit(const std::string &msg) : std::logic_error(msg) {}
};
class MultitonOutOfRange : public std::logic_error
{
public:
    explicit MultitonOutOfRange(const std::string &msg) : std::logic_error(msg) {}
};
class MultitonDoubleRelease : public std::logic_error
{
public:
    explicit MultitonDoubleRelease(const std::string &msg) : std::logic_error(msg) {}
};
template <typename T, size_t max>
requires (max != 0)
class Multiton
{
private:
    inline static std::unique_ptr<T> m_ptr[max]{};
    inline static std::mutex m_mutex;

protected:
    Multiton() = default;

public:
    Multiton(const Multiton &) = delete;
    Multiton &operator=(const Multiton &) = delete;
    Multiton(Multiton &&) = delete;
    Multiton &operator=(Multiton &&) = delete;
    template <typename... Args>
    static std::pair<size_t order, T &> NewInstance(Args &&...args)
    {
        std::lock_guard lock(m_mutex);
        for (size_t i = 0; i < max; ++i)
        {
            if (nullptr == m_ptr[i])
            {
                m_ptr[i] = std::make_unique<T>(std::forward<Args>(args)...);
                return {i + 1, *m_ptr[i]};
            }
        }
        throw MultitonOverLimit(std::format("Class {} attempts \
            to construct an instance that exceeds the instance count limit of {}.",
                                            typeid(T).name(), max));
    }
    static void DestroyInstance(size_t order)
    {
        std::lock_guard lock(m_mutex);
        if (order > max || 0 == order)
        {
            throw MultitonOutOfRange(std::format("Class {} attempts \
                to release an instance with index {}, which is out of range {}.",
                                                 typeid(T).name(), order, max));
        }
        if (nullptr == m_ptr[order - 1])
        {
            throw MultitonDoubleRelease(std::format("Class {} attempts \
                to release an instance with index {} twice.",
                                                 typeid(T).name(), order));
        }
        m_ptr[order - 1].reset();
    }
};
#endif