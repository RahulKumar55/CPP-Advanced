/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\03\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_AUTOSHOP_H
#define SDDS_AUTOSHOP_H
#include <vector>
#include <list>
#include "Vehicle.h"
namespace sdds
{
	class Autoshop
	{
		std::vector<Vehicle*> m_vehicles;
	public:
		Autoshop& operator +=(Vehicle* theVehicle);
		void display(std::ostream& out) const;
		~Autoshop();
		template <typename T>
		void select(T test, std::list<const Vehicle*>& vehicles)
		{
			for (auto& a : m_vehicles)
			{
				if (test(a))
				{
					vehicles.push_back(a);
				}
			}
		}
	};
}
#endif // !SDDS_AUTOSHOP_H
