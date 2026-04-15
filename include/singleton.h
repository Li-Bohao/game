#include <utility>
#include "utils.h"
template <typename T>
class Singleton : public NonTransferable
{
protected:
    Singleton() = default;

public:
    static T &GetInstance()
    {
        static T instance;
        return instance;
    }
};
