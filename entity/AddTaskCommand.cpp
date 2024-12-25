// AddTaskCommand.cpp
#include "AddTaskCommand.h"
#include "TaskManager.h"

AddTaskCommand::AddTaskCommand(TaskManager &manager, const std::string &taskTitle)
    : _manager(manager), _taskTitle(taskTitle) {}

void AddTaskCommand::Execute() {
    _manager.AddTask(_taskTitle);
}
