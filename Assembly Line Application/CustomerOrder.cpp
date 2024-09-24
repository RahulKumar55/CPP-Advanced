// Name: Rahul Kumar
// Seneca Student ID: 157197211
// Seneca email: rkumar141@myseneca.ca
// Date of completion: 11/07/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <iostream>
#include <utility>
#include <vector>
#include <iomanip>
#include <vector>
#include "CustomerOrder.h"

namespace sdds
{
	size_t CustomerOrder::m_widthField{ 0 };
	CustomerOrder::CustomerOrder()
	{
		m_name = "";
		m_product = "";
		m_cntItem = 0;
		m_lstItem = nullptr;
	}
	CustomerOrder::CustomerOrder(const std::string s)
	{
		size_t pos = 0;
		bool more = false;
		Utilities U;
		m_name = U.extractToken(s, pos, more);
		m_product = U.extractToken(s, pos, more);
		std::vector<Item> temp;
		while (more)
		{
			Item it(U.extractToken(s, pos, more));
			temp.push_back(it);
		}
		m_cntItem = temp.size();
		if (m_cntItem)
		{
			m_lstItem = new Item * [m_cntItem];
			for (size_t i = 0; i < m_cntItem; i++)
			{
				m_lstItem[i] = new Item(temp[i]);
			}
		}

		if (m_widthField < U.getFieldWidth())
		{
			m_widthField = U.getFieldWidth();
		}
	}
	CustomerOrder::CustomerOrder(const CustomerOrder& c)
	{
		throw "Not Allowed";
	}
	CustomerOrder::CustomerOrder(CustomerOrder&& c) noexcept
	{
		m_cntItem = 0;
		m_lstItem = nullptr;
		*this = std::move(c);
	}
	CustomerOrder& CustomerOrder::operator=(CustomerOrder&& c) noexcept
	{
		if (this != &c)
		{
			for (size_t i = 0; i < m_cntItem; i++)
			{
				delete m_lstItem[i];
			}
			delete[] m_lstItem;

			m_name = c.m_name;
			m_product = c.m_product;
			m_cntItem = c.m_cntItem;
			m_lstItem = c.m_lstItem;

			c.m_lstItem = nullptr;
			c.m_name = "";
			c.m_product = "";
			c.m_cntItem = 0;
		}
		return *this;
	}
	CustomerOrder::~CustomerOrder()
	{
		for (size_t i = 0; i < m_cntItem; i++)
		{
			delete m_lstItem[i];
		}
		delete[] m_lstItem;
	}
	bool CustomerOrder::isOrderFilled() const
	{
		size_t ret = 0;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_isFilled)
			{
				ret++;
			}
		}
		return ret == m_cntItem;
	}
	bool CustomerOrder::isItemFilled(const std::string& itemName) const
	{
		size_t count = 0;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName)
			{
				count++;
			}
		}
		if (count == 0)
		{
			return true;
		}

		size_t filled = 0;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			if (m_lstItem[i]->m_itemName == itemName && m_lstItem[i]->m_isFilled)
			{
				filled++;
			}
		}

		return filled == count;
	}
	void CustomerOrder::fillItem(Station& station, std::ostream& os)
	{
		int pos = -1;
		int itemsCNT = 0;
		for (size_t i = 0; i < m_cntItem && pos == -1; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName()) itemsCNT++;
		}
		for (size_t i = 0; i < m_cntItem && pos == -1; i++)
		{
			if (m_lstItem[i]->m_itemName == station.getItemName() && !m_lstItem[i]->m_isFilled)
			{
				pos = i;
			}
		}

		if (pos > -1)
		{

			if (station.getQuantity())
			{
				station.updateQuantity();
				m_lstItem[pos]->m_isFilled = true;
				m_lstItem[pos]->m_serialNumber = station.getNextSerialNumber();
				os << "    Filled " << m_name << ", " << m_product << " [" << m_lstItem[pos]->m_itemName << "]\n";
			}
			else
			{
				while (itemsCNT)
				{
					itemsCNT--;
					os << "    Unable to fill " << m_name << ", " << m_product << " [" << m_lstItem[pos]->m_itemName << "]\n";
				}
			}

		}
	}

	void CustomerOrder::display(std::ostream& os) const
	{
		os << m_name << " - " << m_product << std::endl;
		for (size_t i = 0; i < m_cntItem; i++)
		{
			os << "[" << std::setw(6) << std::setfill('0') << std::right << m_lstItem[i]->m_serialNumber << "] " << std::setw(m_widthField) << std::setfill(' ') << std::left << m_lstItem[i]->m_itemName << " - ";
			std::string s = m_lstItem[i]->m_isFilled ? "FILLED" : "TO BE FILLED";
			os << s << std::endl;
		}
	}
}
