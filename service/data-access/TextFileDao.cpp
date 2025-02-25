// TextFileDao.cpp
#include "TextFileDao.h"
#include <iostream>
#include <utility>

TextFileDao::TextFileDao(const std::string &filePath) : filePath_(filePath) {}

std::vector<std::shared_ptr<Task>> TextFileDao::getAllTasks() {
    std::vector<std::shared_ptr<Task>> tasks;
    std::ifstream file(filePath_);

    if (!file.is_open()) {
        std::cerr << "Unable to open file: " << filePath_ << "\n";
        return tasks;
    }

    std::string line;
    getline(file, line); // Skip the header line
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

void TextFileDao::saveAllTasks(const std::vector<std::shared_ptr<Task>> &tasks) {
    std::ofstream file(filePath_);

    if (!file.is_open()) {
        std::cerr << "Unable to open file for writing: " << filePath_ << "\n";
        return;
    }

    file << "Title, Completed\n";
    for (const auto &task : tasks) {
        file << task->GetTitle() << ", " << std::boolalpha << task->IsCompleted() << "\n";
    }

    file.close();
}

std::string TextFileDao::toString() const {
    return "TextFileDao";
}
