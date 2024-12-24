#ifndef IDAO_H
#define IDAO_H
#pragma once
#include "../entity/Object.h"
#include <iostream>
#include <vector>
#include <memory>


class IDao : public Object
{
    public:
        virtual vector<shared_ptr<Object>> getAll() = 0;
};

#endif // IDAO