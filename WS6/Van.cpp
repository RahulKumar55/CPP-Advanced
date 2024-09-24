/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\03\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include "Van.h"
#include "Utilities.h"
namespace sdds
{
	Van::Van(std::istream& f)
	{
		std::string temp;
		std::getline(f, temp);
		std::string::size_type n[5];
		n[0] = temp.find(',');
		std::string tag = temp.substr(0, n[0]);
		trim(tag);
		if (tag[0] == 'v' || tag[0] == 'V' || tag[0] == 'l' || tag[0] == 'L')
		{
			for (size_t i = 1; i < 5; i++)
			{
				n[i] = temp.find(',', n[i - 1] + 1);
			}
			m_maker = temp.substr(n[0] + 1, n[1] - n[0] - 1);
			trim(m_maker);
			m_type = temp.substr(n[1] + 1, n[2] - n[1] - 1);
			trim(m_type);
			m_purp = temp.substr(n[2] + 1, n[3] - n[2] - 1);
			trim(m_purp);
			m_cond = temp.substr(n[3] + 1, n[4] - n[3] - 1);
			trim(m_cond);
			size_t fuel = temp.find(',', n[4] + 1);
			if (fuel != std::string::npos)
			{
				m_speed = std::stod(temp.substr(n[4] + 1, fuel - n[4] - 1));
			}
			else
			{
				m_speed = std::stod(temp.substr(n[4] + 1));
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

			switch (m_type[0])
			{
			case 'p':
				m_type = "pickup";
				break;
			case 'm':
				m_type = "mini-bus";
				break;
			case 'c':
				m_type = "camper";
				break;
			default:
				throw "Invalid record!";
				break;
			}

			switch (m_purp[0])
			{
			case 'd':
				m_purp = "delivery";
				break;
			case 'p':
				m_purp = "passenger";
				break;
			case 'c':
				m_purp = "camping";
				break;
			default:
				throw "Invalid record!";
				break;
			}
		}
	}
	std::string Van::condition() const
	{
		return m_cond;
	}
	double Van::topSpeed() const
	{
		return m_speed;
	}
	std::string Van::type() const
	{
		return m_type;
	}
	std::string Van::usage() const
	{
		return m_purp;
	}
	void Van::display(std::ostream& out) const
	{
		out.setf(std::ios::right);
		out << "| ";
		out.width(8);
		out << m_maker << " | ";
		out.unsetf(std::ios::right);
		out.setf(std::ios::left);
		out.width(12);
		out << m_type << " | ";
		out.width(12);
		out << m_purp << " | ";
		out.width(6);
		out << m_cond << " | ";
		out.setf(std::ios::fixed);
		out.width(6);
		out.precision(2);
		out << m_speed << " |";
	}
}