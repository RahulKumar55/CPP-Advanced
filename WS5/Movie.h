/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 14\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_MOVIE_H
#define SDDS_MOVIE_H
#include <string>
#include <iostream>
namespace sdds
{
	class Movie
	{
		std::string m_title;
		size_t m_year;
		std::string m_des;
		std::string trim(std::string* s);
	public:
		Movie();
		Movie(const std::string& strMovie);
		const std::string& title() const;
		friend std::ostream& operator<<(std::ostream& os, const Movie& m);
		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_title);
			spellChecker(m_des);
		}
	};
}
#endif // !SDDS_MOVIE_H

