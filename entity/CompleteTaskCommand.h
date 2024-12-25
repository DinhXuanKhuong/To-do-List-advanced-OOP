// CompleteTaskCommand.h
#ifndef COMPLETETASKCOMMAND_H
#define COMPLETETASKCOMMAND_H

#include "ICommand.h"

// Concrete Command to mark a task as completed
class CompleteTaskCommand : public ICommand {
private:
    TaskManager &_manager;
    std::string _taskTitle;

public:
    CompleteTaskCommand(TaskManager &manager, const std::string &taskTitle);

    void Execute() override;
};

#endif // COMPLETETASKCOMMAND_H
