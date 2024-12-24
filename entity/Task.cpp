#include "Task.h"

// Default constructor
void Task::MarkCompleted() {
    _isCompleted = true;
}

string Task::GetTitle() const {
    return _title;
}

void Task::SetTitle(const std::string &title) {
    _title = title;
}

bool Task::IsCompleted() const {
    return _isCompleted;
}

string Task::DisplayStatus() const {
    if (_isCompleted) {
        return "Completed";
    } else {
        return "Not Completed";
    }
}

string Task::toString() const {
    return "Task";
}