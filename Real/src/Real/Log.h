#pragma once

#include <memory>

#include "Core.h"
#include "spdlog/spdlog.h"

namespace Real {

	class REAL_API Log 
	{
		public:
			static void Init();

			inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() {return s_CoreLogger;}
			inline static std::shared_ptr<spd::logger>& GetClientLogger() {return s_ClientLogger;}



	};
