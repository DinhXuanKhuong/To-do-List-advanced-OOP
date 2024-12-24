#include "Task.h"

// Default constructor
Task::Task() : _title(""),_isCompleted(false) {}

// Parameterized constructor
Task::Task(const string& title, bool isCompleted)
    : _title(title), _isCompleted(isCompleted) {}

// Getter methods
string Task::title() const {
    return _title;
}


bool Task::isCompleted() const {
    return _isCompleted;
}

// Setter methods
void Task::setTitle(const string& title) {
    _title = title;
}

void Task::setIsCompleted(bool isCompleted) {
    _isCompleted = isCompleted;
}