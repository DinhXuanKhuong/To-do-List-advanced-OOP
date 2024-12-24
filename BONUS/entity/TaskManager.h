// // #ifndef TASK_MANAGER_H
// // #define TASK_MANAGER_H

// // #include "Observer.h"
// // #include "Task.h"
// // #include <vector>
// // #include <algorithm>

// // class TaskManager : public Subject {
// // private:
// //     std::vector<Task> _tasks;

// // public:
// //     void AddTask(const std::string &title) {
// //         _tasks.emplace_back(title);
// //         Notify("Added task: " + title);
// //     }

// //     void RemoveTask(const std::string &title) {
// //         auto it = std::remove_if(_tasks.begin(), _tasks.end(),
// //                                  [&](const Task &task) { return task.GetTitle() == title; });
// //         if (it != _tasks.end()) {
// //             Notify("Removed task: " + title);
// //             _tasks.erase(it, _tasks.end());
// //         }
// //     }

// //     void MarkTaskCompleted(const std::string &title) {
// //         for (Task &task : _tasks) {
// //             if (task.GetTitle() == title) {
// //                 task.MarkCompleted();
// //                 Notify("Marked task as completed: " + title);
// //                 return;
// //             }
// //         }
// //     }

// //     void DisplayTasks() const {
// //         std::cout << "TODO List:\n";
// //         for (const Task &task : _tasks) {
// //             task.Display();
// //         }
// //     }
// // };

// // #endif // TASK_MANAGER_H 

// #ifndef TASK_MANAGER_H
// #define TASK_MANAGER_H

// #include <vector>
// #include <algorithm>
// #include <memory> // For shared_ptr

// #include "Observer.h"
// #include "Task.h"
// #include "../services/data-access/IDao.h"

// class TaskManager : public Subject {
// private:
//     std::vector<Task> _tasks;
//     std::shared_ptr<IDao> _dao; // Use shared_ptr instead of unique_ptr

// public:
//     explicit TaskManager(std::shared_ptr<IDao> dao) : _dao(std::move(dao)) {
//         if (_dao) {
//             _tasks = _dao->getAllTasks(); // Load tasks from DAO
//         }
//     }

//     ~TaskManager() {
//         if (_dao) {
//             _dao->saveAllTasks(_tasks); // Save tasks back to DAO on destruction
//         }
//     }

//     void AddTask(const std::string& title) {
//         _tasks.emplace_back(title);
//         Notify("Added task: " + title);
//         if (_dao) _dao->saveAllTasks(_tasks);
//     }

//     void RemoveTask(const std::string& title) {
//         auto it = std::remove_if(_tasks.begin(), _tasks.end(),
//                                  [&](const Task& task) { return task.GetTitle() == title; });
//         if (it != _tasks.end()) {
//             Notify("Removed task: " + title);
//             _tasks.erase(it, _tasks.end());
//             if (_dao) _dao->saveAllTasks(_tasks);
//         }
//     }

//     void MarkTaskCompleted(const std::string& title) {
//         for (Task& task : _tasks) {
//             if (task.GetTitle() == title) {
//                 task.MarkCompleted();
//                 Notify("Marked task as completed: " + title);
//                 if (_dao) _dao->saveAllTasks(_tasks);
//                 return;
//             }
//         }
//     }

//     void DisplayTasks() const {
//         std::cout << "TODO List:\n";
//         for (const Task& task : _tasks) {
//             std::cout << "\t";
//             task.Display();
//         }
//     }
// };
// #endif // TASK_MANAGER_H 


#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Observer.h"
#include "Task.h"

class TaskManager : public Subject {
private:
    std::vector<std::shared_ptr<Task>> _tasks; // Store tasks as shared_ptr

public:
    TaskManager(std::vector<std::shared_ptr<Task>> tasks){
        _tasks = tasks;
    }

    ~TaskManager() {
        
    }
    std::vector<std::shared_ptr<Task>> getTasks() const {
        return _tasks;
    }

    void AddTask(const std::string& title) {
        _tasks.push_back(std::make_shared<Task>(title));
        Notify("Added task: " + title);
    }

    void RemoveTask(const std::string& title) {
        auto it = std::remove_if(_tasks.begin(), _tasks.end(),
                                 [&](const std::shared_ptr<Task>& task) { return task->GetTitle() == title; });
        if (it != _tasks.end()) {
            Notify("Removed task: " + title);
            _tasks.erase(it, _tasks.end());
        }
    }

    void MarkTaskCompleted(const std::string& title) {
        for (auto& task : _tasks) {
            if (task->GetTitle() == title) {
                task->MarkCompleted();
                Notify("Marked task as completed: " + title);
                return;
            }
        }
    }

    void DisplayTasks() const {
        std::cout << "TODO List:\n";
        for (const auto& task : _tasks) {
            std::cout << "\t";
            task->Display();
        }
    }
};

#endif // TASK_MANAGER_H