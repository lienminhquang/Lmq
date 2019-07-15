#pragma once
#include "../Lmq.h"

#ifdef LMQ_PLATFORM_WINDOWS

extern Lmq::Application* Lmq::CreateApplication();

int main(int argc, char** argv)
{
	
	Lmq::Log::init();
	
	LMQ_CORE_WARN("Initialized logg!");
	int a = 5;
	LMQ_INFO("Hello! Var={0}", a);


	auto app = Lmq::CreateApplication();
	app->Run();

	delete app;
}

#endif // LMQ_PLATFORM_WINDOW
