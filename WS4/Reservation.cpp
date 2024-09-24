/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 08\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <iomanip>
#include "Reservation.h"

namespace sdds
{
	std::string Reservation::trim(std::string* s)
	{
		size_t pos = s->find_first_not_of(" \t");
		s->erase(0, pos);
		pos = s->find_last_not_of(" \t");
		if (pos != std::string::npos)
			s->erase(pos + 1);
		return *s;
	}
	Reservation::Reservation()
	{
		m_resID = "";
		m_name = "";
		m_email = "";
		m_num = 0;
		m_day = 0;
		m_hour = 0;
	}

	Reservation::Reservation(const std::string& res)
	{
		std::string::size_type n[5];
		n[0] = res.find(':');
		m_resID = res.substr(0,n[0]);
		trim(&m_resID);
		for (size_t i = 1; i < 5; i++)
		{
			n[i] = res.find(',', n[i-1]+1);
		}
		m_name = res.substr(n[0]+1, n[1] - n[0]-1);
		trim(&m_name);
		m_email = res.substr(n[1]+1, n[2] - n[1]-1);
		trim(&m_email);
		m_num = std::stoi(res.substr(n[2]+1, n[3] - n[2]-1));
		m_day = std::stoi(res.substr(n[3] + 1, n[4] - n[3]-1));
		m_hour = std::stoi(res.substr(n[4] + 1));
	}

	void Reservation::update(int day, int time)
	{
		m_day = day;
		m_hour = time;
	}

	std::ostream& operator<<(std::ostream& os, const Reservation& r)
	{
		os << "Reservation ";
		os.width(10);
		os.setf(std::ios::right);
		os << r.m_resID << ": ";
		os.width(20);
		os << r.m_name << "  ";
		os.unsetf(std::ios::right);
		os.setf(std::ios::left);
		os.width(20);
		os  << "<" + r.m_email + ">" << "    ";
		if (r.m_hour >=6 && r.m_hour <=9)
			os << "Breakfast";
		else if (r.m_hour >=11 && r.m_hour <=15)
			os << "Lunch";
		else if (r.m_hour >=17 && r.m_hour<= 21)
			os << "Dinner";
		else
			os << "Drinks";
		
		os << " on day " << r.m_day << " @ " << r.m_hour << ":00 for " << r.m_num;
		if (r.m_num == 1)
			os << " person." << std::endl;
		else
			os << " people." << std::endl;
		return os;
	}
}