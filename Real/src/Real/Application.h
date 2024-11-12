#pragma once 

#include "Log.h"

namespace Real
{
	class Application {
		public:
			Application();
			void run();
			virtual ~Application();

	};

	Application* createApplication();
}
