#include "main.h"

int main() {
    string filePath = "database/todoList.txt";
    TasksFacade facade;
    facade.TodoList(filePath);
    return 0;
}