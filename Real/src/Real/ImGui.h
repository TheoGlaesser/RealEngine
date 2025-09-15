#pragma once
#include "../../vendor/imgui/imgui.h"
#include "../../vendor/imgui/imgui_impl_glfw.h"
#include "../../vendor/imgui/mgui_impl_opengl3.h"


namespace Real  {

  class ImGui 
  {
    public:
      ImGui();

      void Init();
      void InitGlfw();
      void InitOpenGl();

      void Shutdown();

    private:
      ImGuiIO& io
  };

};
