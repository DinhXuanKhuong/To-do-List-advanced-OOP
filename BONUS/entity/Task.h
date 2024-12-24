#ifndef TASK_H
#define TASK_H

#include <iostream>
#include <string>

#include "Object.h"

class Task : public Object {
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

    void SetTitle(const std::string &title) {
        _title = title;
    }

    bool IsCompleted() const {
        return _isCompleted;
    }

    void Display() const {
        std::cout << _title << (_isCompleted ? " [Completed]" : "") << "\n";
    }

    std::string toString() const override {
        return "Task";
    }
};

#endif // TASK_H