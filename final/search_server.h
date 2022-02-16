#pragma once

#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <string>

#include <deque>
#include <string_view>
#include "invertedindex.h"
using namespace std;

class SearchServer {
public:
    SearchServer() = default;
    explicit SearchServer(istream& document_input) :index(document_input) {}
    void UpdateDocumentBase(istream& document_input);
    void AddQueriesStream(istream& query_input, ostream& search_results_output);

private:
    InvertedIndex index;
};