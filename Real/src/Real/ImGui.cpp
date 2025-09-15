#include "ImGui.h"
#include "Core.h"


namespace Real {

  ImGui::ImGui() 
  {
  }


  void ImGui::Init() 
  {
    REAL_ASSERT(IMGUI_CHECKVERSION());
    ImGui::CreateContext();

    io = ImGui::GetIO(); 
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableKeyboard;     // Enable Keyboard Controls
    io.ConfigFlags |= ImGuiConfigFlags_NavEnableGamepad;      // Enable Gamepad Controls
                                                              
    ImGui::StyleColorsDark();

  }


  void ImGui::Shutdown()
  {
    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
  }


};
