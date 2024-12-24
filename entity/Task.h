#ifndef TASK_H
#define TASK_H

#include <string>
#include "Object.h"

using namespace std;

class Task : public Object {
private:
    string _title;
    bool _isCompleted;

public:
    // Constructors
    Task();
    Task(const string& title, bool isCompleted);

    // Getter methods
    string title() const;
    bool isCompleted() const;

    // Setter methods
    void setTitle(const string& title);
    void setIsCompleted(bool isCompleted);
};

#endif // TASK_H