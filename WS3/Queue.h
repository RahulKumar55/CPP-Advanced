/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 09\30\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_QUEUE_H
#define SDDS_QUEUE_H
#include <iostream>
#include"Dictionary.h"
namespace sdds
{
	template<typename T, unsigned int N>
	class Queue
	{
		T m_line[N]{};
		static T dum;
		size_t m_size{};
	public:
		virtual ~Queue(){ }
		virtual bool push(const T& item)
		{ 
			bool ret = false;
			if (m_size < N)
			{
				m_line[m_size] = item;
				m_size++;
				ret = true;
			}
			return ret;
		}

		T pop()
		{
			T temp = m_line[0];
			for (size_t i = 1; i < m_size; i++)
			{
				m_line[i - 1] = m_line[i];
			}
			m_size--;
			return temp;
		}
		
		size_t size() const
		{
			return m_size;
		}

		std::ostream& display(std::ostream& os = std::cout) const
		{
			os << "----------------------\n| Dictionary Content |\n----------------------" << std::endl;
			for (size_t i = 0; i < m_size; i++)
			{
				os << m_line[i] << std::endl;
			}
			os << "----------------------" << std::endl;
			return os;
		}

		T operator[](size_t s) const
		{
			if (s < m_size)
			{
				return m_line[s];
			}
			return dum;
		}
	};

	template<typename T, unsigned int N>
	T Queue<T, N>::dum{};

	template<>
	sdds::Dictionary Queue<sdds::Dictionary, 100u>::dum{ "Empty Term", "Empty Substitute" };
}
#endif // !SDDS_QUEUE_H
