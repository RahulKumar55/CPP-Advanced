/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 09\30\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_UNIQUEQUEUE_H
#define SDDS_UNIQUEQUEUE_H
#include <cmath>
#include "Queue.h"

namespace sdds
{
	template<typename T>
	class UniqueQueue : public Queue<T, 100>
	{
	public:
		bool push(const T& item) override
		{
			bool ret = false;
			bool exis = true;
			if (this->size() < 100)
			{
				for (size_t i = 0; i < this->size() && exis; i++)
				{
					if (item == this->operator[](i))
					{
						exis = false;
					}
				}

				if (exis)
				{
					ret =Queue<T, 100>::push(item);
				}
			}
			return ret;
		}
	};

	template<>
	bool UniqueQueue<double>::push(const double& item)
	{
		bool ret = false;
		bool exis = true;
		if (this->size() < 100)
		{
			for (size_t i = 0; i < this->size() && exis; i++)
			{
				if(std::fabs((*this)[i] - item) < 0.005)
				{
					exis = false;
				}
			}

			if (exis)
			{
				ret = Queue<double, 100>::push(item);
			}
		}
		return ret;
	}
}
#endif
