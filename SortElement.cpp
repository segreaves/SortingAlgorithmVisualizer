#include "SortElement.h"

SortElement::SortElement()
{
}

SortElement::SortElement(float value)
{
	m_value = value;
}

float SortElement::getValue()
{
	return m_value;
}

bool SortElement::isHighlighted()
{
	return m_highlight;
}

void SortElement::highlight()
{
	m_highlight = true;
}

void SortElement::turnOff()
{
	m_highlight = false;
}

bool SortElement::operator<(SortElement oth)
{
	return m_value < oth.m_value;
}

bool SortElement::operator<=(SortElement oth)
{
	return m_value <= oth.m_value;
}

bool SortElement::operator>(SortElement oth)
{
	return m_value > oth.m_value;
}

bool SortElement::operator>=(SortElement oth)
{
	return m_value >= oth.m_value;
}

void SortElement::operator=(const SortElement& oth)
{
	this->m_value = oth.m_value;
	this->m_highlight = oth.m_highlight;
}

std::ostream& operator<<(std::ostream& stream, SortElement obj)
{
	stream << obj.m_value;
	return stream;
}
