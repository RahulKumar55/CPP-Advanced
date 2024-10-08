// Name: Rahul Kumar
// Seneca Student ID: 157197211
// Seneca email: rkumar141@myseneca.ca
// Date of completion: 11/07/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#ifndef SDDS_CUSTOMERORDER_H
#define SDDS_CUSTOMERORDER_H

#include <string>
#include "Station.h"
#include "Utilities.h"
namespace sdds
{
	struct Item
	{
		std::string m_itemName;
		size_t m_serialNumber{ 0 };
		bool m_isFilled{ false };

		Item(const std::string& src) : m_itemName(src)
		{
		};
	};

	class CustomerOrder
	{
		std::string m_name;
		std::string m_product;
		size_t m_cntItem;
		Item** m_lstItem;
		static size_t m_widthField;
	public:
		CustomerOrder();
		CustomerOrder(const std::string s);
		CustomerOrder(const CustomerOrder& c);
		CustomerOrder(CustomerOrder&& c) noexcept;
		CustomerOrder& operator=(const CustomerOrder& c) = delete;
		CustomerOrder& operator=(CustomerOrder&& c) noexcept;
		~CustomerOrder();
		bool isOrderFilled() const;
		bool isItemFilled(const std::string& itemName) const;
		void fillItem(Station& station, std::ostream& os);
		void display(std::ostream& os) const;
	};
}
#endif