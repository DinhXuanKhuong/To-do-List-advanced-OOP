// ConsoleLogger.h
#ifndef CONSOLELOGGER_H
#define CONSOLELOGGER_H
#include <iostream>
#include <string>

#include "IObserver.h"
#include "Subject.h"    
// Observer Implementation: Console Logger
class ConsoleLogger : public IObserver {
public:
    void Update(const std::string& message) override;
};

#endif // CONSOLELOGGER_H
