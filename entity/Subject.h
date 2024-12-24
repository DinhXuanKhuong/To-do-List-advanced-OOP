#ifndef SUBJECT_H
#define SUBJECT_H

#include <list>

#include "ISubject.h"
#include "IObserver.h"


// Subject class for notifying observers
class Subject : public ISubject {
private:
    std::list<IObserver *> observers_;

public:
    void Attach(IObserver *observer) override {
        observers_.push_back(observer);
    }

    void Detach(IObserver *observer) override {
        observers_.remove(observer);
    }

    void Notify(const std::string &message) override {
        for (IObserver *observer : observers_) {
            observer->Update(message);
        }
    }
};


#endif // SUBJECT_H

