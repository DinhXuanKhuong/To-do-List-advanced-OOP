// // #ifndef TASK_MANAGER_H
// // #define TASK_MANAGER_H

#ifndef TASK_MANAGER_H
#define TASK_MANAGER_H

#include <vector>
#include <memory>
#include <algorithm>
#include "Observer.h"
#include "Task.h"
#include "Subject.h"

class TaskManager : public Subject {
private:
    std::vector<std::shared_ptr<Task> > _tasks; // Store tasks as shared_ptr

public:
    TaskManager(std::vector<std::shared_ptr<Task> > tasks){
        _tasks = tasks;
    }

    ~TaskManager() {
        // 
    }
    std::vector<std::shared_ptr<Task> > getTasks() const {
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

};

#endif // TASK_MANAGER_H