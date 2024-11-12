#include "realpch.h"
#include "Application.h"

#include "Real/Events/Event.h"
#include "Real/Events/ApplicationEvent.h"
#include "Real/Log.h"

namespace Real {

	Application::Application() {
	
	}

	Application::~Application() {

	}

	void Application::run() {
    WindowResizeEvent e(1280, 720);
    REAL_TRACE(e.toString());

    while (true);
	}
}
