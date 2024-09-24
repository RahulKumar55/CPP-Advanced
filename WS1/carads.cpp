/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 09\16\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include "carads.h"

double g_discount;
double g_taxrate;
namespace sdds
{
	void listArgs(int argc, char** argv)
	{
		std::cout << "Command Line:\n" << "--------------------------" << std::endl;
		for (int i = 0; i < argc; i++)
		{
			std::cout << "  " << i+1  << ": " << argv[i] << std::endl;
		}
		std::cout << "--------------------------\n" << std::endl;
	}
	Cars::Cars()
	{
		m_brand = nullptr;
		strcpy(m_model, "/0");
		m_year = 0;
		m_price = 0;
		m_status = 'N';
		m_prom = false;
	}

	Cars::Cars(const Cars& car)
	{
		m_brand = nullptr;
		*this = car;
	}
	Cars& Cars::operator=(const Cars& car)
	{
		if (this != &car)
		{
			strcpy(m_model, car.m_model);
			m_year = car.m_year;
			m_price = car.m_price;
			m_status = car.m_status;
			m_prom = car.m_prom;
			if (m_brand != nullptr)
			{
				delete[] m_brand;
			}
			m_brand = new char[strlen(car.m_brand) + 1];
			strcpy(m_brand, car.m_brand);
		}
		return *this;
	}
	Cars::~Cars()
	{
		delete[] m_brand;
	}
	Cars::operator bool()
	{
		bool ret = false;
		if (m_status == 'N')
		{
			ret = true;
		}
		return ret;
	}
	std::istream& Cars::read(std::istream& is)
	{
		if (is)
		{
			char disProm;
			char brand[50];
			is.get(m_status);
			is.ignore();
			is.get(brand, 50, ',');
			is.ignore();
			is.get(m_model, 15, ',');
			is.ignore();
			is >> m_year;
			is.ignore();
			is >> m_price;
			is.ignore();
			is.get(disProm);
			is.ignore();

			delete[] m_brand;
			m_brand = new char[strlen(brand) + 1];
			strcpy(m_brand, brand);
			if (disProm == 'Y')
			{
				m_prom = true;
			}
			else
			{
				m_prom = false;
			}
		}
		return is;
	}
	void Cars::display(bool reset)
	{
		static int count = 1;
		if (reset)
		{
			count = 1;
		}
		std::cout.width(2);
		std::cout.setf(std::ios::left);
		std::cout << count << ". ";
		count++;
		std::cout.width(10);
		std::cout << m_brand << "| ";
		std::cout.width(15);
		std::cout << m_model << "| ";
		std::cout.width(4);
		std::cout << m_year << " |";
		std::cout.unsetf(std::ios::left);
		std::cout.setf(std::ios::right);
		std::cout.width(12);
		std::cout.precision(2);
		std::cout.setf(std::ios::fixed);
		double price = m_price + (m_price * g_taxrate);
		std::cout << price << "|";
		
		if (m_prom)
		{
			std::cout.width(12);
			std::cout.precision(2);
			double s_price = price - (price * g_discount);
			std::cout << s_price;
		}
		std::cout.unsetf(std::ios::right);
		std::cout << std::endl;
		

	}
	char Cars::getStatus()
	{
		return m_status;
	}

	std::istream& operator>>(std::istream& is, Cars& car)
	{
		car.read(is);
		return is;
	}
	void operator>>(const Cars& car1, Cars& car2)
	{
		car2 = car1;
	}
}