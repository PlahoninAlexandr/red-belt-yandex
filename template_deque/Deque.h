#pragma once
#include <exception>
#include <stdexcept>
#include <iostream>
#include <vector>

using namespace std;

template<class T>
class Deque {
private:
	vector<T> front, back;
	int size;
public:
	Deque() {
		size = 0;
	}

	T& operator[](const int index) {
		return At(index);
	}

	const T& operator[](const int index) const {
		return At(index);
	}
	
	T& At(size_t index) {
		if (index < front.size()) return front.at(front.size() - 1 - index);
		else if (index < size) return back.at(index - front.size());
		else throw std::out_of_range("index out of range");
	}
	const T& At(size_t index) const {
		if (index < front.size()) return front.at(front.size() - 1 - index);
		else if (index < size) return back.at(index - front.size());
		else throw std::out_of_range("index out of range");
	}

	bool Empty() const {
		if (size == 0) return true;
		else return false;
	}

	int Size() const {
		return size;
	}

	T& Front() {
		return At(0);
	}

	const T& Front() const {
		return At(0);
	}

	T& Back() {
		return At(Size() - 1);
	}

	const T& Back() const {
		return At(Size() - 1);
	}

	void PushFront(T data) {
		front.push_back(data);
		size++;
	}

	void PushBack(T data) {
		back.push_back(data);
		size++;
	}
};