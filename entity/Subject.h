#ifndef SUBJECT_H
#define SUBJECT_H

#include "Observer.h"


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


#endif // SUBJECT_H

