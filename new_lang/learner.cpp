#include <algorithm>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include "profile.h"
#include <set>

using namespace std;

class Learner {
private:
    set<string> dict;
    vector<string> vec;
    int newWords, oldWords;

public:
    int Learn(const vector<string>& words) {
        oldWords = dict.size();
        for (const auto& word : words) {
            dict.insert(word);
            ++newWords;
        }
        newWords = dict.size() - oldWords;
        return newWords;
    }

    vector<string> KnownWords() {
        for (const auto& s : dict) vec.push_back(s);
        return vec;
    }
};

int main() {
    Learner learner;
    string line;
    while (getline(cin, line)) {
        vector<string> words;
        stringstream ss(line);
        string word;
        while (ss >> word) {
            words.push_back(word);
        }
        cout << learner.Learn(words) << "\n";
        break;
    }
    cout << "=== known words ===\n";
    
    for (auto word : learner.KnownWords()) {
        cout << word << "\n";
    }
    

    return 0;
}