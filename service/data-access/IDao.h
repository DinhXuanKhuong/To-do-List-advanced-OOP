#ifndef IDAO_H
#define IDAO_H
#pragma once
#include "../../entity/Object.h"
#include "../../entity/Task.h"
#include <iostream>
#include <vector>
#include <memory>


class IDao : public Object {
public:
    virtual ~IDao() = default;

    /// @brief Fetch all tasks from the file.
    /// @return A vector of shared_ptr<Task>.
    virtual vector<shared_ptr<Task>> getAllTasks() = 0;

    /// @brief Save all tasks to the file.
    /// @param tasks A vector of shared_ptr<Task> to save.
    virtual void saveAllTasks(const std::vector<std::shared_ptr<Task>>& tasks) = 0;
};

#endif // IDAO