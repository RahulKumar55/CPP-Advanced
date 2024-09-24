// Name: Rahul Kumar
// Seneca Student ID: 157197211
// Seneca email: rkumar141@myseneca.ca
// Date of completion: 11/06/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#include <iomanip>
#include "Station.h"
#include "Utilities.h"

namespace sdds
{
	size_t Station::m_widthField;
	size_t Station::id_generator = 1;
	Station::Station(const std::string s)
	{
		size_t pos = 0;
		bool more = false;
		Utilities U;
		m_itemName = U.extractToken(s, pos, more);
		m_nextSerNum = stoi(U.extractToken(s, pos, more));
		m_stockQty = stoi(U.extractToken(s, pos, more));

		if (m_widthField < U.getFieldWidth())
		{
			m_widthField = U.getFieldWidth();
		}
		m_des = U.extractToken(s, pos, more);
		m_id = id_generator++;
	}
	const std::string& Station::getItemName() const
	{
		return m_itemName;
	}
	size_t Station::getNextSerialNumber()
	{
		return m_nextSerNum++;
	}
	size_t Station::getQuantity() const
	{
		return m_stockQty;
	}
	void Station::updateQuantity()
	{
		if (m_stockQty > 0)
		{
			--m_stockQty;
		}
	}
	void Station::display(std::ostream& os, bool full) const
	{
		if (full)
		{
			os << std::right  << std::setfill('0') << std::setw(3) << m_id << " | "
				<< std::left << std::setfill(' ') << std::setw(m_widthField) << m_itemName << " | "
				<< std::right << std::setfill('0') << std::setw(6) << m_nextSerNum << " | "
				<< std::right << std::setfill(' ') << std::setw(4) << m_stockQty << " | "
				<< m_des << std::endl;
		}
		else
		{
			os << std::right << std::setfill('0') << std::setw(3) << m_id << " | "
				<< std::left << std::setfill(' ') << std::setw(m_widthField) << m_itemName << " | "
				<< std::right << std::setfill('0') << std::setw(6) << m_nextSerNum << " | " << std::endl;
		}
	}
}