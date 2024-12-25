// AddTaskCommand.h
#ifndef ADDTASKCOMMAND_H
#define ADDTASKCOMMAND_H

#include "ICommand.h"

// Concrete Command to add a task
class AddTaskCommand : public ICommand {
private:
    TaskManager &_manager;
    std::string _taskTitle;

public:
    AddTaskCommand(TaskManager &manager, const std::string &taskTitle);

    void Execute() override;
};

#endif // ADDTASKCOMMAND_H
