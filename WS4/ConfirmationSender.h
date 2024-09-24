/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 08\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_CONFIRMATIONSENDER_H
#define SDDS_CONFIRMATIONSENDER_H
#include "Reservation.h"
namespace sdds
{
	class ConfirmationSender
	{
		const Reservation** m_res;
		size_t m_cnt;
	public:
		ConfirmationSender();
		ConfirmationSender(const ConfirmationSender& cs);
		ConfirmationSender(ConfirmationSender&& cs);
		~ConfirmationSender();
		ConfirmationSender& operator=(const ConfirmationSender& cs);
		ConfirmationSender& operator=(ConfirmationSender&& cs);
		ConfirmationSender& operator+=(const Reservation& res);
		ConfirmationSender& operator-=(const Reservation& res);
		friend std::ostream& operator<<(std::ostream& os, const ConfirmationSender& c);
	};
}
#endif // !SDDS_CONFIRMATIONSENDER_H
