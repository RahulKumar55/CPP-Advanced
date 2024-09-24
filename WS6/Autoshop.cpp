/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\03\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Autoshop.h"

namespace sdds
{
	Autoshop& Autoshop::operator +=(Vehicle* theVehicle)
	{
		m_vehicles.push_back(theVehicle);
		return *this;
	}
	void Autoshop::display(std::ostream& out) const
	{
		for (size_t i = 0; i < m_vehicles.size(); i++)
		{
			m_vehicles[i]->display(out);
			out << std::endl;
		}
	}

	Autoshop::~Autoshop()
	{
		for (size_t i = 0; i < m_vehicles.size(); i++)
		{
			delete m_vehicles[i];
		}
	}
}