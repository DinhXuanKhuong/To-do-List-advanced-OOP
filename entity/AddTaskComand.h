#ifndef ADD_TASK_COMMAND_H
#define ADD_TASK_COMMAND_H

#include "ICommand.h"

// Concrete Command to add a task
class AddTaskCommand : public ICommand {
private:
    TaskManager &_manager;
    std::string _taskTitle;

public:
    AddTaskCommand(TaskManager &manager, const std::string &taskTitle)
        : _manager(manager), _taskTitle(taskTitle) {}

    void Execute() override {
        _manager.AddTask(_taskTitle);
    }
};

#endif // ADD_TASK_COMMAND_H