/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 08\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Restaurant.h"

namespace sdds
{

	size_t Restaurant::call_cant = 0;
	Restaurant::Restaurant()
	{
		m_res = nullptr;
		m_cnt = 0;
	}

	Restaurant::Restaurant(const Reservation* reservations[], size_t cnt)
	{
		m_res = new Reservation* [cnt];
		m_cnt = cnt;
		for (size_t i = 0; i < cnt; i++)
		{
			m_res[i] = new Reservation(*reservations[i]);
		}
	}
	size_t Restaurant::size() const
	{
		return m_cnt;
	}

	Restaurant::Restaurant(const Restaurant& r)
	{
		m_res = nullptr;
		*this = r;
	}
	Restaurant::Restaurant(Restaurant&& r)
	{
		m_res = nullptr;
		*this = std::move(r);
	}
	Restaurant::~Restaurant()
	{
		for (size_t i = 0; i < m_cnt; i++)
		{
			delete m_res[i];
		}
		delete[] m_res;
	}
	Restaurant& Restaurant::operator=(const Restaurant& r)
	{
		if (this != &r)
		{
			if (r.m_res != nullptr)
			{
				for (size_t i = 0; i < m_cnt; i++)
				{
					if (m_res[i] != nullptr)
					{
						delete m_res[i];
					}
				}
				delete[] m_res;
				m_cnt = r.m_cnt;

				m_res = new Reservation * [m_cnt];
				for (size_t i = 0; i < m_cnt; i++)
				{
					m_res[i] = new Reservation(*r.m_res[i]);
				}
			}
		}
		return *this;
	}
	Restaurant& Restaurant::operator=(Restaurant&& r)
	{
		if (this != &r)
		{
			if (r.m_res != nullptr)
			{
				for (size_t i = 0; i < m_cnt; i++)
				{
					delete m_res[i];
				}
				delete[] m_res;
				m_cnt = r.m_cnt;

				m_res = r.m_res;
				r.m_res = nullptr;
				r.m_cnt = 0;
			}
		}
		return *this;
	}

	std::ostream& operator<<(std::ostream& os, const Restaurant& r)
	{
		r.call_cant++;
		os << "--------------------------\nFancy Restaurant (" << r.call_cant << ")\n" << "--------------------------\n";
		if (r.m_cnt)
		{
			for (size_t i = 0; i < r.m_cnt; i++)
			{
				os << *r.m_res[i];
			}
		}
		else
		{
			os << "This restaurant is empty!" << std::endl;
		}
		os << "--------------------------\n";
		return os;
	}
}