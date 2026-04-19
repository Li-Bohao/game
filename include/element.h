#ifndef ELEMENT_H
#define ELEMENT_H
#include <utility>
#include <memory>
#include <variant>
class Element
{
protected:
	bool m_passable, m_moveable;
	unsigned short m_height;
	unsigned short m_width;
	struct Point
	{
		unsigned short x, y;
	};
	struct MoveDistance
	{
		unsigned short x, y;
	};

public:
	bool Passable()
	{
		return m_passable;
	}
	bool Moveable()
	{
		return m_moveable;
	}
	virtual MoveDistance Move() = 0;
	// 返回true是仍然存在，返回false是元素消失
};
#endif