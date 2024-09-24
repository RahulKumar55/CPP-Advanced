/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 14\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <regex>
#include <iomanip>
#include"Book.h"

namespace sdds
{
	std::string Book::trim(std::string* s)
	{
		size_t pos = s->find_first_not_of(" \t");
		s->erase(0, pos);
		pos = s->find_last_not_of(" \t");
		if (pos != std::string::npos)
			s->erase(pos + 1);
		return *s;
	}
	Book::Book()
	{
		m_aut = "";
		m_title = "";
		m_con = "";
		m_des = "";
		m_year = 0;
		m_price = 0;
	}
	Book::Book(const std::string& strBook)
	{
		std::string::size_type n[5];
		n[0] = strBook.find(',');
		m_aut = strBook.substr(0, n[0]);
		trim(&m_aut);
		for (size_t i = 1; i < 5; i++)
		{
			n[i] = strBook.find(',', n[i - 1] + 1);
		}
		m_title = strBook.substr(n[0] + 1, n[1] - n[0] - 1);
		trim(&m_title);
		m_con = strBook.substr(n[1] + 1, n[2] - n[1] - 1);
		trim(&m_con);
		m_price = std::stod(strBook.substr(n[2] + 1, n[3] - n[2] - 1));
		m_year = std::stoi(strBook.substr(n[3] + 1, n[4] - n[3] - 1));
		m_des = strBook.substr(n[4] + 1);
		trim(&m_des);
	}
	const std::string& Book::title() const
	{
		return m_title;
	}
	const std::string& Book::country() const
	{
		return m_con;
	}
	const size_t& Book::year() const
	{
		return m_year;
	}
	double& Book::price()
	{
		return m_price;
	}
	std::ostream& operator<<(std::ostream& os, const Book& b)
	{
		os.setf(std::ios::right);
		os.width(20);
		os << b.m_aut << " | ";
		os.width(22);
		os << b.m_title << " | ";
		os.width(5);
		os << b.m_con << " | ";
		os.width(4);
		os << b.m_year << " | ";
		os.setf(std::ios::fixed);
		os.precision(2);
		os.width(6);
		os << b.m_price << " | ";
		os.unsetf(std::ios::right);
		os.setf(std::ios::left);
		os << b.m_des << std::endl;
		return os;
	}
}