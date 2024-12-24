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

    // // Sample Commands
    // AddTaskCommand addTask1(manager, "Play games");
    // AddTaskCommand addTask2(manager, "Read a book");
    // CompleteTaskCommand completeTask(manager, "Play games");
    // RemoveTaskCommand removeTask(manager, "Read a book");

    // // Execute commands
    // addTask1.Execute();
    // addTask2.Execute();
    // dao->saveAllTasks(manager.getTasks());
    // manager.DisplayTasks();
    // std::cout << "\n";
    // std::cout << "\n";

    // completeTask.Execute();
    // dao->saveAllTasks(manager.getTasks());
    // manager.DisplayTasks();
    // std::cout << "\n";
    // std::cout << "\n";

    // removeTask.Execute();
    // dao->saveAllTasks(manager.getTasks());
    // manager.DisplayTasks();
    // std::cout << "\n";
    // std::cout << "\n";

    return 0;

    
}