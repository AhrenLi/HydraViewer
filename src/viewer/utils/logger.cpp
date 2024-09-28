//
//  Create by AhrenLi (https://github.com/AhrenLi) on 2024/09/28.
//

#include "logger.h"

#include <spdlog/sinks/sink.h>
#include <spdlog/sinks/stdout_color_sinks.h>

HV_NS_OPEN

Logger::Logger(LogLevel level) {
	const char* format = "[%Y-%m-%d %H:%M:%S.%e] <Thread %t> [%^%l%$] [%@,%!] %v";
	auto consoleSink = std::make_shared<spdlog::sinks::stdout_color_sink_mt>();
	consoleSink->set_pattern(format);

	mLogger = std::make_shared<spdlog::logger>(LOG_NAME, consoleSink);
	mLogger->set_level((spdlog::level::level_enum)level);
	spdlog::register_logger(mLogger);
}

Logger::~Logger() {
	if (mLogger) {
		mLogger->flush();
	}
	spdlog::drop_all();
	spdlog::shutdown();
}

HV_NS_CLOSE