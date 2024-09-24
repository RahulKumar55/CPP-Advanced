/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\03\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <sstream>
#include "Racecar.h"
namespace sdds
{
	Racecar::Racecar(std::istream& in) : Car(in)
	{
		std::string temp;
		in.clear();
		in.seekg(0);
		std::getline(in, temp);
		size_t found = temp.rfind(',');
		m_booster = std::stod(temp.substr(found + 1));
	}
	double Racecar::topSpeed() const
	{
		return (Car::topSpeed() * m_booster) +
			Car::topSpeed();
	}
	void Racecar::display(std::ostream& out) const
	{
		Car::display(out);
		out << "*";
	}
}