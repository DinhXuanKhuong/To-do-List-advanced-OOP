#ifndef IDAO_H
#define IDAO_H

#include <vector>
#include <string>
#include <memory>
#include "../../entity/Task.h"

class IDao {
public:
    virtual ~IDao() = default;

    /// @brief Fetch all tasks from the file.
    /// @return A vector of shared_ptr<Task>.
    virtual std::vector<std::shared_ptr<Task>> getAllTasks() = 0;

    /// @brief Save all tasks to the file.
    /// @param tasks A vector of shared_ptr<Task> to save.
    virtual void saveAllTasks(const std::vector<std::shared_ptr<Task>>& tasks) = 0;
};

#endif // IDAO_H