#ifndef ELEMENT_H
#define ELEMENT_H
#include<utility>
#include<memory>
struct Point {
	unsigned short x;
	unsigned short y;
};
struct MoveDistance {
	unsigned short x, y;
};
class Element {
protected:
	bool m_passable, m_moveable;
	unsigned char m_tallness;
	unsigned short m_height;
	unsigned short m_width;
public:
	bool Passable(){
		return m_passable;
	}
	bool Moveable() {
		return m_moveable;
	}
	virtual MoveDistance Move() = 0;
	//返回true是仍然存在，返回false是元素消失
	virtual bool CheckPerFrame(std::pair<std::unique_ptr<Element>, Point>& element_list) = 0;
};
#endif