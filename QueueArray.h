#pragma once

template<typename T>
class QueueArray {
public:
	QueueArray(int size = 10);

	void dequeue();
	void enqueue(T item);
	T peek();
	int size();
	bool isEmpty();
	bool isFull();

private:
    T*  _arr;
	int _capacity;
	int _head;
	int _tail;
	int _count;
};

template<typename T>
QueueArray<T>::QueueArray(int size) {
	_arr = new T[size];
	_capacity = size;
	_head = 0;
	_tail = -1;
	_count = 0;
}

template<typename T>
void QueueArray<T>::dequeue() {
	if (isEmpty()) return;

	_head = (_head + 1) % _capacity;
	_count--;
}

template<typename T>
void QueueArray<T>::enqueue(T item) {
	// check for Queue overflow
	if (isFull()) return;

	_tail = (_tail + 1) % _capacity;
	_arr[_tail] = item;
	_count++;
}

template<typename T>
T QueueArray<T>::peek() {
	return _arr[_head];
}

template<typename T>
int QueueArray<T>::size() {
    return _count;
}

template<typename T>
bool QueueArray<T>::isEmpty() {
    return size() == 0;
}

template<typename T>
bool QueueArray<T>::isFull() {
	return size() == _capacity;
}