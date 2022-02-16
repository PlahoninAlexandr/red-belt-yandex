#include <iomanip>
#include <iostream>
#include <vector>
#include <utility>
#include <iterator>
#include <algorithm>
#include <set>
#include<map>
using namespace std;

class ReadingManager
{
public:
    ReadingManager()
    {
        users.resize(10000000);
        pages.resize(10010);
        N = 0;
    }
    void Read(const long int& u_i, const int& p)
    {
        if (users[u_i] != 0)
            pages[users[u_i]] -= 1;
        else
            N++;
        pages[p] ++;
        users[u_i] = p;
    }
    float Cheer(const long int& u_i)
    {
        if (users[u_i] == 0)
            return 0;
        if (N == 1)
            return 1;
        long int count = 0;
        for (long int i = 0; i < users[u_i]; i++)
            count += pages[i];
        return float(count) / (N - 1);
    }
private:
    vector<long int>users;
    vector <int> pages;
    long int N;
};


int main() {
    // Для ускорения чтения данных отключается синхронизация
    // cin и cout с stdio,
    // а также выполняется отвязка cin от cout
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    ReadingManager manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        int user_id;
        cin >> user_id;

        if (query_type == "READ") {
            int page_count;
            cin >> page_count;
            manager.Read(user_id, page_count);
        }
        else if (query_type == "CHEER") {
            cout << setprecision(6) << manager.Cheer(user_id) << "\n";
        }
    }

    return 0;
}