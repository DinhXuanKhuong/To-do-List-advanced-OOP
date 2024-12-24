#include "ToTableConverter.h"

ToTableConverter::ToTableConverter() : _headers({}), _columnSizes({}) { }

ToTableConverter::ToTableConverter(vector<string> headers, vector<int> columnSizes)
    : _headers(headers), _columnSizes(columnSizes) {}

vector<string> ToTableConverter::headers() const 
{
    return _headers;
}

vector<int> ToTableConverter::columnSizes() const 
{
    return _columnSizes;
}

string ToTableConverter::toString() const { return "ToTableConverter"; }

ToTableConverter::ToRowConverter::ToRowConverter() : _columnSizes({}) {}

ToTableConverter::ToRowConverter::ToRowConverter(vector<int> columnSizes)
    : _columnSizes(columnSizes) {}