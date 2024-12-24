#ifndef CONSOLE_LOGGER_H
#define CONSOLE_LOGGER_H
#include <iostream>
#include <string>

#include "Observer.h"
#include "Subject.h"    
// Observer Implementation: Console Logger
class ConsoleLogger : public Observer {
public:
    void Update(const std::string& message) override {
        std::cout << "[LOG]: " << message << "\n";
    }
};

#endif // CONSOLE_LOGGER_H