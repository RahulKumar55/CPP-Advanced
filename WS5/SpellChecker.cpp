/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 14\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include <fstream>
#include "SpellChecker.h"

namespace sdds
{
	SpellChecker::SpellChecker(const char* filename)
	{
		std::ifstream f(filename);
		if (!f)
		{
			throw "Bad file name!";
		}
		else
		{
			std::string wline;
			int i = 0;
			do
			{
				std::getline(f, wline);
				std::string::size_type n = wline.find(' ');
				m_badWords[i] = wline.substr(0, n);
				m_goodWords[i] = wline.substr(n+1);
				size_t pos = m_goodWords[i].find_first_not_of(" \t");
				m_goodWords[i].erase(0, pos);
				i++;
			} while (f && i < 6);
		}
	}
	void SpellChecker::operator()(std::string& text)
	{
		for (size_t i = 0; i < 6; i++)
		{
			for (size_t j = 0; j < text.size(); j++)
			{
				std::string::size_type n = text.find(m_badWords[i]);
				if (n != std::string::npos)
				{
					text.replace(n, m_badWords[i].size(), m_goodWords[i]);
					m_cnt[i]++;
				}
			}
		}
	}
	void SpellChecker::showStatistics(std::ostream& out) const
	{
		out << "Spellchecker Statistics" << std::endl;
		for (size_t i = 0; i < 6; i++)
		{
			out.setf(std::ios::right);
			out.width(15);
			out << m_badWords[i] << ": " << m_cnt[i] << " replacements" << std::endl;
		}
	}
}