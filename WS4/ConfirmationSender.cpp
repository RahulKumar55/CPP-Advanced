/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 08\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "ConfirmationSender.h"

namespace sdds
{
	ConfirmationSender::ConfirmationSender()
	{
		m_res = nullptr;
		m_cnt = 0;
	}


	ConfirmationSender::ConfirmationSender(const ConfirmationSender& cs)
	{
		m_res = nullptr;
		*this = cs;
	}
	ConfirmationSender::ConfirmationSender(ConfirmationSender&& cs)
	{
		m_res = nullptr;
		*this = std::move(cs);
	}
	ConfirmationSender::~ConfirmationSender()
	{
		delete[] m_res;
	}
	ConfirmationSender& ConfirmationSender::operator=(const ConfirmationSender& cs)
	{
		if (this != &cs)
		{
			delete[] m_res;
			m_cnt = cs.m_cnt;
			m_res = new const Reservation * [m_cnt];
			for (size_t i = 0; i < m_cnt; i++)
			{
				m_res[i] = cs.m_res[i];
			}
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator=(ConfirmationSender&& cs)
	{
		if (this != &cs)
		{
			delete[] m_res;
			m_cnt = cs.m_cnt;
			m_res = cs.m_res;
			cs.m_res = nullptr;
			cs.m_cnt = 0;
		}
		return *this;
	}

	ConfirmationSender& ConfirmationSender::operator+=(const Reservation& res)
	{
		bool exist = false;
		for (size_t i = 0; i < m_cnt && !exist; i++)
		{
			if (m_res[i] == &res)
				exist = true;
		}


		if (!exist)
		{
			const Reservation** temp = new const Reservation * [m_cnt];
			for (size_t i = 0; i < m_cnt; i++)
			{
				temp[i] = m_res[i];
			}

			delete[] m_res;

			m_res = new const Reservation * [m_cnt + 1];
			for (size_t i = 0; i < m_cnt; i++)
			{
				m_res[i] = temp[i];
			}
			delete[] temp;
			m_res[m_cnt] = &res;
			m_cnt++;
		}
		return *this;
	}
	ConfirmationSender& ConfirmationSender::operator-=(const Reservation& res)
	{
		int index = -1;
		for (size_t i = 0; i < m_cnt && index == -1; i++)
		{
			if (m_res[i] == &res)
				index = i;
		}

		if (index != -1)
		{
			m_res[index] = nullptr;
		}

		return *this;
	}
	std::ostream& operator<<(std::ostream& os, const ConfirmationSender& c)
	{
		os << "--------------------------\nConfirmations to Send\n" << "--------------------------\n";
		if (c.m_cnt)
		{
			for (size_t i = 0; i < c.m_cnt; i++)
			{
				if (c.m_res[i])
				{
					os << *c.m_res[i];
				}
			}
		}
		else
		{
			os << "There are no confirmations to send!" << std::endl;
		}
		os << "--------------------------\n";
		return os;
	}

}