# Compiler
CXX = g++
CXXFLAGS = -std=c++20 -Wall -Wextra -pedantic -O2

# Target executable
TARGET = logger

# Source and header files
SRCS = main.cpp
HEADERS = logger.h

# Build rules
all: $(TARGET)

$(TARGET): $(SRCS) $(HEADERS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS)

# Clean rule
clean:
	rm -f $(TARGET)

# Phony targets
.PHONY: all clean
