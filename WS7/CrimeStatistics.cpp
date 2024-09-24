/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\07\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include <iomanip>
#include <fstream>
#include <algorithm>
#include <numeric>
#include "CrimeStatistics.h"

void printbar(std::ostream& out = std::cout);
namespace sdds
{
	CrimeStatistics::CrimeStatistics(const std::string s)
	{
		std::ifstream f(s);
		if (!f)
		{
			throw "ERROR: Cannot open file";
		}
		Crime c;
		while (f)
		{
			f >> c.prov;
			f >> c.dist;
			f >> c.crime;
			f >> c.year;
			f >> c.numCases;
			f >> c.m_resolved;
			if (f)
			{
				m_crimes.push_back(c);
			}
		}
	}
	void CrimeStatistics::display(std::ostream& out) const
	{
		int tot{0}, sol{0};
		auto print = [&](const Crime& theCrime)
		{
			out << theCrime << std::endl;
		};
		std::for_each(m_crimes.begin(), m_crimes.end(), print);
		auto total = [&](int sum, const Crime c)
		{
			return sum + c.numCases;
		};
		auto solve = [&](int sum, const Crime c)
		{
			return sum + c.m_resolved;
		};
		tot = std::accumulate(m_crimes.begin(), m_crimes.end(), (int)0, total);
		sol = std::accumulate(m_crimes.begin(), m_crimes.end(), (int)0, solve);
		printbar();
		out << "|" << std::setw(80) << std::right << "Total Crimes:  " << tot << " |" << std::endl;
		out << "|" << std::setw(80) << std::right << "Total Resolved Cases:  " << sol << " |" << std::endl;
	}

	std::ostream& operator<<(std::ostream& out, const Crime& theCrime)
	{
		out << "| " << std::setw(21) << std::left << theCrime.prov << " | " << std::setw(15) << theCrime.dist << " | " << std::setw(20) << theCrime.crime << " | " << std::setw(6) << std::right <<theCrime.year << " | " << std::setw(4) << theCrime.numCases << " | "
			<< std::setw(3) << theCrime.m_resolved << " |";
		return out;
	}

	void CrimeStatistics::sort(const std::string field)
	{
		auto compare = [&](const Crime c1, const Crime c2)
		{
			if (field == "Province")
			{
				return c1.prov < c2.prov;
			}
			else if (field == "Crime")
			{
				return c1.crime < c2.crime;
			}
			else if (field == "Cases")
			{
				return c1.numCases < c2.numCases;
			}
			else if (field == "Resolved")
			{
				return c1.m_resolved < c2.m_resolved;
			}
			return false;
		};
		std::sort(m_crimes.begin(), m_crimes.end(), compare);
	}

	void CrimeStatistics::cleanList()
	{
		std::transform(m_crimes.begin(), m_crimes.end(), m_crimes.begin(), [&](Crime c)
			{
				if (c.crime == "[None]")
				{
					c.crime = "";
				}
				return c;
		    }
		);
	}

	bool CrimeStatistics::inCollection(std::string name) const
	{
		bool ret = false;

		ret = std::any_of(m_crimes.begin(), m_crimes.end(), [&](Crime c)
			{
				return c.crime == name;
		});
		return ret;
	}

	std::list<Crime> CrimeStatistics::getListForProvince(const std::string pro) const
	{
		int num = std::count_if(m_crimes.begin(), m_crimes.end(), [&](Crime c)
			{
				return c.prov == pro;
			});
		std::list<Crime> ret(num);
		std::copy_if(m_crimes.begin(), m_crimes.end(), ret.begin(), [&](Crime c)
			{
				return c.prov == pro;
		});
		return ret;
	}
}