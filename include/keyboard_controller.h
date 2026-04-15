#ifndef KEYBOARD_CONTROLLER_H
#define KEYBOARD_CONTROLLER_H
#include <windows.h>
#include "controller.h"
bool is_pressed(uint8_t key)
{
	return GetAsyncKeyState(key) & 0x8000;
}
class KeyboardController : public Controller
{
private:
	KeyboardController() = default;

public:
	Input GetInput()
	{
#define CHECK_AND_RETURN(key, val)        \
	do                                    \
	{                                     \
		if (is_pressed(m_keys[Key::key])) \
			return Input::val;            \
	} while (0)
		CHECK_AND_RETURN(QUIT, QUIT);
		CHECK_AND_RETURN(ENTER, ENTER);
		CHECK_AND_RETURN(MAX, MAXIMUM);
		CHECK_AND_RETURN(A, ATTACK);
		CHECK_AND_RETURN(B, BAG);
		CHECK_AND_RETURN(C, CAST);
		CHECK_AND_RETURN(D, D);
#undef CHECK_AND_RETURN
		bool up = is_pressed(Key::UP);
		bool down = is_pressed(Key::DOWN);
		bool left = is_pressed(Key::LEFT);
		bool right = is_pressed(Key::RIGHT);
		if (up)
		{
			if (left)
			{
				return Input::UPPER_LEFT;
			}
			if (right)
			{
				return Input::UPPER_RIGHT;
			}
			return Input::UP;
		}
		if (down)
		{
			if (left)
			{
				return Input::LOWER_LEFT;
			}
			if (right)
			{
				return Input::LOWER_RIGHT;
			}
			return Input::DOWN;
		}
		return Input::NO_ACTION;
	}
	void LoadKeys()
	{
		//不要走开，下个commit更精彩
	}
	void SetKey(uint8_t order)
	{
		//不要走开，下个commit更精彩
	}
};
#endif