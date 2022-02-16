#include "test_runner.h"

#include <algorithm>
#include <iostream>
#include <string>
#include <queue>
#include <stdexcept>
#include <set>
using namespace std;

template <class T>
class ObjectPool {
public:
	T* Allocate() {
		if (!free.empty()) {
			T* t = free.front();
			allocated.insert(t);
			free.pop();
			return t;
		}
		else {
			T* t = new T;
			allocated.insert(t);
			return t;
			// mb nado delete data dobavit
		}
	}

	T* TryAllocate() {
		if (!free.empty()) {
			T* t = free.front();
			allocated.insert(t);
			free.pop();
			return t;
		}
		else {
			return nullptr;
		}
	}

	void Deallocate(T* object) {
		auto it = allocated.find(object);

		if (it == allocated.end()) {
			throw invalid_argument("invalid_argument");
		}
		else {
			T* p = *it;
			free.push(p);
			allocated.erase(it);
		}
	}

	~ObjectPool() {
		for (auto& a : allocated) {
			delete a;
		}
		while (!free.empty()) {
			delete free.front();
			free.pop();
		}
	}

private:
	// Добавьте сюда поля
	queue<T*> free;
	set<T*> allocated;
};

void TestObjectPool() {
	ObjectPool<string> pool;

	auto p1 = pool.Allocate();
	auto p2 = pool.Allocate();
	auto p3 = pool.Allocate();

	*p1 = "first";
	*p2 = "second";
	*p3 = "third";

	pool.Deallocate(p2);
	ASSERT_EQUAL(*pool.Allocate(), "second");

	pool.Deallocate(p3);
	pool.Deallocate(p1);
	ASSERT_EQUAL(*pool.Allocate(), "third");
	ASSERT_EQUAL(*pool.Allocate(), "first");

	pool.Deallocate(p1);
}

int main() {
	TestRunner tr;
	RUN_TEST(tr, TestObjectPool);
	return 0;
}
