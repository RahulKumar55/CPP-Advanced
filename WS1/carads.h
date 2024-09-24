/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 09\16\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef CARADS_H
#define CARADS_H
#include <iostream>

extern double g_taxrate;
extern double g_discount;

namespace sdds
{
	void listArgs(int argc, char** argv);

	class Cars
	{
		char* m_brand;
		char m_model[15];
		int m_year;
		double m_price;
		char m_status;
		bool m_prom;
	public:
		Cars();
		Cars(const Cars& car);
		~Cars();
		Cars& operator=(const Cars& car);
		std::istream& read(std::istream& is);
		void display(bool reset);
		char getStatus();
		operator bool();
	};
	std::istream& operator>>(std::istream& is, Cars& car);
	void operator>>(const Cars& car1, Cars& car2);
}


#endif // !CARADS_H
