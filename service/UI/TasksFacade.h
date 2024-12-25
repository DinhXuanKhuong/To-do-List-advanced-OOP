// TasksFacade.h
#ifndef TASKSFACADE_H
#define TASKSFACADE_H

#include "../../entity/Object.h"
#include "../data-access/KeyboardDao.h"
#include "../data-access/TextFileDao.h"
#include "TasksToTableConverter.h"
#include "../../entity/ICommand.h"
#include "../../entity/AddTaskCommand.h"
#include "../../entity/RemoveTaskCommand.h"
#include "../../entity/CompleteTaskCommand.h"
#include "../../entity/ConsoleLogger.h"

class TasksFacade : public Object {
private:
    TaskManager _manager;
    TasksToTableConverter _tableConverter;
    TextFileDao _textFileDao;
    KeyboardDao _keyboardDao;
    ConsoleLogger _consoleLogger;

public:
    TasksFacade();
    void TodoList(const std::string &filePath);
    void printMenu();
    std::string toString() const override;
};

#endif // TASKSFACADE_H
