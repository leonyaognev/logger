#pragma once

#include "logger.h"

static const char *levelToStr(LogLevel lvl) {
  switch (lvl) {
  case LogLevel::TRACE:
    return "TRACE";
  case LogLevel::INFO:
    return "INFO";
  case LogLevel::WARN:
    return "WARN";
  case LogLevel::ERROR:
    return "ERROR";
  default:
    return "UNKNOWN";
  }
}

static const char *levelToColor(LogLevel lvl) {
  switch (lvl) {
  case LogLevel::TRACE:
    return CLR_TRACE;
  case LogLevel::INFO:
    return CLR_INFO;
  case LogLevel::WARN:
    return CLR_WARN;
  case LogLevel::ERROR:
    return CLR_ERROR;
  default:
    return CLR_RESET;
  }
}
