#ifndef TOTABLECONVERTER_H
#define TOTABLECONVERTER_H
#pragma once
#include "../../entity/Object.h"
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>
#include <sstream>
#include <memory>
#include <iomanip>


using namespace std;

class ToTableConverter : public Object
{
    protected:
        vector<string> _headers;
        vector<int> _columnSizes;

    public:
        ToTableConverter();
        ToTableConverter(vector<string> headers, vector<int> columnSizes);
        virtual ~ToTableConverter() = default;
    
    public:
        vector<string> headers() const;
        vector<int> columnSizes() const;
    
    public:
        string toString() const override;
        virtual string convert(const vector<shared_ptr<Object>>& os, string intro) = 0;

    protected:
        class ToRowConverter
        {
            protected:
                vector<int> _columnSizes;

            public:
                ToRowConverter();
                ToRowConverter(vector<int> columnSizes);
                virtual string convert(const shared_ptr<Object>& object) const = 0; // Use a more generic type
        };
};

#endif // TOTABLECONVERTER_H
