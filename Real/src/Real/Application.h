#pragma once 

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
