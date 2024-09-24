// Name: Rahul Kumar
// Seneca Student ID: 157197211
// Seneca email: rkumar141@myseneca.ca
// Date of completion: 11/06/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iostream>
#include "Utilities.h"
namespace sdds
{
	char Utilities::m_delimiter{};
	void Utilities::setFieldWidth(size_t newWidth)
	{
		m_widthField = newWidth;
	}
	size_t Utilities::getFieldWidth() const
	{
		return m_widthField;
	}
	std::string Utilities::extractToken(const std::string& str, size_t& next_pos, bool& more)
	{
		more = false;
		if (str[next_pos] == m_delimiter)
		{
			throw "No token";
		}

		size_t n = str.find(m_delimiter, next_pos);
		std::string temp;
		if (n == std::string::npos)
		{
			temp = str.substr(next_pos);
			next_pos = 0;
		}
		else
		{
			temp = str.substr(next_pos, n - next_pos);
			next_pos = n + 1;
			more = true;
		}

		if (m_widthField < temp.length())
		{
			m_widthField = temp.length();
		}
		trim(temp);
		return temp;
	}

	void Utilities::setDelimiter(char newDelimiter)
	{
		m_delimiter = newDelimiter;
	}
	char Utilities::getDelimiter()
	{
		return m_delimiter;
	}


	////////////////////////////
	std::string& trim(std::string& s)
	{
		size_t pos = s.find_first_not_of(" \t");
		s.erase(0, pos);
		pos = s.find_last_not_of(" \t");
		if (pos != std::string::npos)
			s.erase(pos + 1);
		return s;
	}
}