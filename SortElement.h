#pragma once
#include <SFML/Graphics.hpp>
#include <iostream>

enum Status { Idle, Compare, Swap};

class SortElement
{
private:
	float m_value = 0;
	bool m_highlight = false;
public:
	SortElement();
	SortElement(float value);


	float getValue();
	bool isHighlighted();
	void highlight();
	void turnOff();

	bool operator<(SortElement oth);
	bool operator<=(SortElement oth);
	bool operator>(SortElement oth);
	bool operator>=(SortElement oth);
	void operator=(const SortElement& oth);
	friend std::ostream& operator<<(std::ostream& stream, SortElement obj);
};
