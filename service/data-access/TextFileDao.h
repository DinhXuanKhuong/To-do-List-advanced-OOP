// TextFileDao.h
#ifndef TEXTFILEDAO_H
#define TEXTFILEDAO_H

#include "../../entity/Task.h"
#include "IDao.h"
#include <fstream>
#include <sstream>
#include <memory>

class TextFileDao : public IDao {
private:
    std::string filePath_;

public:
    explicit TextFileDao(const std::string &filePath);

    std::vector<std::shared_ptr<Task>> getAllTasks() override;
    void saveAllTasks(const std::vector<std::shared_ptr<Task>> &tasks) override;
    std::string toString() const override;
};

#endif // TEXTFILEDAO_H
