#include "SortManager.h"

SortManager::SortManager() : SortManager(100)
{
}

SortManager::SortManager(int numberValues)
{
	m_numberValues = numberValues;
	generateRandomValues();
}

void SortManager::setScreenManager(ScreenManager* screenManager)
{
	m_screenManager = screenManager;
}

void SortManager::setSorter(SortAlgorithm algo)
{
	m_sorter.m_algorithm = algo;
}

void SortManager::sort()
{
	auto lambdaDrawer = [this]()
	{
		m_screenManager->clearWindow();
		m_screenManager->draw(m_values);
		m_screenManager->display();
		sf::sleep(sf::seconds(0.01f));
	};
	m_sorter.sort(m_values, lambdaDrawer);
}

void SortManager::generateRandomValues()
{
	m_values.clear();
	for (int i = 1; i <= m_numberValues; i++) m_values.push_back(i);
	std::random_shuffle(m_values.begin(), m_values.end());
}

std::vector<SortElement> SortManager::getValues()
{
	return m_values;
}
