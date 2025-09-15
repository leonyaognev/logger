#include <cstdarg>
#include <ctime>
#include <fstream>
#include <iostream>
#include <mutex>

#include "levelTo.h"
#include "logger.h"

// Global ofstream object for logging to a file
static std::ofstream logFile;

// Mutex to synchronize access to logger in multithreaded environment
static std::mutex logMutex;

// -------------------------------------------------------------
// Main logging function
// level - log level (TRACE, INFO, WARN, ERROR)
// file  - source file name (__FILE__)
// func  - function name (__func__)
// line  - line number (__LINE__)
// fmt   - printf-style format string
// -------------------------------------------------------------
void logMessage(LogLevel level, const char *file, const char *func, int line,
                const char *fmt, ...) {

  // Lock the mutex to ensure thread safety for console and file output
  std::lock_guard<std::mutex> lock(logMutex);

  // Open log file in append mode if it's not already open
  if (!logFile.is_open()) {
    logFile.open(LOG_FILE, std::ios::app);
  }

  // Get current time
  std::time_t t = std::time(nullptr);
  std::tm tm_info{};
  localtime_r(&t, &tm_info); // Thread-safe conversion to local time

  // Format time as "YYYY-MM-DD HH:MM:SS"
  char timeBuf[20];
  std::strftime(timeBuf, sizeof(timeBuf), "%Y-%m-%d %H:%M:%S", &tm_info);

  // Format user-provided message with variable arguments
  char userBuf[1024];  // buffer for formatted message
  va_list args;        // variable argument list
  va_start(args, fmt); // initialize argument list
  vsnprintf(userBuf, sizeof(userBuf), fmt, args); // safely format string
  va_end(args);                                   // clean up

  // Output log to console with color for the log level
  std::cout << levelToColor(level) << "[" << levelToStr(level) << "] "
            << CLR_RESET // reset console color
            << timeBuf << " " << file << ":" << line << " " << func
            << "(): " << userBuf << std::endl;

  // Output log to file (without color)
  if (logFile.is_open()) {
    logFile << "[" << levelToStr(level) << "] " << timeBuf << " " << file << ":"
            << line << " " << func << "(): " << userBuf << std::endl;
  }
}
