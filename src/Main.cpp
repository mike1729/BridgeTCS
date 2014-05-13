#include "Application.hpp"
#include "ui/text/ApplicationView.hpp"
#include <functional>

int main() 
{
	Application application;
	ui::text::ApplicationView appView;

	application.subscribe(appView);
	application.run();
	return 0;
}
