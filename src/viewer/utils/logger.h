//
//  Create by AhrenLi (https://github.com/AhrenLi) on 2024/09/28.
//

#pragma once

#include "../hv.h"

#include <spdlog/spdlog.h>

HV_NS_OPEN

#define LOG_NAME "hv_log"

#define LOG_TRACE(...) SPDLOG_LOGGER_CALL(spdlog::get(LOG_NAME), spdlog::level::trace, __VA_ARGS__)
#define LOG_DEBUG(...) SPDLOG_LOGGER_CALL(spdlog::get(LOG_NAME), spdlog::level::debug, __VA_ARGS__)
#define LOG_INFO(...) SPDLOG_LOGGER_CALL(spdlog::get(LOG_NAME), spdlog::level::info, __VA_ARGS__)
#define LOG_WARN(...) SPDLOG_LOGGER_CALL(spdlog::get(LOG_NAME), spdlog::level::warn, __VA_ARGS__)
#define LOG_ERROR(...) SPDLOG_LOGGER_CALL(spdlog::get(LOG_NAME), spdlog::level::err, __VA_ARGS__)
#define LOG_CRITICAL(...) SPDLOG_LOGGER_CALL(spdlog::get(LOG_NAME), spdlog::level::critical, __VA_ARGS__)

class Logger {

public:
	enum LogLevel
	{
		LEVEL_TRACE = 0,
		LEVEL_DEBUG = 1,
		LEVEL_INFO = 2,
		LEVEL_WARN = 3,
		LEVEL_ERROR = 4,
		LEVEL_CRITICAL = 5,
		LEVEL_OFF = 6,
	};

	explicit Logger(LogLevel level = LogLevel::LEVEL_TRACE);

	~Logger();

private:
	std::shared_ptr<spdlog::logger> mLogger;
};

HV_NS_CLOSE