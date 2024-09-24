/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\03\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_VAN_H
#define SDDS_VAN_H
#include "Vehicle.h"
namespace sdds
{
	class Van : public Vehicle
	{
		std::string m_maker;
		std::string m_type;
		std::string m_cond;
		std::string m_purp;
		double m_speed;
	public:
		Van(){ };
		Van(std::istream&);
		std::string condition() const;
		double topSpeed() const;
		std::string type() const;
		std::string usage() const;
		void display(std::ostream& out) const;
	};
}
#endif // !SDDS_VAN_H
