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
		bubbleSort(values, drawer);
		break;
	case SortAlgorithm::quicksort:
		quickSort(values, 0, values.size() - 1, drawer);
		break;
	case SortAlgorithm::insertionsort:
		insertionSort(values, drawer);
		break;
	case SortAlgorithm::mergesort:
		mergeSort(values, 0, values.size() - 1, drawer);
		break;
	default:
		bubbleSort(values, drawer);
		break;
	}
}

template <typename T> void Sorter::bubbleSort(std::vector<T>& items, const std::function<void()>& drawer)
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

template<typename T> void Sorter::quickSort(std::vector<T>& items, int left, int right, const std::function<void()>& drawer)
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

    if (left < j) quickSort(items, left, j, drawer);
    if (i < right) quickSort(items, i, right, drawer);
}

template<typename T> void Sorter::insertionSort(std::vector<T>& items, const std::function<void()>& drawer)
{
	int n = items.size();
	for (int i = 1; i < n; i++)
	{
		T key = items[i];
		int j = i - 1;
		while (j >= 0 && key < items[j])
		{
			items[j + 1] = items[j];
			items[j] = key;// only for visualization
			items[j].highlight();
			drawer();
			items[j].turnOff();
			j--;
		}
		items[j + 1] = key;
	}
}

template <typename T> void Sorter::mergeSort(std::vector<T>& items, int l, int r, const std::function<void()>& drawer)
{
	if (l < r)
	{
		int m = l + (r - l) / 2;
		mergeSort(items, l, m, drawer);
		mergeSort(items, m + 1, r, drawer);
		merge(items, l, m, r, drawer);
	}
}

template <typename T> void Sorter::merge(std::vector<T>& items, int l, int m, int r, const std::function<void()>& drawer)
{
	int nl = m - l + 1;
	int nr = r - m;

	std::vector<T> L;
	std::vector<T> R;

	for (int i = 0; i < nl; i++) L.push_back(items[l + i]);
	for (int i = 0; i < nr; i++) R.push_back(items[m + 1 + i]);

	int i = 0, j = 0, k = l;
	while (i < nl && j < nr)
	{
		if (L[i] <= R[j])
		{
			items[k] = L[i];
			items[k].highlight();
			drawer();
			items[k].turnOff();
			i++;
		}
		else
		{
			items[k] = R[j];
			items[k].highlight();
			drawer();
			items[k].turnOff();
			j++;
		}
		k++;
	}

	while (i < nl)
	{
		items[k] = L[i];
		items[k].highlight();
		drawer();
		items[k].turnOff();
		i++;
		k++;
	}
	while (j < nr)
	{
		items[k] = R[j];
		items[k].highlight();
		drawer();
		items[k].turnOff();
		j++;
		k++;
	}
}
