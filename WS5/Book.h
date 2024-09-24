/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 14\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_BOOK_H
#define SDDS_BOOK_H
#include <string>
#include <iostream>
namespace sdds
{
	class Book
	{
		std::string m_aut;
		std::string m_title;
		std::string m_con;
		size_t m_year;
		double m_price;
		std::string m_des;
		std::string trim(std::string* s); // removes leading and trailing spaces from a string
	public:
		Book();
		Book(const std::string& strBook);
		const std::string& title() const;
		const std::string& country() const;
		const size_t& year() const;
		double& price();
		friend std::ostream& operator<<(std::ostream& os, const Book& b);
		template <typename T>
		void fixSpelling(T& spellChecker)
		{
			spellChecker(m_des);
		}
	};
}
#endif // !SDDS_BOOK_H
