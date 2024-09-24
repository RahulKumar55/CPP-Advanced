/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 08\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RESTAURANT_H
#define SDDS_RESTAURANT_H
#include"Reservation.h"

namespace sdds
{
	class Restaurant
	{
		Reservation** m_res;
		size_t m_cnt{};
		static size_t call_cant;
	public:
		Restaurant();
		Restaurant(const Reservation* reservations[], size_t cnt);
		Restaurant(const Restaurant& r);
		Restaurant(Restaurant&& r);
		~Restaurant();
		Restaurant& operator=(const Restaurant& r);
		Restaurant& operator=(Restaurant&& r);
		size_t size() const;

		friend std::ostream& operator<<(std::ostream& os, const Restaurant& r);
	};
	
}
#endif // !SDDS_RESTAURANT_H
