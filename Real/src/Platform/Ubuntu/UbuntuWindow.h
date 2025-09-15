#pragma once

#include "Real/Window.h"

#include <GLFW/glfw3.h>


namespace Real {

  class UbuntuWindow : public Window
  {
  public:
    UbuntuWindow(const WindowProps& props);
    virtual ~UbuntuWindow();

    void onUpdate() override;

    inline unsigned int getWidth() const override {return m_Data.width;}
    inline unsigned int getHeight() const override {return m_Data.width;}

    //Window attributes
    inline void setEventCallback(const eventCallbackFn& callback) override {m_Data.eventCallback = callback;}
    void setVSync(bool enabled) override;
    bool isVSync() const override;
  private:
    virtual void Init(const WindowProps& props);
    virtual void Shutdown();
  private:
    GLFWwindow* m_Window;

    struct WindowData
    {
      std::string title; 
      int width, height;
      bool VSync;

      eventCallbackFn eventCallback;
    };

    WindowData m_Data;
  };

}
