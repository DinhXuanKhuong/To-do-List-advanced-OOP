#ifndef COMMAND_H
#define COMMAND_H

#include "TaskManager.h"

// Base Command class
class ICommand {
public:
    virtual ~ICommand() = default;
    virtual void Execute() = 0;
};

#endif // COMMAND_H