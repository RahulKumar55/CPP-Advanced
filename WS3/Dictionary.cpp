/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 09\30\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Dictionary.h"

namespace sdds
{
	Dictionary::Dictionary()
	{
		m_definition = "";
		m_term = "";
    }

	bool Dictionary::operator==(const Dictionary& d1)const
	{
		bool ret = false;
		if (m_term == d1.m_term && m_definition == d1.m_definition) ret = true;
		return ret;
	}

	std::ostream& operator<<(std::ostream& os, const Dictionary& d)
	{
		os.width(20);
		os.setf(std::ios::right);
		os << d.getTerm() << ": " << d.getDefinition();
		os.unsetf(std::ios::right);
		return os;
	}
}