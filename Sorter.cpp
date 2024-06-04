#include "Sorter.h"

void Sorter::setSortingAlgorithm(SortAlgorithm algorithm)
{
	m_algorithm = algorithm;
}

void Sorter::sort(std::vector<SortElement>& values, const std::function<void()>& drawer)
{
	switch (m_algorithm)
	{
	case SortAlgorithm::bubblesort:
		bs(values, drawer);
		break;
	case SortAlgorithm::quicksort:
		qs(values, 0, values.size() - 1, drawer);
		break;
	default:
		bs(values, drawer);
		break;
	}
}

template <typename T> void Sorter::bs(std::vector<T>& items, const std::function<void()>& drawer)
{
	int n = items.size();
	for (int i = 0; i < n - 1; i++)
	{
		for (int j = 0; j < n - i - 1; j++)
			if (items[j] > items[j + 1])
			{
				items[j].highlight();
				items[j + 1].highlight();
				T temp = items[j];
				items[j] = items[j + 1];
				items[j + 1] = temp;
				drawer();
				items[j].turnOff();
				items[j + 1].turnOff();
			}
	}
}

template<typename T> void Sorter::qs(std::vector<T>& items, int left, int right, const std::function<void()>& drawer)
{
    int i = left, j = right;
    T x = items[(left + right) / 2];
    T y;

    do {
        while ((items[i] < x) && (i < right)) i++;
        while ((x < items[j]) && (left < j)) j--;

        if (i <= j) {
            items[i].highlight();
            items[j].highlight();
            y = items[i];
            items[i] = items[j];
            items[j] = y;
            drawer();
            items[i].turnOff();
            items[j].turnOff();
            i++;
            j--;
        }
    } while (i <= j);

    if (left < j) qs(items, left, j, drawer);
    if (i < right) qs(items, i, right, drawer);
}
