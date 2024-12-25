// RemoveTaskCommand.cpp
#include "RemoveTaskCommand.h"
#include "TaskManager.h"

RemoveTaskCommand::RemoveTaskCommand(TaskManager &manager, const std::string &taskTitle)
    : _manager(manager), _taskTitle(taskTitle) {}

void RemoveTaskCommand::Execute() {
    _manager.RemoveTask(_taskTitle);
}
