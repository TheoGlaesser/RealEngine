#pragma once
#include "Application.h"

extern Real::Application* Real::createApplication();

int main() 
{
  Real::Log::Init();
  REAL_WARN("Initialized Log!");
  REAL_INFO("Initialized Log!");

  auto app = Real::createApplication();
  app->run();
	delete app;


	return 0;
}
