#pragma once
#include <SFML/Graphics.hpp>
#include "ScreenManager.h"
#include "Sorter.h"

class SortManager
{
private:
	ScreenManager* m_screenManager;
	Sorter m_sorter;
	std::vector<SortElement> m_values;
	int m_numberValues = 0;
public:
	SortManager();
	SortManager(int numberValues);
	void setScreenManager(ScreenManager* screenManager);
	void setSorter(SortAlgorithm algo);
	void generateRandomValues();
	std::vector<SortElement> getValues();
	void sort();
};
