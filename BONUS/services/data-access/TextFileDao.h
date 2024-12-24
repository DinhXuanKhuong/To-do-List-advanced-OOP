#ifndef TEXTFILEDAO_H
#define TEXTFILEDAO_H

#include "IDao.h"
#include <fstream>
#include <sstream>
#include <memory>

class TextFileDao : public IDao {
private:
    std::string filePath_;

public:
    explicit TextFileDao(const std::string& filePath) : filePath_(filePath) {}

    std::vector<std::shared_ptr<Task>> getAllTasks() override {
        std::vector<std::shared_ptr<Task>> tasks;
        std::ifstream file(filePath_);

        if (!file.is_open()) {
            std::cerr << "Unable to open file: " << filePath_ << "\n";
            return tasks;
        }

        std::string line;
        while (std::getline(file, line)) {
            std::stringstream stream(line);
            std::string title;
            bool isCompleted;

            std::getline(stream, title, ','); // Read the title
            stream >> std::boolalpha >> isCompleted; // Read the completed status (true/false)

            auto task = std::make_shared<Task>(title);
            if (isCompleted) {
                task->MarkCompleted();
            }
            tasks.push_back(task);
        }

        file.close();
        return tasks;
    }

    void saveAllTasks(const std::vector<std::shared_ptr<Task>>& tasks) override {
        std::ofstream file(filePath_);

        if (!file.is_open()) {
            std::cerr << "Unable to open file for writing: " << filePath_ << "\n";
            return;
        }

        for (const auto& task : tasks) {
            file << task->GetTitle() << ", " << std::boolalpha << task->IsCompleted() << "\n";
        }

        file.close();
    }
};

#endif // TEXTFILEDAO_H