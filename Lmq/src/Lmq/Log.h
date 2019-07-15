#pragma once
#include "Core.h"
#include "spdlog/spdlog.h"
#include <memory>

namespace Lmq
{
	class LMQ_API Log
	{
	public:
		static void init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

//core log mascros
#define LMQ_CORE_ERROR(...) ::Lmq::Log::GetCoreLogger()->error(__VA_ARGS__)
#define LMQ_CORE_WARN(...) ::Lmq::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define LMQ_CORE_INFO(...) ::Lmq::Log::GetCoreLogger()->info(__VA_ARGS__)
#define LMQ_CORE_TRACE(...) ::Lmq::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define LMQ_CORE_FATAL(...) ::Lmq::Log::GetCoreLogger()->fatal(__VA_ARGS__)

//client log mascros
#define LMQ_ERROR(...)	::Lmq::Log::GetClientLogger()->error(__VA_ARGS__)
#define LMQ_WARN(...)	::Lmq::Log::GetClientLogger()->warn(__VA_ARGS__)
#define LMQ_INFO(...)	::Lmq::Log::GetClientLogger()->info(__VA_ARGS__)
#define LMQ_TRACE(...)	::Lmq::Log::GetClientLogger()->trace(__VA_ARGS__)
#define LMQ_FATAL(...)	::Lmq::Log::GetClientLogger()->fatal(__VA_ARGS__)

