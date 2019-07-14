#pragma once
#include "Core.h"

namespace Lmq
{
	class LMQ_API Application
	{
	public:
		Application();
		virtual ~Application();

		void Run();
	};

	// To be defined in client

	Application* CreateApplication();
}


