#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H
#include <iostream>
#include <string>

#include "IObserver.h"
#include "Subject.h"    
// Observer Implementation: Console Logger
class ConsoleLogger : public IObserver {
public:
    void Update(const std::string& message) override {
        std::cout << "[LOG]: " << message << "\n";
    }
};

#endif // CONSOLE_LOGGER_H