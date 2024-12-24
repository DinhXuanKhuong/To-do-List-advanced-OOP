#ifndef OBSERVER_H
#define OBSERVER_H

#include <string>
#include <list>

// Observer Interface
class Observer {
public:
    virtual ~Observer() = default;
    virtual void Update(const std::string &message) = 0;
};

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

#endif // OBSERVER_H