#pragma once
#include<list>
#include<memory>
#include "element.h"
class Map {
private:
	Point m_start;
	std::list<std::pair<std::unique_ptr<Element>, Point>> m_element_list;//需要把点位一起存在表里！
public:
	void Load();
	bool InMap();

};