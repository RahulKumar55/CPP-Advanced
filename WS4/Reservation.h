/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 08\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RESERVATION_H
#define SDDS_RESERVATION_H
#include <string>
#include <iostream>

namespace sdds
{
	class Reservation
	{
		std::string m_resID;
		std::string m_name;
		std::string m_email;
		int m_num;
		int m_day;
		int m_hour;
		std::string trim(std::string* s);
	public:
		Reservation();
		Reservation(const std::string& res);
		void update(int day, int time);
		friend std::ostream& operator<<(std::ostream& os, const Reservation& r);
	};
}
#endif // !SDDS_RESERVATION_H
