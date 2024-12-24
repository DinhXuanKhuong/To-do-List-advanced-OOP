#ifndef TASK_H
#define TASK_H

#include <string>
#include "Date.h"
#include "Object.h"

using namespace std;

class Task : public Object {
public:
    enum Type {
        high = 1,
        mid = 2,
        low = 3,
    };

private:
    string _title;
    Date _date;
    Type _type;
    bool _isCompleted;

public:
    // Constructors
    Task();
    Task(const string& title, const Date& date, Type type, bool isCompleted);

    // Getter methods
    string title() const;
    Date date() const;
    Type type() const;
    bool isCompleted() const;

    // Setter methods
    void setTitle(const string& title);
    void setDate(const Date& date);
    void setType(Type type);
    void setIsCompleted(bool isCompleted);
};

#endif // TASK_H