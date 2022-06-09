#pragma once
#include <iostream>
#include <array>
template<typename T>
void selectionSort(T list[], const std::size_t size) {
	// forѭ����ÿ�δ�list[i] ~ list[size-1]���ҳ�һ����С��������list[i]����
	for (std::size_t i = 0; i < size - 1; i++) {
		// ��ʼ������list[i]��Ϊ��Сֵ����i��Ϊ��Сֵ������
		int u = i;
		T min = list[i];
		// ��ѭ�����ҳ�list[i+1]~list[size-1]�е���Сֵ�������±�
		for (std::size_t j = i + 1; j < size; j++) {
			if (list[j] < min) {
				min = list[j];
				u = j;
			}
		}
		// ��list[i]������Сֵ����ô����list[i] <--> list[u]
		if (u != i) {
			list[u] = list[i];
			list[i] = min;
		}
	}
}
template <typename T, int N>
void selectionSort(std::array<T, N>& list) {
	constexpr int size = N;
	// forѭ����ÿ�δ�list[i] ~ list[size-1]���ҳ�һ����С��������list[i]����
	for (std::size_t i = 0; i < size - 1; i++) {
		// ��ʼ������list[i]��Ϊ��Сֵ����i��Ϊ��Сֵ������
		int u = i;
		T min = list[i];
		// ��ѭ�����ҳ�list[i+1]~list[size-1]�е���Сֵ�������±�
		for (std::size_t j = i + 1; j < size; j++) {
			if (list[j] < min) {
				min = list[j];
				u = j;
			}
		}
		// ��list[i]������Сֵ����ô����list[i] <--> list[u]
		if (u != i) {
			list[u] = list[i];
			list[i] = min;
		}

	}
}