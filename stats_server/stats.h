#pragma once

#include "http_request.h"

#include <string_view>
#include <map>
#include <algorithm>
#include <iterator>
#include <iostream>

using namespace std;

class Stats {
    void Add(string_view& method, map<string_view, int>& container, const string& POLE);
    map<string_view, int> method_;
    map<string_view, int> uri_;
public:
    Stats();
    void AddMethod(string_view method);
    void AddUri(string_view uri);
    const map<string_view, int>& GetMethodStats() const;
    const map<string_view, int>& GetUriStats() const;
};

HttpRequest ParseRequest(string_view line);
bool Parse(string_view& line, string& methods);