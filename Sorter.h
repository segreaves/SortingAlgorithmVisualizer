#pragma once
#include <vector>
#include "SortElement.h"
#include <functional>

enum SortAlgorithm { quicksort, bubblesort };

class Sorter
{
public:
	SortAlgorithm m_algorithm = SortAlgorithm::bubblesort;
	void setSortingAlgorithm(SortAlgorithm algorithm);
	void sort(std::vector<SortElement>& values, const std::function<void()>& drawer);
	template <typename T> void bs(std::vector<T>& items, const std::function<void()>& drawer);
	template <typename T> void qs(std::vector<T>& items, int left, int right, const std::function<void()>& drawer);
};
