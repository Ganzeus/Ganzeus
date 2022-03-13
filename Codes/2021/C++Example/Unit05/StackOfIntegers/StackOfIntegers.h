#pragma once
//»ŒŒÒ1£∫±‡–¥StackOfIntegers¿‡
/*
-elements:int[100]
-size:int
+StackOfIntegers()
+empty(): bool
+peek(): int
+push(value: int): int
+pop(): int
+getSize(): int
*/
class StackOfIntegers {
private:
	int elements[100]{ 0 };
	int size{ 0 };
	int top = 0;
public:
	StackOfIntegers();
	int getSize();
	bool empty();
	int peak();
	int push(int value);
	int pop();
};