// ConsoleLogger.cpp
#include "ConsoleLogger.h"

void ConsoleLogger::Update(const std::string &message) {
    std::cout << "[LOG]: " << message << "\n";
}
