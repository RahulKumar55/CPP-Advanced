/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\19\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_GENERATINGLIST_H
#define SDDS_GENERATINGLIST_H

#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <memory>
#include <utility>
#include <fstream>

namespace sdds {
	template<typename T>
	class GeneratingList {

		std::vector<T> list;
	public:

		GeneratingList(){}
		GeneratingList(const char* f) {
			std::ifstream file(f);
			if (!file)
				throw std::string("*** Failed to open file ") + std::string(f) + std::string(" ***");

			while (file) {
				T t;
				if (t.load(file))
					list.push_back(T(t));
			}
		}

		size_t size() const { return list.size(); }
		const T& operator[](size_t i) const { return list[i]; }

		//TODO: Implement the Luhn Algorithm to check the 
		//      valadity of SIN No's
		bool checkSIN(const std::string sin)
		{
			int sum = 0;
			size_t parity = sin.size() % 2;
			for (size_t i = 1; i <= sin.size(); i++)
			{
				size_t digit = sin[i-1] - '0';
				if (i%2 == parity)
				{
					sum += digit;
				}
				else if (digit > 4)
				{
					sum += (2 * digit) - 9;
				}
				else
				{
					sum += 2 * digit;
				}
			}
			return sum % 10 == 0;
		}

		//TODO: Overload the += operator with a smart pointer
		// as a second operand.
		void operator+=(const std::unique_ptr<T> t)
		{
			list.push_back(*t);
		}

		//TODO: Overload the += operator with a raw pointer
		// as a second operand.
		void operator+=(const T* t)
		{
			list.push_back(*t);
		}

		void print(std::ostream& os) const {
			os << std::fixed << std::setprecision(2);
			for (auto& e : list)
				e.print(os);
		}
	};

	template<typename T>
	std::ostream& operator<<(std::ostream& os, const GeneratingList<T>& rd) {
		rd.print(os);
		return os;
	}
}
#endif // !SDDS_GENERATINGLIST_H
