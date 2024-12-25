#ifndef KEYBOARDDAO_H
#define KEYBOARDDAO_H
#pragma once
#include "IDao.h"
#include "../../entity/Task.h"
#include <regex>
class KeyboardDao : public IDao {
    public:
        vector<shared_ptr<Task> > getAllTasks() override;
        void saveAllTasks(const vector<shared_ptr<Task>> &tasks) override { // do nothing 
        };
        string toString() const override { return "KeyboardDao"; }
};



#endif // KEYBOARDDAO_H