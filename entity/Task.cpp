#include "Task.h"

// Default constructor
Task::Task() : _title(""), _date(), _type(low), _isCompleted(false) {}

// Parameterized constructor
Task::Task(const string& title, const Date& date, Type type, bool isCompleted)
    : _title(title), _date(date), _type(type), _isCompleted(isCompleted) {}

// Getter methods
string Task::title() const {
    return _title;
}

Date Task::date() const {
    return _date;
}

Task::Type Task::type() const {
    return _type;
}

bool Task::isCompleted() const {
    return _isCompleted;
}

// Setter methods
void Task::setTitle(const string& title) {
    _title = title;
}

void Task::setDate(const Date& date) {
    _date = date;
}

void Task::setType(Type type) {
    _type = type;
}

void Task::setIsCompleted(bool isCompleted) {
    _isCompleted = isCompleted;
}