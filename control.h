#pragma once
#include <windows.h>
class Control {
private:
	using InputVector = unsigned;
	using KeyOrder = unsigned char;
	using Key = unsigned char;

	static constexpr KeyOrder KEY_COUNT = 11;

	Key m_keys[KEY_COUNT];

	Control() :m_keys{ 'W','A','S','D',VK_NUMPAD1,VK_NUMPAD2,VK_NUMPAD3,VK_NUMPAD4,'R',VK_RETURN,VK_ESCAPE} {
		
	}

public:
	//static constexpr KeyOrder up = 0, down = 1, left = 2, right = 3, a = 4, b = 5, c = 6, d = 7, select = 8, start = 9, quit = 10;
	InputVector GetInput() {
		InputVector result = 0;
		for (KeyOrder i = 0; i < KEY_COUNT; ++i) {
			if (GetAsyncKeyState(m_keys[i]) & 0x8000) {
				result |= 1 << i;
			}
		}
		return result;
	}
	void SetKey(KeyOrder order, Key new_key) {
		m_keys[order] = new_key;
	}

	Control(const Control&) = delete;
	Control& operator=(const Control&) = delete;
	Control(Control&&) = delete;
	Control& operator=(Control&&) = delete;

	static Control& GetController() {
		static Control instance;
		return instance;
	}
};