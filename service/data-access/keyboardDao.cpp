#include "keyboardDao.h"

vector<shared_ptr<Object>> KeyboardDao::getAll() {
    vector<shared_ptr<Object>> tasks;

    string title;
    int n;
    cout << "Enter the number of tasks you want to add: ";
    cin >> n;
    cin.ignore();
    for (int i = 0; i < n; i++) {
        cout << "Enter the title of task " << i + 1 << ": ";
        getline(cin, title);
        shared_ptr<Task> task = make_shared<Task>(title);
        tasks.push_back(task);
    }
    return tasks;
}