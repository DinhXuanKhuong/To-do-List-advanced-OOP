// CompleteTaskCommand.cpp
#include "CompleteTaskCommand.h"
#include "TaskManager.h"

CompleteTaskCommand::CompleteTaskCommand(TaskManager &manager, const std::string &taskTitle)
    : _manager(manager), _taskTitle(taskTitle) {}

void CompleteTaskCommand::Execute() {
    _manager.MarkTaskCompleted(_taskTitle);
}
