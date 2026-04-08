#ifndef ACTOR_H
#define ACTOR_H
#include"element.h"
#include"control.h"
class Actor: public Element {
private:
	Control& a;
	Actor():a(Control::GetController()) {
		
	}
public:
	MoveDistance Move() {
		
	}
	bool CheckPerFrame(std::pair<std::unique_ptr<Element>, Point>& element_list) {

	}
	Actor(const Actor&) = delete;
	Actor& operator=(const Actor&) = delete;
	Actor(Actor&&) = delete;
	Actor& operator=(Actor&&) = delete;
	static Actor& GetActor() {
		static Actor instance;
		return instance;
	}
};
#endif