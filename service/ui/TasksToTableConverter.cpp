#include "TasksToTableConverter.h"

string TasksToTableConverter::convert(const vector<shared_ptr<Task> > &tasks, string intro) {
    stringstream table;
    table << intro << "\n\n";

    table << '|' << left << _headers[0] << setw(_columnSizes[0])
        << infoSuitableForRow(_headers[1], _columnSizes[1])
        << infoSuitableForRow(_headers[2], _columnSizes[2]) << "|\n";
    

    int sum = _headers.size() - 3;
    for(size_t i = 0; i < _headers.size(); i++)
    {
        sum += _columnSizes[i];
    }
    for(size_t i = 0; i < sum; i++) table << '-';
    table << '\n'; 

    // Convert each startup to a row
    TaskToRowConverter rowConverter(_columnSizes);
    for (size_t i = 0; i < tasks.size(); i++)
    {
        table << '|' << left << setw(_columnSizes[0] - 2) << i + 1 << rowConverter.convert(tasks[i]) << '\n';
        // shared_ptr<Task> task = dynamic_pointer_cast<Task>(os[i]);
    }


    return table.str();
}

string TasksToTableConverter::TaskToRowConverter::convert(const shared_ptr<Task> &task) const {
    stringstream row;
    // shared_ptr<Task> task = dynamic_pointer_cast<Task>(o);
    


    row << infoSuitableForRow(task->GetTitle(), _columnSizes[1])
        << infoSuitableForRow(task->DisplayStatus(), _columnSizes[2]) << '|';

    return row.str();
}


string infoSuitableForRow(const string &info, int size) {
    stringstream in4;
    if(info.length() < size - 2)
    {
        in4 << "| " << left << setw(size - 2) << info;
    }
    else
    {
        string info2;
        for(int i = 0; i < size - 2; i++)
        {
            if(i < size - 5)
            {
                info2 += info[i];
            }
            else
            {
                info2 += '.';
            }
        }
        in4 << "| " << left << setw(size - 2) << info2;
    }

    return in4.str();
}