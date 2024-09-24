/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\07\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_CRIMESTATISTICS_H
#define SDDS_CRIMESTATISTICS_H

#include <string>
#include <vector>
#include <list>
namespace sdds
{
	struct Crime
	{
		std::string prov;
		std::string dist;
		std::string crime;
		size_t numCases;
		size_t year;
		size_t m_resolved;
	};

	class CrimeStatistics
	{
		std::vector<Crime> m_crimes;
	public:
		CrimeStatistics(const std::string s);
		void display(std::ostream& out) const;
		void sort(const std::string field);
		void cleanList();
		bool inCollection(std::string name) const;
		std::list<Crime> getListForProvince(const std::string pro) const;
	};
	std::ostream& operator<<(std::ostream& out, const Crime& theCrime);
}
#endif // !SDDS_CRIMESTATISTICS_H
