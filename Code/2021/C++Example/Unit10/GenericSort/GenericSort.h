#pragma once
#include <iostream>
#include <array>
template<typename T>
void selectionSort(T list[], const std::size_t size) {
	// for循环，每次从list[i] ~ list[size-1]中找出一个最小的数，与list[i]交换
	for (std::size_t i = 0; i < size - 1; i++) {
		// 初始化，将list[i]记为最小值，将i记为最小值的索引
		int u = i;
		T min = list[i];
		// 用循环，找出list[i+1]~list[size-1]中的最小值和它的下标
		for (std::size_t j = i + 1; j < size; j++) {
			if (list[j] < min) {
				min = list[j];
				u = j;
			}
		}
		// 若list[i]不是最小值，那么交换list[i] <--> list[u]
		if (u != i) {
			list[u] = list[i];
			list[i] = min;
		}
	}
}
template <typename T, int N>
void selectionSort(std::array<T, N>& list) {
	constexpr int size = N;
	// for循环，每次从list[i] ~ list[size-1]中找出一个最小的数，与list[i]交换
	for (std::size_t i = 0; i < size - 1; i++) {
		// 初始化，将list[i]记为最小值，将i记为最小值的索引
		int u = i;
		T min = list[i];
		// 用循环，找出list[i+1]~list[size-1]中的最小值和它的下标
		for (std::size_t j = i + 1; j < size; j++) {
			if (list[j] < min) {
				min = list[j];
				u = j;
			}
		}
		// 若list[i]不是最小值，那么交换list[i] <--> list[u]
		if (u != i) {
			list[u] = list[i];
			list[i] = min;
		}

	}
}