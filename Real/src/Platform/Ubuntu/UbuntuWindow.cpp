#include "UbuntuWindow.h"
#include "Real/Events/ApplicationEvent.h"
#include "Real/Events/MouseEvent.h"
#include "Real/Events/KeyEvent.h"

#include "glad/glad.h"


namespace Real {
  
  static bool s_GLFWInitialized = false;

  static void glfwSetErrorCallback(int error, const char* description)
  {
    REAL_CORE_ERROR("GLFW Error ({0}) : {1}", error, description);
  }


  Window* Window::create(const WindowProps& props)
  {
    return new UbuntuWindow(props);
  }


  UbuntuWindow::UbuntuWindow(const WindowProps& props)
  {
    Init(props);
  }


  UbuntuWindow::~UbuntuWindow() 
  {
  }


  void UbuntuWindow::Init(const WindowProps& props)
  {
    m_Data.title = props.title;
    m_Data.width = props.width;
    m_Data.height = props.height;

    REAL_CORE_INFO("Creating window{0} ({1}, {2})", props.title, props.width, props.height);

    if(!s_GLFWInitialized)
    {
      int success = glfwInit();
      REAL_CORE_ASSERT(success, "Could not initialize GLFW");

      s_GLFWInitialized = true;
    }


  
    m_Window = glfwCreateWindow((int)props.width, (int)props.height, m_Data.title.c_str(), nullptr, nullptr);
    glfwMakeContextCurrent(m_Window);

    int status = gladLoadGLLoader((GLADloadproc)glfwGetProcAddress);
    REAL_CORE_ASSERT(status, "Failed to load GLAD");
          
    glfwSetWindowUserPointer(m_Window, &m_Data);
    setVSync(true);

    //IMPLEMENT GLFW CALLBACK FUNCTIONS
    glfwSetKeyCallback(m_Window, [](GLFWwindow* window, int key, int scancode, int action, int mods)
    {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

      switch(action)
      {
        case GLFW_PRESS:
        {
          KeyPressedEvent event(key, 0);
          data.eventCallback(event);
          break;
        }
        case GLFW_RELEASE:
        {
          KeyPressedEvent event(key, 0);
          data.eventCallback(event);
          break;
        }
        case GLFW_REPEAT:
        {
          KeyPressedEvent event(key, 1);
          data.eventCallback(event);
          break;
        }
      }
    });

    glfwSetWindowCloseCallback(m_Window, [](GLFWwindow* window)
    {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
      WindowCloseEvent event;
      data.eventCallback(event);
    });

    glfwSetWindowSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
    {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

      data.width = width; 
      data.height = height;
      

      WindowResizeEvent event(width, height);
      data.eventCallback(event);
    });

    glfwSetScrollCallback(m_Window, [](GLFWwindow* window, double xoffset, double yoffset)
    {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));
      
      MouseScrolledEvent event(xoffset, yoffset);
      data.eventCallback(event);
    });

    glfwSetCursorPosCallback(m_Window, [](GLFWwindow* window, double xpos, double ypos)
    {
      WindowData& data = *static_cast<WindowData*>(glfwGetWindowUserPointer(window));

      MouseMovedEvent event(xpos, ypos);
      data.eventCallback(event);
    });

    glfwSetFramebufferSizeCallback(m_Window, [](GLFWwindow* window, int width, int height)
    {
      glViewport(0, 0, width, height);
    });
  }
      
       
   


  void UbuntuWindow::Shutdown()
  {
    glfwDestroyWindow(m_Window);
  }


  void UbuntuWindow::onUpdate()
  {
    glfwPollEvents();
    glfwSwapBuffers(m_Window);
  }


  void UbuntuWindow::setVSync(bool enabled)
  {
    if(enabled) glfwSwapInterval(1);
    else glfwSwapInterval(0);

    m_Data.VSync = enabled;
  }


  bool UbuntuWindow::isVSync() const
  {
    return m_Data.VSync;
  }

}
  
