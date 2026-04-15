#ifndef CONTROLER_H
#define CONTROLER_H
#include <cstdint>
#include <type_traits>
#include "utils.h"

class Controller : public NonTransferable
{
private:
    constexpr static uint8_t KEY_COUNT = 11;

protected:
    uint64_t m_keys[KEY_COUNT];
    enum Key : uint8_t
    {
        UP = 0,
        DOWN,
        LEFT,
        RIGHT,
        A,
        B,
        C,
        D,
        MAX,
        ENTER,
        QUIT,
        ENUM_KEY_COUNT // 固定在最后位置，只用于编译期约束
    };
    static_assert(KEY_COUNT == static_cast<std::underlying_type_t<Key>>(Key::ENUM_KEY_COUNT),
                  "A must equal the number of enumerators in B");

public:
    enum class Input : uint8_t
    {
        NO_ACTION = 0,
        UP,
        DOWN,
        LEFT,
        RIGHT,
        UPPER_LEFT,
        UPPER_RIGHT,
        LOWER_LEFT,
        LOWER_RIGHT,
        ATTACK,
        BAG,
        CAST,
        D,
        MAXIMUM,
        ENTER,
        QUIT
    };
    virtual Input GetInput() = 0;
    virtual void LoadKeys() = 0;
    virtual void SetKey(uint8_t) = 0;
};
#endif
