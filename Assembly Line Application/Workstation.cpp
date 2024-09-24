// Name: Rahul Kumar
// Seneca Student ID: 157197211
// Seneca email: rkumar141@myseneca.ca
// Date of completion: 11/19/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include "Workstation.h"

namespace sdds
{
	Workstation::Workstation(const std::string& str): Station(str)
	{
		m_pNextStation = nullptr;
	}

	void Workstation::fill(std::ostream& os)
	{
		if (!m_orders.empty())
		{
			m_orders.begin()->fillItem(*this, os);
		}
	}

	bool Workstation::attemptToMoveOrder()
	{
		bool ret = false;
		if (m_orders.size())
		{
			if (m_orders[0].isItemFilled(this->getItemName()) || this->getQuantity() == 0)
			{
				if (m_pNextStation)
				{
					*m_pNextStation += std::move(m_orders.front());
				}
				else if (m_orders[0].isOrderFilled())
				{
					g_completed.push_back(std::move(m_orders[0]));
				}
				else
				{
					g_incomplete.push_back(std::move(m_orders[0]));
				}
				m_orders.pop_front();
				ret = true;
			}
		}
		return ret;
	}

	void Workstation::setNextStation(Workstation* station)
	{
		m_pNextStation = station;
	}

	Workstation* Workstation::getNextStation() const
	{
		return m_pNextStation;
	}

	void Workstation::display(std::ostream& os) const
	{
		os << this->getItemName() << " --> ";
		os << (m_pNextStation != nullptr ? m_pNextStation->getItemName() : "End of Line") << std::endl;
	}

	Workstation& Workstation::operator+=(CustomerOrder&& newOrder)
	{
		m_orders.push_back(std::move(newOrder));
		return *this;
	}
}