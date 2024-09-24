/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\03\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_LUXURYVAN_H
#define SDDS_LUXURYVAN_H
#include "Van.h"
namespace sdds
{
	class Luxuryvan : public Van
	{
		std::string m_consumption;
	public:
		Luxuryvan(std::istream&);
		void display(std::ostream& out) const;
		std::string consumption() const;
	};
}
#endif // !SDDS_VAN_H