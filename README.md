# Logger Utility

A modern, lightweight C++ logging utility with support for multiple log levels (Debug, Info, Warning, Error). Features include timestamped log messages, color-coded output, and the ability to log multiple values in one statement - all without requiring a dedicated logger object. Perfect for debugging and monitoring applications in style!

## Features

- **Log Levels**: Debug, Info, Warning, Error.
- **Timestamps**: Automatically adds a timestamp to each log entry.
- **Multiple Values**: Log multiple values in a single statement.
- **Color-Coded Output**: Log levels are color-coded for better visibility.

## Getting Started

### Prerequisites

- C++ compiler with support for C++20 or later.
- `make` build system.

### Building the Project

1. Clone or copy the project files into a directory.
2. Navigate to the directory in your terminal.
3. Use the following command to build the project:
   ```bash
   make
   ```

### Running the Program

Once built, you can run the program using:
```bash
./logger
```

### Cleaning Up

To remove the compiled binary, run:
```bash
make clean
```

## Logging Example

Here's how you can use the logging utility:

```cpp
#include "logger.h"

int main() {
    int testValue = 42;
    std::string testStr = "Hello, logger!";
    double testDouble = 3.14159;

    log(LogLevel::Debug, "This is a debug message.");
    log(LogLevel::Info, "Multiple values:", testValue, testStr, testDouble);
    log(LogLevel::Warning, "A warning occurred.");
    log(LogLevel::Error, "An error message with a value:", testValue);

    return 0;
}
```

### Sample Output

```text
[2025-01-15 12:00:00] [DEBUG] This is a debug message.
[2025-01-15 12:00:01] [INFO] Multiple values: 42 Hello, logger! 3.14159
[2025-01-15 12:00:02] [WARNING] A warning occurred.
[2025-01-15 12:00:03] [ERROR] An error message with a value: 42
```

Log levels are color-coded in the console:
- **DEBUG**: Cyan
- **INFO**: Green
- **WARNING**: Yellow
- **ERROR**: Red

## Project Structure

```plaintext
Logger/
├── logger.h        # Logging utility header
├── main.cpp        # Example usage
├── Makefile        # Build system configuration
└── README.md       # Project documentation
```

## Customization

You can modify the log level names, colors, or timestamp format in `logger.h` to suit your preferences.

## License

This project is open source. Feel free to use and modify it for your own purposes.
