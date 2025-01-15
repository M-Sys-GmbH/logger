#ifndef LOGGER_H
#define LOGGER_H

#include <iostream>
#include <sstream>
#include <string>
#include <mutex>
#include <chrono>
#include <iomanip>

enum class LogLevel {
    Debug,
    Info,
    Warning,
    Error
};

inline std::string logLevelToString(LogLevel level) {
    switch (level) {
        case LogLevel::Debug: return "\033[36m[DEBUG]\033[0m";    // Cyan
        case LogLevel::Info: return "\033[32m[INFO]\033[0m";     // Green
        case LogLevel::Warning: return "\033[33m[WARNING]\033[0m"; // Yellow
        case LogLevel::Error: return "\033[31m[ERROR]\033[0m";   // Red
        default: return "[UNKNOWN]";
    }
}

inline std::string getCurrentTimestamp() {
    auto now = std::chrono::system_clock::now();
    auto timeT = std::chrono::system_clock::to_time_t(now);
    auto localTime = std::localtime(&timeT);

    std::ostringstream ss;
    ss << std::put_time(localTime, "%Y-%m-%d %H:%M:%S");
    return ss.str();
}

// Thread-safe logging function
template <typename... Args>
void log(LogLevel level, const Args&... args) {
    static std::mutex logMutex;
    std::lock_guard<std::mutex> lock(logMutex);

    std::ostringstream ss;

    // Add timestamp and log level
    ss << "[" << getCurrentTimestamp() << "] " << logLevelToString(level);

    // Expand parameter pack into the stream
    (void)std::initializer_list<int>{(ss << " " << args, 0)...};

    // Print the final log message
    std::cout << ss.str() << std::endl;
}

#endif // LOGGER_H
