#pragma once
#include "../Lmq.h"

#ifdef LMQ_PLATFORM_WINDOWS

extern Lmq::Application* Lmq::CreateApplication();

int main(int argc, char** argv)
{
	printf("Lmq engine!");
	auto app = Lmq::CreateApplication();
	app->Run();

	delete app;
}

#endif // LMQ_PLATFORM_WINDOW
