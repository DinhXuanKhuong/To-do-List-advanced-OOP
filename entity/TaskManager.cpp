// TaskManager.cpp
#include "TaskManager.h"

TaskManager::TaskManager(std::vector<std::shared_ptr<Task>> tasks)
    : _tasks(std::move(tasks)) {}

TaskManager::~TaskManager() {
    // Destructor: no special cleanup needed due to smart pointers
}

std::vector<std::shared_ptr<Task>> TaskManager::getTasks() const {
    return _tasks;
}

void TaskManager::AddTask(const std::string &title) {
    _tasks.push_back(std::make_shared<Task>(title));
    Notify("Added task: " + title);
}

void TaskManager::RemoveTask(const std::string &title) {
    auto it = std::remove_if(_tasks.begin(), _tasks.end(),
                             [&](const std::shared_ptr<Task> &task) { return task->GetTitle() == title; });
    if (it != _tasks.end()) {
        Notify("Removed task: " + title);
        _tasks.erase(it, _tasks.end());
    }
}

void TaskManager::MarkTaskCompleted(const std::string &title) {
    for (auto &task : _tasks) {
        if (task->GetTitle() == title) {
            task->MarkCompleted();
            Notify("Marked task as completed: " + title);
            return;
        }
    }
}
