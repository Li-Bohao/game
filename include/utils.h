#ifndef UTILS_H
#define UTILS_H
class NonCopyable
{
public:
    NonCopyable(const NonCopyable &) = delete;
    NonCopyable &operator=(const NonCopyable &) = delete;
};
class NonMovable
{
public:
    NonMovable(NonMovable &&) = delete;
    NonMovable &operator=(NonMovable &&) = delete;
};
class NonTransferable
{
public:
    NonTransferable(const NonTransferable &) = delete;
    NonTransferable &operator=(const NonTransferable &) = delete;
    NonTransferable(NonTransferable &&) = delete;
    NonTransferable &operator=(NonTransferable &&) = delete;
};
#endif