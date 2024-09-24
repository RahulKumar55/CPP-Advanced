/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\03\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_RACECAR_H
#define SDDS_RACECAR_H
#include "Car.h"

namespace sdds
{
	class Racecar : public Car
	{
		double m_booster;
	public:
		Racecar(std::istream&);
		double topSpeed() const;
		void display(std::ostream& out) const;
	};
}

#endif // SDDS_RACECAR_H