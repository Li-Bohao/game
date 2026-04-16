#ifndef UTILS_H
#define UTILS_H
class NonCopyable
{
protected:
    NonCopyable() = default;

public:
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;
};
class NonMovable
{
protected:
    NonMovable() = default;

public:
    NonMovable(NonMovable &&) = delete;
    NonMovable &operator=(NonMovable &&) = delete;
};
class NonTransferable
{
protected:
    NonTransferable() = default;

public:
    NonTransferable(const NonTransferable &) = delete;
    NonTransferable &operator=(const NonTransferable &) = delete;
    NonTransferable(NonTransferable &&) = delete;
    NonTransferable &operator=(NonTransferable &&) = delete;
};
#endif