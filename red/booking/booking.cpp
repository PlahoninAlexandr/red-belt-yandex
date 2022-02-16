#include <iostream>
#include <cmath>
#include <queue>
#include <tuple>
#include <map>
#include <string>

using namespace std;

class Booking {
public:
    void book(long long int time, string hotel_name, unsigned int client_id, unsigned short room_count) {
        last_booking = time;
        recalculate(time);
        m_book.push(make_tuple(time, hotel_name, client_id, room_count));
        if (m_hotel_clients[hotel_name][client_id] == 0) {
            ++m_hotels_clients_total[hotel_name];
        }
        ++m_hotel_clients[hotel_name][client_id];
        m_hotels_rooms[hotel_name] += room_count;
    }
    unsigned int clients(string hotel_name) {
        return m_hotels_clients_total[hotel_name];
    }
    unsigned int rooms(string hotel_name) {
        return m_hotels_rooms[hotel_name];
    }
private:
    queue<tuple<long long int, string, int, short>> m_book;
    map<string, map<unsigned int, int>> m_hotel_clients;
    map<string, int> m_hotels_clients_total;
    map<string, unsigned short> m_hotels_rooms;
    long long int last_booking;
    void recalculate(long long int time) {
        while (!m_book.empty() && get<0>(m_book.front()) <= time - 86400) {
            auto elem = m_book.front();
            auto client_id = get<2>(elem);
            auto hotel_name = get<1>(elem);
            auto room_count = get<3>(elem);
            --m_hotel_clients[hotel_name][client_id];
            if (m_hotel_clients[hotel_name][client_id] == 0) {
                --m_hotels_clients_total[hotel_name];
            }
            m_hotels_rooms[hotel_name] -= room_count;
            m_book.pop();
        }
    }
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    Booking manager;

    int query_count;
    cin >> query_count;

    for (int query_id = 0; query_id < query_count; ++query_id) {
        string query_type;
        cin >> query_type;
        if (query_type == "CLIENTS") {
            string hotel_name;
            cin >> hotel_name;
            cout << manager.clients(hotel_name) << '\n';
        }
        else if (query_type == "ROOMS") {
            string hotel_name;
            cin >> hotel_name;
            cout << manager.rooms(hotel_name) << '\n';
        }
        else if (query_type == "BOOK") {
            long long int time;
            string hotel_name;
            unsigned int client_id;
            unsigned short room_count;
            cin >> time >> hotel_name >> client_id >> room_count;
            manager.book(time, hotel_name, client_id, room_count);
        }
    }
}