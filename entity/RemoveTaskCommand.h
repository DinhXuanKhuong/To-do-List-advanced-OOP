// RemoveTaskCommand.h
#ifndef REMOVETASKCOMMAND_H
#define REMOVETASKCOMMAND_H
#include "ICommand.h"

// Concrete Command to remove a task
class RemoveTaskCommand : public ICommand {
private:
    TaskManager &_manager;
    std::string _taskTitle;

public:
    RemoveTaskCommand(TaskManager &manager, const std::string &taskTitle);

    void Execute() override;
};

#endif // REMOVETASKCOMMAND_H
