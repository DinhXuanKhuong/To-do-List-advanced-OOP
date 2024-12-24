#ifndef COMMAND_H
#define COMMAND_H

#include "TaskManager.h"

// Base Command class
class Command {
public:
    virtual ~Command() = default;
    virtual void Execute() = 0;
};

// Concrete Command to add a task
class AddTaskCommand : public Command {
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

// Concrete Command to remove a task
class RemoveTaskCommand : public Command {
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

// Concrete Command to mark a task as completed
class CompleteTaskCommand : public Command {
private:
    TaskManager &_manager;
    std::string _taskTitle;

public:
    CompleteTaskCommand(TaskManager &manager, const std::string &taskTitle)
        : _manager(manager), _taskTitle(taskTitle) {}

    void Execute() override {
        _manager.MarkTaskCompleted(_taskTitle);
    }
};

#endif // COMMAND_H