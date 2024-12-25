// Subject.cpp
#include "Subject.h"

void Subject::Attach(IObserver *observer) {
    observers_.push_back(observer);
}

void Subject::Detach(IObserver *observer) {
    observers_.remove(observer);
}

void Subject::Notify(const std::string &message) {
    for (IObserver *observer : observers_) {
        observer->Update(message);
    }
}
