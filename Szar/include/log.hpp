#ifndef SZAR_LOG_HPP
#define SZAR_LOG_HPP

#include <core.hpp>

#include <memory>

#include <spdlog/spdlog.h>

#define SZAR_CORE_TRACE(...)    do { if(auto& logger = szar::Log::GetCoreLogger()) logger->trace(__VA_ARGS__); } while(0)
#define SZAR_CORE_DEBUG(...)    do { if(auto& logger = szar::Log::GetCoreLogger()) logger->debug(__VA_ARGS__); } while(0)
#define SZAR_CORE_INFO(...)     do { if(auto& logger = szar::Log::GetCoreLogger()) logger->info(__VA_ARGS__); } while(0)
#define SZAR_CORE_WARN(...)     do { if(auto& logger = szar::Log::GetCoreLogger()) logger->warn(__VA_ARGS__); } while(0)
#define SZAR_CORE_ERROR(...)    do { if(auto& logger = szar::Log::GetCoreLogger()) logger->error(__VA_ARGS__); } while(0)
#define SZAR_CORE_FATAL(...)    do { if(auto& logger = szar::Log::GetCoreLogger()) logger->critical(__VA_ARGS__); } while(0)

#define SZAR_CLIENT_TRACE(...)  do { if(auto& logger = szar::Log::GetClientLogger()) logger->trace(__VA_ARGS__); } while(0)
#define SZAR_CLIENT_DEBUG(...)  do { if(auto& logger = szar::Log::GetClientLogger()) logger->debug(__VA_ARGS__); } while(0)
#define SZAR_CLIENT_INFO(...)   do { if(auto& logger = szar::Log::GetClientLogger()) logger->info(__VA_ARGS__); } while(0)
#define SZAR_CLIENT_WARN(...)   do { if(auto& logger = szar::Log::GetClientLogger()) logger->warn(__VA_ARGS__); } while(0)
#define SZAR_CLIENT_ERROR(...)  do { if(auto& logger = szar::Log::GetClientLogger()) logger->error(__VA_ARGS__); } while(0)
#define SZAR_CLIENT_FATAL(...)  do { if(auto& logger = szar::Log::GetClientLogger()) logger->critical(__VA_ARGS__); } while(0)

namespace szar 
{
	class SZ_DECLSPEC Log
	{
	public:
		static void Init();

		inline static std::shared_ptr<spdlog::logger>& GetCoreLogger() { return s_CoreLogger; }
		inline static std::shared_ptr<spdlog::logger>& GetClientLogger() { return s_ClientLogger; }

	private:
		static std::shared_ptr<spdlog::logger> s_CoreLogger;
		static std::shared_ptr<spdlog::logger> s_ClientLogger;
	};
}

#endif // !SZAR_LOG_HPP
