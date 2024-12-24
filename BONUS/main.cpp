#include "./entity/TaskManager.h"
#include "./entity/Command.h"
#include "./entity/ConsoleLogger.h"
#include "./services/data-access/TextFileDao.h"



int main() {
    std::shared_ptr<IDao> dao = std::make_shared<TextFileDao>("tasks.txt");
    std::vector<std::shared_ptr<Task>> tasks = dao->getAllTasks();
    // Create a task manager and attach a logger
    TaskManager manager(tasks);
    ConsoleLogger logger;
    manager.Attach(&logger);

    // Display tasks loaded from file
    dao->saveAllTasks(manager.getTasks());
    manager.DisplayTasks();
    std::cout << "\n";
    std::cout << "\n";
    return 0;
}