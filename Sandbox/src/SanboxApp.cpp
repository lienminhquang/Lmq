#include <Lmq.h>

class Sandbox : public Lmq::Application
{
public:

	Sandbox()
	{

	}

	~Sandbox()
	{

	}
};

Lmq::Application* Lmq::CreateApplication()
{
	return new Sandbox();
}