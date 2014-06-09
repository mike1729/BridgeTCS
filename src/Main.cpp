#include "viewmodel/Application.hpp"
#include "ui/text/ApplicationView.hpp"
#include <functional>

int main() 
{

	viewmodel::Application application;
	//bridge::PlayerID id =0;
	ui::text::ApplicationView appView;
	
	application.sigModified.connect([& appView](viewmodel::Application const & app) {
		appView.notify(app);
	});
	application.runApplication();
	return 0;
}
