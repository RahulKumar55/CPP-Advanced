/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\03\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <sstream>
#include "Luxuryvan.h"
#include "Utilities.h"

namespace sdds
{
	Luxuryvan::Luxuryvan(std::istream& in)
	{
		std::string temp;
		std::getline(in, temp);
		std::stringstream ss(temp);
		(Van&)*this = Van(ss);
		size_t found = temp.rfind(',');
		m_consumption = temp.substr(found + 1);
		trim(m_consumption);
		if (m_consumption[0] != 'e')
		{
			throw "Invalid record!";
		}
	}
	void Luxuryvan::display(std::ostream& out) const
	{
		Van::display(out);
		out << " electric van  *";
	}
	std::string Luxuryvan::consumption() const
	{
		return m_consumption;
	}
}