#ifndef SUBJECT_H
#define SUBJECT_H

#include "IObserver.h"


// Subject class for notifying observers
class Subject {
private:
    std::list<IObserver *> observers_;

public:
    void Attach(IObserver *observer) {
        observers_.push_back(observer);
    }

    void Detach(IObserver *observer) {
        observers_.remove(observer);
    }

    void Notify(const std::string &message) {
        for (IObserver *observer : observers_) {
            observer->Update(message);
        }
    }
};


#endif // SUBJECT_H

