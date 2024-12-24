#ifndef KEYBOARDDAO_H
#define KEYBOARDDAO_H
#pragma once
#include "IDao.h"
#include "../entity/Task.h"

class KeyboardDao : public IDao
{
    public:
        vector<shared_ptr<Object>> getAll() override;
};



#endif // KEYBOARDDAO_H