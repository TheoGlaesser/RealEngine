#pragma once 

#include "Log.h"
#include "Window.h"
#include "Events/Event.h"
#include "Layerstack.h"


namespace Real
{

	class Application {
		public:
			Application();
			virtual ~Application();

      void pushLayer(Layer* layer);
      void pushOverlay(Layer* overlay);

			void run();

      void onEvent(Event& e);
    private:
      bool onWindowClose(Event& e);
      std::unique_ptr<Window> m_Window;
      bool m_Running;
      LayerStack m_LayerStack;



	};

	Application* createApplication();

}
