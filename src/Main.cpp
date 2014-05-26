#include "viewmodel/Application.hpp"
#include "ui/text/ApplicationView.hpp"
#include <functional>

int main() 
{

	viewmodel::Application application;
	ui::text::ApplicationView appView;
	
	application.sigModified.connect([& appView](viewmodel::Application const & app) {
		appView.notify(app);
	});
	application.run();
	return 0;
}
