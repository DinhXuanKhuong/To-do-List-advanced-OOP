// Subject.h
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
    void Attach(IObserver *observer) override;
    void Detach(IObserver *observer) override;
    void Notify(const std::string &message) override;
};

#endif // SUBJECT_H
