// Name: Rahul Kumar
// Seneca Student ID: 157197211
// Seneca email: rkumar141@myseneca.ca
// Date of completion: 11/06/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.

#ifndef SDDS_STATION_H
#define SDDS_STATION_H

#include <string>
namespace sdds
{
	class Station
	{
		size_t m_id;
		std::string m_itemName;
		std::string m_des;
		size_t m_nextSerNum;
		size_t m_stockQty;
		static size_t m_widthField;
		static size_t id_generator;
	public:
		Station();
		Station(const std::string s);
		const std::string& getItemName() const;
		size_t getNextSerialNumber();
		size_t getQuantity() const;
		void updateQuantity();
		void display(std::ostream& os, bool full) const;
	};
}
#endif // !SDDS_STATION_H
