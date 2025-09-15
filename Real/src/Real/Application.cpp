#include "realpch.h"
#include "Application.h"
#include "Real/Events/Event.h"
#include "Real/Events/ApplicationEvent.h"
#include "Log.h"

#include "glad/glad.h"


#define BIND_EVENT_FN(x) std::bind(&Application::x, this, std::placeholders::_1)

namespace Real {

	Application::Application() 
  {
    m_Window = std::unique_ptr<Window>(Window::create());
    m_Window->setEventCallback(BIND_EVENT_FN(onEvent));

    //ImGui gui;
	}
 
  Application::~Application() 
  {
	}

 

  void Application::onEvent(Event& e) 
  {
    EventDispatcher dispatcher(e);
    dispatcher.dispatch<WindowCloseEvent>(BIND_EVENT_FN(onWindowClose));

    REAL_CORE_TRACE("{0}", e.toString());

    ///LOOP FROM BACK TO FRONT THROUGH ALL LAYERS///
    for(auto it = m_LayerStack.end(); it != m_LayerStack.begin(); ) {
      (*--it)->onEvent(e);
      if(e.m_Handled) {
       return;
      }
    }
  }



  ///////SIMPLE WRAPPERS FOR LAYERSTACK FUNCTIONS///////////////
  void Application::pushLayer(Layer* layer) 
  {
    m_LayerStack.pushLayer(layer);
  }

  void Application::pushOverlay(Layer* overlay) 
  {
    m_LayerStack.pushOverlay(overlay);
  }



  ////////////MAIN LOOP/////////////////
	void Application::run() 
  {
    while(m_Running)
    {
      glClearColor(1,0,1,1);
      glClear(GL_COLOR_BUFFER_BIT);
      
      ///LOOP OVER ALL LAYERS FRONT TO BACK///
      for(Layer* layer : m_LayerStack) {
        layer->onUpdate();
      }

      m_Window->onUpdate();
    }
	}



  ///////////////PRIVATE MEMBER FUNCTION WHICH IS BINDED TO GLFW WINDOW CLOSE EVENT//////////////
  bool Application::onWindowClose(Event& e)
  {
    m_Running = false;
    return true;
  }

}
