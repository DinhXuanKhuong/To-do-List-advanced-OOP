#include "Task.h"

// Default constructor
Task::Task() : _title(""),_isCompleted(false) {}

// Parameterized constructor
Task::Task(const string& title)
    : _title(title), _isCompleted(false){}

// Getter methods
string Task::title() const {
    return _title;
}


string Task::isCompleted() const {
    return _isCompleted ? "Done" : "Not Yet";
}

// Setter methods
void Task::setTitle(const string& title) {
    _title = title;
}

void Task::setIsCompleted(bool isCompleted) {
    _isCompleted = isCompleted;
}