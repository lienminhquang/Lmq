#pragma once

#ifdef LMQ_PLATFORM_WINDOWS
	#ifdef LMQ_BUILD_DLL
		#define LMQ_API __declspec(dllexport)
	#else
		#define LMQ_API __declspec(dllimport)
	#endif // 
#else
	#error Lmq only support Windows!
#endif // LMQ_PLATFORM_WINDOWS

