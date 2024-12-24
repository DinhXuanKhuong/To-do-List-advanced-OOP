#ifndef ISUBJECT_H
#define ISUBJECT_H

#include "Object.h"
#include "IObserver.h"

class ISubject : public Object {
public:
    virtual void Attach(IObserver *observer) = 0;
    virtual void Detach(IObserver *observer) = 0;
    virtual void Notify(const std::string &message) = 0;
    virtual ~ISubject() = default;
    std::string toString() const override {
        return "ISubject";
    }
};

#endif // ISUBJECT_H