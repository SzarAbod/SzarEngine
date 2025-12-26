#include <log.hpp>

#include <spdlog/sinks/stdout_color_sinks.h>
#include <spdlog/sinks/basic_file_sink.h>

namespace szar
{
	std::shared_ptr<spdlog::logger> Log::s_CoreLogger;
	std::shared_ptr<spdlog::logger> Log::s_ClientLogger;
	
	/**
	 * @brief Initializes the global logging subsystem for the application.
	 *
	 * Configures a global log pattern, creates a colorized console sink (warnings and above)
	 * and a file sink that writes to "logs.txt", and then constructs two loggers:
	 * the core logger named "Szar" and the client logger named "Game". Both loggers are set
	 * to the trace level and share the configured sinks.
	 */
	void Log::Init()
	{
		spdlog::set_pattern("%^[%T] %n: %v%$");
		
		auto consoleLogger = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
		auto fileLogger = std::make_shared<spdlog::sinks::basic_file_sink_mt>("logs.txt", true);

		consoleLogger->set_pattern("%^[%T] %n: %v%$");
		consoleLogger->set_level(spdlog::level::warn);

		fileLogger->set_pattern("[%T] [%l] %n: %v");

		std::vector<spdlog::sink_ptr> sinks{ consoleLogger, fileLogger };

		s_CoreLogger = std::make_shared<spdlog::logger>("Szar", sinks.begin(), sinks.end());
		s_ClientLogger = std::make_shared<spdlog::logger>("Game", sinks.begin(), sinks.end());

		s_CoreLogger->set_level(spdlog::level::trace);
		s_ClientLogger->set_level(spdlog::level::trace);
	}
}