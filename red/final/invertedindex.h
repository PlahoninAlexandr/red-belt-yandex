#ifndef INVERTEDINDEX_H
#define INVERTEDINDEX_H

#include <istream>
#include <ostream>
#include <set>
#include <list>
#include <vector>
#include <map>
#include <string>

#include <deque>
#include <string_view>
using namespace std;
vector<string_view> SplitIntoWords(string_view line);
class InvertedIndex {
public:
    InvertedIndex() = default;
    explicit InvertedIndex(istream& is);

    struct Entry {
        size_t docid;
        size_t rating;
    };
    const vector<Entry>& Lookup(string_view word) const;

    const deque<string>& GetDocument() const {
        return docs;
    }

private:
    map <string_view, vector<Entry> > index;
    deque<string> docs;
};

#endif