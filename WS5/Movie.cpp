/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 14\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Movie.h"

namespace sdds
{
	std::string Movie::trim(std::string* s)
	{
		size_t pos = s->find_first_not_of(" \t");
		s->erase(0, pos);
		pos = s->find_last_not_of(" \t");
		if (pos != std::string::npos)
			s->erase(pos + 1);
		return *s;
	}

	Movie::Movie()
	{
		m_title = "";
		m_des = "";
		m_year = 0;
	}

	Movie::Movie(const std::string& strMovie)
	{
		std::string::size_type n[2];
		n[0] = strMovie.find(',');
		n[1] = strMovie.find(',', n[0] + 1);
		m_title = strMovie.substr(0, n[0]);
		trim(&m_title);
		m_year = std::stoi(strMovie.substr(n[0] + 1, n[1] - n[0] - 1));
		m_des = strMovie.substr(n[1] + 1);
		trim(&m_des);
	}

	const std::string& Movie::title() const
	{
		return m_title;
	}

	std::ostream& operator<<(std::ostream& os, const Movie& m)
	{
		os.setf(std::ios::right);
		os.width(40);
		os << m.m_title << " | ";
		os.unsetf(std::ios::right);
		os.width(4);
		os << m.m_year << " | " << m.m_des << std::endl;
		return os;
	}
}