/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\03\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "Car.h"
#include "Utilities.h"
namespace sdds
{
	Car::Car(std::istream& f)
	{
		std::string temp;
		std::getline(f, temp);
		std::string::size_type n[3];
		n[0] = temp.find(',');
		std::string tag = temp.substr(0, n[0]);
		trim(tag);
		if (tag[0] == 'c' || tag[0] == 'C' || tag[0] == 'r' || tag[0] =='R')
		{
			for (size_t i = 1; i < 3; i++)
			{
				n[i] = temp.find(',', n[i - 1] + 1);
			}
			m_maker = temp.substr(n[0] + 1, n[1] - n[0] - 1);
			trim(m_maker);
			m_cond = temp.substr(n[1] + 1, n[2] - n[1] - 1);
			trim(m_cond);
			size_t boost = temp.find(',', n[2] + 1);
			try
			{
				if (boost != std::string::npos)
				{
					m_speed = std::stod(temp.substr(n[2] + 1, boost - n[2] - 1));
				}
				else
				{
					m_speed = std::stod(temp.substr(n[2] + 1));
				}
			}
			catch (...)
			{
				throw "Invalid record!";
			}
			

			switch (m_cond[0])
			{
			case 'n':
				m_cond = "new";
				break;
			case 'u':
				m_cond = "used";
				break;
			case 'b':
				m_cond = "broken";
				break;
			case ' ':
				m_cond = "new";
				break;
			case '\0':
				m_cond = "new";
				break;
			default:
				throw "Invalid record!";
				break;
			}
		}
	}
	std::string Car::condition() const
	{
		return m_cond;
	}
	double Car::topSpeed() const
	{
		return m_speed;
	}
	void Car::display(std::ostream& out) const
	{
		out.setf(std::ios::right);
		out << "| ";
		out.width(10);
		out << m_maker << " | ";
		out.unsetf(std::ios::right);
		out.setf(std::ios::left);
		out.width(6);
		out << m_cond << " | ";
		out.setf(std::ios::fixed);
		out.precision(2);
		out.width(6);
		out << topSpeed() << " |";
	}
}