#ifndef TASKSTOTABLECONVERTER_H
#define TASKSTOTABLECONVERTER_H

#include "ToTableConverter.h"
#include "../../entity/Task.h"
using namespace std;


class TasksToTableConverter : public ToTableConverter {
public:
    TasksToTableConverter(const vector<string> headers, const vector<int> columnSizes)
        : ToTableConverter(headers, columnSizes) {}
    string convert(const vector<shared_ptr<Task> >& tasks, string intro) override;

protected:
    class TaskToRowConverter : public ToRowConverter
    {
    public:
        using ToRowConverter::ToRowConverter; // Inherit constructors
        string convert(const shared_ptr<Task>& task) const override;
    };
};

string infoSuitableForRow(const string& info, int size);



#endif // TASKSTOTABLECONVERTER_H