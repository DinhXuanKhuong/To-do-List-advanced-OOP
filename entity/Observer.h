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



#endif // OBSERVER_H