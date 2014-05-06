#include "Application.cpp"


int main() {
	ui::ApplicationView appView = ui::ApplicationView();
	Application application = Application(appView);
	application.run();
	return 0;
}
