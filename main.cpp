#include "logger.h"

int main() {
    int value = 42;
    std::string message = "Hello, Logger!";
    double pi = 3.14159;

    // Example usage
    log(LogLevel::Debug, "Debugging value:", value);
    log(LogLevel::Info, "Message:", message);
    log(LogLevel::Warning, "Pi value is approximately:", pi);
    log(LogLevel::Error, "An error occurred with value:", value, "and message:", message);

    return 0;
}
