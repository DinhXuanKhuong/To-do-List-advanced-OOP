#include <iostream>
#include <vector>
#include <string>
#include <list>
#include <functional>
#include <memory>

// Observer Interface
class Observer {
public:
    virtual void Update(const std::string &message) = 0;
};

// Subject class for notifying observers
class Subject {
private:
    std::list<Observer *> observers_;

public:
    void Attach(Observer *observer) {
        observers_.push_back(observer);
    }

    void Detach(Observer *observer) {
        observers_.remove(observer);
    }

    void Notify(const std::string &message) {
        for (Observer *observer : observers_) {
            observer->Update(message);
        }
    }
};

// Task class
class Task {
private:
    std::string _title;
    bool _isCompleted;

public:
    explicit Task(const std::string &title) : _title(title), _isCompleted(false) {}

    void MarkCompleted() {
        _isCompleted = true;
    }

    std::string GetTitle() const {
        return _title;
    }

    bool IsCompleted() const {
        return _isCompleted;
    }

    void Display() const {
        std::cout << _title << (_isCompleted ? " [Completed]" : "") << "\n";
    }
};

// Receiver class to manage tasks
class TaskManager : public Subject {
private:
    std::vector<Task> tasks_;

public:
    void AddTask(const std::string &title) {
        tasks_.emplace_back(title);
        Notify("Added task: " + title);
    }

    void RemoveTask(const std::string &title) {
        auto it = std::remove_if(tasks_.begin(), tasks_.end(),
                                 [&](const Task &task) { return task.GetTitle() == title; });
        if (it != tasks_.end()) {
            Notify("Removed task: " + title);
            tasks_.erase(it, tasks_.end());
        }
    }

    void MarkTaskCompleted(const std::string &title) {
        for (Task &task : tasks_) {
            if (task.GetTitle() == title) {
                task.MarkCompleted();
                Notify("Marked task as completed: " + title);
                return;
            }
        }
    }

    void DisplayTasks() const {
        std::cout << "TODO List:\n";
        for (const Task &task : tasks_) {
            task.Display();
        }
    }
};

// Observer Implementation: Console Logger
class ConsoleLogger : public Observer {
public:
    void Update(const std::string &message) override {
        std::cout << "[LOG]: " << message << "\n";
    }
};

// Command Pattern: Base Command Class
class Command {
public:
    virtual ~Command() = default;
    virtual void Execute() = 0;
};

// Concrete Command to add a task
class AddTaskCommand : public Command {
private:
    TaskManager &manager_;
    std::string taskTitle_;

public:
    AddTaskCommand(TaskManager &manager, const std::string &taskTitle)
        : manager_(manager), taskTitle_(taskTitle) {}

    void Execute() override {
        manager_.AddTask(taskTitle_);
    }
};

// Concrete Command to remove a task
class RemoveTaskCommand : public Command {
private:
    TaskManager &manager_;
    std::string taskTitle_;

public:
    RemoveTaskCommand(TaskManager &manager, const std::string &taskTitle)
        : manager_(manager), taskTitle_(taskTitle) {}

    void Execute() override {
        manager_.RemoveTask(taskTitle_);
    }
};

// Concrete Command to mark a task as completed
class CompleteTaskCommand : public Command {
private:
    TaskManager &manager_;
    std::string taskTitle_;

public:
    CompleteTaskCommand(TaskManager &manager, const std::string &taskTitle)
        : manager_(manager), taskTitle_(taskTitle) {}

    void Execute() override {
        manager_.MarkTaskCompleted(taskTitle_);
    }
};

// Main function demonstrating the TODO list
int main() {
    // Create a task manager and attach a logger
    TaskManager manager;
    ConsoleLogger logger;
    manager.Attach(&logger);
    std::string task;
    std::cin >> task;

    // Create commands
    AddTaskCommand addTask1(manager, "Buy groceries");
    AddTaskCommand addTask2(manager, "Read a book");
    CompleteTaskCommand completeTask(manager, "Buy groceries");
    RemoveTaskCommand removeTask(manager, "Read a book");

    // Execute commands
    addTask1.Execute();
    addTask2.Execute();
    manager.DisplayTasks();
    std::cout << std::endl;
    std::cout << std::endl;

    completeTask.Execute();
    manager.DisplayTasks();
    std::cout << std::endl;
    std::cout << std::endl;
    

    removeTask.Execute();
    manager.DisplayTasks();
    std::cout << std::endl;
    std::cout << std::endl;

    return 0;
}