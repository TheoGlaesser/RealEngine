
#include "../../Real/src/Real.h"

class ExampleLayer : public  Real::Layer 
{
public:
  ExampleLayer() : Layer("Example Layer")
  {
  }

  void onEvent(Real::Event& e) override {
    REAL_INFO("Event ", e.toString());
  }

  void onUpdate() override {
    REAL_INFO("Example Layer updated");
  }
};





class Sandbox : public Real::Application
{
	public:
		Sandbox() {
      pushLayer(new ExampleLayer());
		}

		~Sandbox() {

		}
};


Real::Application* Real::createApplication() {
	return new Sandbox();
}
	

