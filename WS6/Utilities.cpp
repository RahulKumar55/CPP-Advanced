/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\03\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <sstream>
#include "Utilities.h"
#include "Car.h"
#include "Van.h"
#include "Luxuryvan.h"
#include "Racecar.h"
namespace sdds
{
	Vehicle* createInstance(std::istream& in)
	{
		Vehicle* veh = nullptr;
		std::string temp;
		std::getline(in, temp);
		std::stringstream ss(temp);
		std::string::size_type n;
		n = temp.find(',');
		std::string tag = temp.substr(0, n);
		trim(tag);
		if (tag[0])
		{
			if (tag[0] == 'c' || tag[0] == 'C')
			{
				veh = new Car(ss);
			}
			else if (tag[0] == 'v' || tag[0] == 'V')
			{
				veh = new Van(ss);
			}
			else if (tag[0] == 'l' || tag[0] == 'L')
			{
				veh = new Luxuryvan(ss);
			}
			else if (tag[0] == 'r' || tag[0] == 'R')
			{
				veh = new Racecar(ss);
			}
			else
			{
				temp = tag[0];
				throw "Unrecognized record type: [" + temp + "]";
			}
		}
		return veh;
	}

	///////////////
	/*Removes leading and trailing spaces from a string*/
	std::string& trim(std::string& s)
	{
		size_t pos = s.find_first_not_of(" \t");
		s.erase(0, pos);
		pos = s.find_last_not_of(" \t");
		if (pos != std::string::npos)
			s.erase(pos + 1);
		return s;
	}
}