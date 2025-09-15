#include <cstdarg>
#include <ctime>
#include <fstream>
#include <iostream>
#include <mutex>

#include "levelTo.h"
#include "logger.h"

static std::ofstream logFile;
static std::mutex logMutex;

void logMessage(LogLevel level, const char *file, const char *func, int line,
                const char *fmt, ...) {
  std::lock_guard<std::mutex> lock(logMutex);

  if (!logFile.is_open()) {
    logFile.open("matrix.log", std::ios::app);
  }

  std::time_t t = std::time(nullptr);
  std::tm tm_info{};
  localtime_r(&t, &tm_info);

  char timeBuf[20];
  std::strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", &tm_info);

  char userBuf[1024];
  va_list args;
  va_start(args, fmt);
  vsnprintf(userBuf, sizeof(userBuf), fmt, args);
  va_end(args);

  std::cout << levelToColor(level) << "[" << levelToStr(level) << "] "
            << CLR_RESET << timeBuf << " " << file << ":" << line << " " << func
            << "(): " << userBuf << std::endl;

  if (logFile.is_open()) {
    logFile << "[" << levelToStr(level) << "] " << timeBuf << " " << file << ":"
            << line << " " << func << "(): " << userBuf << std::endl;
  }
}
