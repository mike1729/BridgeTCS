#include "Application.hpp"
#include "ui/text/ApplicationView.hpp"
#include <functional>

int main() {
	Application application;
	ui::text::ApplicationView appView;

	application.sigModified.connect(std::bind(&ui::text::ApplicationView::notify, &appView, std::placeholders::_1));
	application.run();
	return 0;
}
