#ifndef IOBSERVER_H
#define IOBSERVER_H

#include <string>
#include <list>

// Observer Interface
class IObserver {
public:
    virtual ~IObserver() = default;
    virtual void Update(const std::string &message) = 0;
};



#endif // IOBSERVER_H