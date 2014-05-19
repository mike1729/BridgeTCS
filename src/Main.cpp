//#include "Application.hpp"
#include "ui/text/ApplicationView.hpp"
#include <functional>

int main() 
{
	Application application;
	ui::text::ApplicationView appView;
	
	application.sigModified.connect([& appView](Application const & app) {
		appView.notify(app);
	});
	application.run();
	return 0;
}
