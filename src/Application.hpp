#ifndef _APPLICATION_HPP
#define _APPLICATION_HPP

#include "ui/ApplicationView.cpp"
#include "ui/Observable.hpp"

class Application : public ui::Observable{
public:
	Application(ui::ApplicationView& view) {
		subscribe(view);
	}
	void run();
};

#endif