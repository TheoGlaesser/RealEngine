#pragma once
#include <iostream>

extern Real::Application* Real::createApplication();

int main() {
	std::cout << "Welcome to Real Engine\n";
	auto app = Real::createApplication();
	app->run();
	delete app;


	return 0;
}
