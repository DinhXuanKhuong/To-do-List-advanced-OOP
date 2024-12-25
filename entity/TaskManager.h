// TaskManager.h
#ifndef TASKMANAGER_H
#define TASKMANAGER_H

#include <vector>
#include <memory>
#include <algorithm>
#include "IObserver.h"
#include "Task.h"
#include "Subject.h"

class TaskManager : public Subject {
private:
    std::vector<std::shared_ptr<Task>> _tasks; // Store tasks as shared_ptr

public:
    TaskManager(std::vector<std::shared_ptr<Task>> tasks);

    ~TaskManager();

    std::vector<std::shared_ptr<Task>> getTasks() const;

    void AddTask(const std::string &title);
    void RemoveTask(const std::string &title);
    void MarkTaskCompleted(const std::string &title);
};

#endif // TASKMANAGER_H
