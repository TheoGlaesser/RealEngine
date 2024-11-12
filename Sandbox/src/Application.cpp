
#include "../../Real/src/Real.h"

class Sandbox : public Real::Application
{
	public:
		Sandbox() {

		}

		~Sandbox() {

		}

};


Real::Application* Real::createApplication() {
	return new Sandbox();
}
	

