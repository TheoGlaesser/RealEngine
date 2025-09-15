#pragma once



#include "Core.h"
#include "../../vendor/spdlog/include/spdlog/spdlog.h"
#include "spdlog/fmt/ostr.h"

namespace Real {

	class Log 
	{
		public:
			static void Init();
      

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger;}
			inline static std::shared_ptr<spdlog::logger>& GetClientLogger() {return s_ClientLogger;}

    private:
      static std::shared_ptr<spdlog::logger> s_CoreLogger;
      static std::shared_ptr<spdlog::logger> s_ClientLogger;


	};

}

#define REAL_CORE_ERROR(...)   ::Real::Log::GetCoreLogger()->error(__VA_ARGS__)
#define REAL_CORE_WARN(...)    ::Real::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define REAL_CORE_INFO(...)    ::Real::Log::GetCoreLogger()->info(__VA_ARGS__)
#define REAL_CORE_TRACE(...)   ::Real::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define REAL_CORE_FATAL(...)   ::Real::Log::GetCoreLogger()->fatal(__VA_ARGS__)


#define REAL_ERROR(...)   ::Real::Log::GetCoreLogger()->error(__VA_ARGS__)
#define REAL_WARN(...)    ::Real::Log::GetCoreLogger()->warn(__VA_ARGS__)
#define REAL_INFO(...)    ::Real::Log::GetCoreLogger()->info(__VA_ARGS__)
#define REAL_TRACE(...)   ::Real::Log::GetCoreLogger()->trace(__VA_ARGS__)
#define REAL_FATAL(...)   ::Real::Log::GetCoreLogger()->fatal(__VA_ARGS__)

