#ifndef TASKSFACADE_H
#define TASKSFACADE_H


#include "../../entity/Object.h"

#include "../data-access/keyboardDao.h"
#include "../data-access/TextFileDao.h"
#include "TasksToTableConverter.h"
#include "../../entity/Command.h"
#include "../../entity/ConsoleLogger.h"

class TasksFacade : public Object {
private:
    TaskManager _manager; // 
    TasksToTableConverter _tableConverter; // 
    TextFileDao _textFileDao;
    KeyboardDao _keyboardDao; 
    // AddTaskCommand _addTaskCommand;
    // RemoveTaskCommand _removeTaskCommand;
    // CompleteTaskCommand _completeTaskCommand;
public:
    TasksFacade() : _manager({}), _tableConverter({}, {}), _textFileDao(""), _keyboardDao() {}
    void TodoList (const std::string& filePath) {

        std::shared_ptr<TextFileDao> FileDao = std::make_shared<TextFileDao>(filePath);
        // cout << "FileDao created\n";
        std::vector<std::shared_ptr<Task> > tasks = FileDao->getAllTasks();
        // cout << tasks.size();
        _manager = TaskManager(tasks);
        _tableConverter = TasksToTableConverter({"NO.","Title", "Completed"}, {5, 50, 20});
        int input;
        while (true) {
            printMenu();
            std::cin >> input;
            std::cin.ignore();
            if (input == 1) {
                vector<shared_ptr<Task> > enteredTasks = _keyboardDao.getAllTasks();
                for (auto task : enteredTasks) {
                    AddTaskCommand addTaskCommand(_manager, task->GetTitle());
                    addTaskCommand.Execute();
                }
                FileDao->saveAllTasks(_manager.getTasks());
            }
            else if (input == 2) {
                std::string title;
                std::cout << "Enter the title of the task you want to remove: ";
                std::getline(std::cin, title);
                RemoveTaskCommand removeTaskCommand(_manager, title);
                removeTaskCommand.Execute();
                FileDao->saveAllTasks(_manager.getTasks());
            }
            else if (input == 3) {
                std::string title;
                std::cout << "Enter the title of the task you want to mark as completed: ";
                std::getline(std::cin, title);
                CompleteTaskCommand completeTaskCommand(_manager, title);
                completeTaskCommand.Execute();
                FileDao->saveAllTasks(_manager.getTasks());
            }
            else if (input == 4) {
                std::cout << _tableConverter.convert(_manager.getTasks(), "TODO List");
            }
            else if (input == 5) {
                FileDao->saveAllTasks(_manager.getTasks());
                cout << "TO-DO LIST Saved. \nExiting the program\n";
                break;
            }
        
        }
    }
    void printMenu() {
        std::cout << "-----------------------\n";
        std::cout << "Choose a number in menu below: \n";
        std::cout << "1. Add Task\n";
        std::cout << "2. Remove Task\n";
        std::cout << "3. Mark Task as Completed\n";
        std::cout << "4. Display Tasks\n";
        std::cout << "5. Exit\n";

        cout << "Your choice: ";
    }
    string toString() const override {
        return "TasksFacade";
    }

};



#endif
