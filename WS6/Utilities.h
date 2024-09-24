/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\03\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_UTILITIES_H
#define SDDS_UTILITIES_H
#include "Vehicle.h"
namespace sdds
{
	Vehicle* createInstance(std::istream& in);
	////////////

	/*Trims the leading and trailing spaces in a string*/
	std::string& trim(std::string& s);
}
#endif // !SDDS_UTILITIES_H
