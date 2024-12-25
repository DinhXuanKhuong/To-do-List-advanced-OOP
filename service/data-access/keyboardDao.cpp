#include "KeyboardDao.h"

vector<shared_ptr<Task> > KeyboardDao::getAllTasks() {
    vector<shared_ptr<Task> > tasks;

    string title;
    int n;
    cout << "Enter the number of tasks you want to add: ";
    string input;
    while(true) {
        getline(cin, input);
        regex pattern("\\d+");
        smatch match;
        if (regex_match(input, match, pattern)) {
            n = stoi(input);
            break;
        } else {
            cout << "Invalid input. Please enter a valid number." << endl;
        }
    }
    for (int i = 0; i < n; i++) {
        cout << "Enter the title of task " << i + 1 << ": ";
        getline(cin, title);
        shared_ptr<Task> task = make_shared<Task>(title);
        tasks.push_back(task);
    }
    return tasks;
}