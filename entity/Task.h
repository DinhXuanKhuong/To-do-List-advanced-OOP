#ifndef TASK_H
#define TASK_H
#include <iostream>
#include <string>
#include "Object.h"

using namespace std;

class Task : public Object {
private:
    string _title;
    bool _isCompleted;

public:
    explicit Task(const std::string &title) : _title(title), _isCompleted(false) {}

    void MarkCompleted();

    std::string GetTitle() const;

    void SetTitle(const std::string &title);

    bool IsCompleted() const;

    string DisplayStatus() const;

    std::string toString() const override ;
};

#endif // TASK_H