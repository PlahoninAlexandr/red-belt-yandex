#include "Deque.h"
using namespace std;

void foo(Deque<int>& d) {
    for (size_t i = 0; i < d.Size(); ++i) {
        printf("%d ", d[i]);
    } 
}

void foo2(Deque<int> const& d) {
    for (size_t i = 0; i < d.Size(); ++i) {
        printf("%d ", d.At(i));
    }
}

int main() {
    Deque<int> my_deque{};

    my_deque[0];

    my_deque.PushBack(1);
    my_deque.PushBack(2);
    my_deque.PushBack(3);
    my_deque.PushBack(7);
    my_deque.PushBack(8);

    cout << my_deque.Front() << endl;
    cout << my_deque.Back() << endl;

    my_deque.PushFront(4);
    my_deque.PushFront(5);
    my_deque.PushFront(6);

    cout << my_deque.Front() << endl;
    cout << my_deque.Back() << endl;

    cout << "=========" << endl;
    foo(my_deque);
    cout << endl;
    foo2(my_deque);   
    
    return 0;
}