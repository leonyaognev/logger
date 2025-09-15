#pragma once

enum class LogLevel { TRACE, INFO, WARN, ERROR };

// Цвета ANSI
#define CLR_TRACE "\033[90m"
#define CLR_INFO "\033[32m"
#define CLR_WARN "\033[33m"
#define CLR_ERROR "\033[31m"
#define CLR_RESET "\033[0m"

#ifdef DEBUG
#define LOG_TRACE(fmt, ...)                                                    \
  logMessage(LogLevel::TRACE, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_INFO(fmt, ...)                                                     \
  logMessage(LogLevel::INFO, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_WARN(fmt, ...)                                                     \
  logMessage(LogLevel::WARN, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#define LOG_ERROR(fmt, ...)                                                    \
  logMessage(LogLevel::ERROR, __FILE__, __func__, __LINE__, fmt, ##__VA_ARGS__)
#else
#define LOG_TRACE(fmt, ...)
#define LOG_INFO(fmt, ...)
#define LOG_WARN(fmt, ...)
#define LOG_ERROR(fmt, ...)
#endif
