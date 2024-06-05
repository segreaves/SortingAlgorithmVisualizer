#pragma once
#include <vector>
#include "SortElement.h"
#include <functional>

enum SortAlgorithm { quicksort, bubblesort, insertionsort, mergesort };

class Sorter
{
public:
	SortAlgorithm m_algorithm = SortAlgorithm::bubblesort;
	void setSortingAlgorithm(SortAlgorithm algorithm);
	void sort(std::vector<SortElement>& values, const std::function<void()>& drawer);
	template <typename T> void bubbleSort(std::vector<T>& items, const std::function<void()>& drawer);
	template <typename T> void quickSort(std::vector<T>& items, int left, int right, const std::function<void()>& drawer);
	template <typename T> void insertionSort(std::vector<T>& items, const std::function<void()>& drawer);
	template <typename T> void mergeSort(std::vector<T>& items, int l, int r, const std::function<void()>& drawer);
	template <typename T> void merge(std::vector<T>& items, int l, int m, int r, const std::function<void()>& drawer);
};
