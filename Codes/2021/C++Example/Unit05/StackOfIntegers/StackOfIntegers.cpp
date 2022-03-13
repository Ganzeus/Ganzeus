#include"StackOfIntegers.h"

StackOfIntegers::StackOfIntegers() {
	size = 0;
	for (int& i : elements) {
		i = 0;
	}
}

bool StackOfIntegers::empty() {
	return (size == 0 ? true : false);
}

int StackOfIntegers::getSize() {
	return size;
}

int StackOfIntegers::peak() {
	return elements[size - 1];
}

int StackOfIntegers::pop() {
	int tmp = elements[size - 1];
	elements[size - 1] = 0;
	size--;
	return tmp;
}

int StackOfIntegers::push(int value) {
	elements[size] = value;
	size++;
	return value;
}