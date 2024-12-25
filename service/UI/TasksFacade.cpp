// TasksFacade.cpp
#include "TasksFacade.h"
#include <iostream>
#include <memory>

TasksFacade::TasksFacade() : _manager({}), _tableConverter({}, {}), _textFileDao(""), _keyboardDao() {}

void TasksFacade::TodoList(const std::string &filePath) {
    std::shared_ptr<TextFileDao> FileDao = std::make_shared<TextFileDao>(filePath);
    std::vector<std::shared_ptr<Task>> tasks = FileDao->getAllTasks();
    _manager = TaskManager(tasks);
    _manager.Attach(&_consoleLogger);
    _tableConverter = TasksToTableConverter({"NO.", "Title", "Completed"}, {5, 50, 20});
    int input;
    while (true) {
        printMenu();
        std::cin >> input;
        std::cin.ignore();
        if (input == 1) {
            std::vector<std::shared_ptr<Task>> enteredTasks = _keyboardDao.getAllTasks();
            for (auto task : enteredTasks) {
                AddTaskCommand addTaskCommand(_manager, task->GetTitle());
                addTaskCommand.Execute();
            }
            FileDao->saveAllTasks(_manager.getTasks());

        } else if (input == 2) {
            std::string title;
            std::cout << "Enter the title of the task you want to remove: ";
            std::getline(std::cin, title);
            RemoveTaskCommand removeTaskCommand(_manager, title);
            removeTaskCommand.Execute();
            FileDao->saveAllTasks(_manager.getTasks());
        } else if (input == 3) {
            std::string title;
            std::cout << "Enter the title of the task you want to mark as completed: ";
            std::getline(std::cin, title);
            CompleteTaskCommand completeTaskCommand(_manager, title);
            completeTaskCommand.Execute();
            FileDao->saveAllTasks(_manager.getTasks());
        } else if (input == 4) {
            std::cout << _tableConverter.convert(_manager.getTasks(), "TODO List");
        } else if (input == 5) {
            FileDao->saveAllTasks(_manager.getTasks());
            _consoleLogger.Update("Exiting the program");
            break;
        }
    }
}

void TasksFacade::printMenu() {
    std::cout << "-----------------------\n";
    std::cout << "Choose a number in menu below: \n";
    std::cout << "1. Add Task\n";
    std::cout << "2. Remove Task\n";
    std::cout << "3. Mark Task as Completed\n";
    std::cout << "4. Display Tasks\n";
    std::cout << "5. Exit\n";

    std::cout << "Your choice: ";
}

std::string TasksFacade::toString() const {
    return "TasksFacade";
}
