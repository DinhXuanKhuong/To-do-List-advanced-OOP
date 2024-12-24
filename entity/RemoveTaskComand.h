#ifndef REMOVE_TASK_COMMAND_H
#define REMOVE_TASK_COMMAND_H
#include "ICommand.h"

// Concrete Command to remove a task
class RemoveTaskCommand : public ICommand {
private:
    TaskManager &_manager;
    std::string _taskTitle;

public:
    RemoveTaskCommand(TaskManager &manager, const std::string &taskTitle)
        : _manager(manager), _taskTitle(taskTitle) {}

    void Execute() override {
        _manager.RemoveTask(_taskTitle);
    }
};

#endif // REMOVE_TASK_COMMAND_H