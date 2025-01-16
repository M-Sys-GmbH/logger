#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <string>
#include <chrono>
#include <iomanip>
#include <sstream>
#include <syncstream>

enum class LogLevel { Debug, Info, Warning, Error };

// ANSI color codes
namespace LogColors {
    const std::string Reset = "\033[0m";
    const std::string Debug = "\033[36m";   // Cyan
    const std::string Info = "\033[32m";    // Green
    const std::string Warning = "\033[33m"; // Yellow
    const std::string Error = "\033[31m";   // Red
}

inline std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto time_t_now = std::chrono::system_clock::to_time_t(now);
    auto localtime = *std::localtime(&time_t_now);

    std::ostringstream ss;
    ss << std::put_time(&localtime, "[%Y-%m-%d %H:%M:%S]");
    return ss.str();
}

inline std::pair<std::string, std::string> getLogLevelInfo(LogLevel level) {
    switch (level) {
        case LogLevel::Debug:   return { "DEBUG", LogColors::Debug };
        case LogLevel::Info:    return { "INFO", LogColors::Info };
        case LogLevel::Warning: return { "WARNING", LogColors::Warning };
        case LogLevel::Error:   return { "ERROR", LogColors::Error };
        default:                return { "UNKNOWN", LogColors::Reset };
    }
}

template <typename... Args>
void log(LogLevel level, const Args&... args) {
    auto [levelStr, color] = getLogLevelInfo(level);
    std::osyncstream sync_out(std::cout);

    sync_out << getCurrentTimestamp() << " "
    << color << levelStr << LogColors::Reset << ": ";

    // Unpack and print all arguments
    ((sync_out << args << " "), ...);

    sync_out << "\n";
}

#endif // LOGGER_H
