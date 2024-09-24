/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 14\10\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#ifndef SDDS_COLLECTION_H
#define SDDS_COLLECTION_H
#include <string>
#include <stdexcept>
#include <iostream>
namespace sdds
{
	template <typename T>
	class Collection
	{
		std::string c_name;
		T* c_items;
		size_t c_size;
		void (*c_func)(const Collection<T>&, const T&);
	public:
		Collection(const std::string& name)
		{
			c_name = name;
			c_items = nullptr;
			c_size = 0;
			c_func = nullptr;
		}

		~Collection()
		{
			delete[] c_items;
		}

		const std::string& name() const
		{
			return c_name;
		}

		size_t size() const
		{
			return c_size;
		}

		void setObserver(void (*observer)(const Collection<T>&, const T&))
		{
			c_func = observer;
		}

		Collection<T>& operator+=(const T& item)
		{
			bool exist = false;
			for (size_t i = 0; i < c_size && !exist; i++)
			{
				if (c_items[i].title() == item.title())
				{
					exist = true;
				}
			}

			if (!exist)
			{
				c_size++;
				T* temp = nullptr;
				if (c_items != nullptr)
				{
					temp = new T[c_size - 1];
					for (size_t i = 0; i < c_size - 1; i++)
					{
						temp[i] = c_items[i];
					}
					delete[] c_items;
				}

				c_items = new T[c_size];
				for (size_t i = 0; i < c_size - 1; i++)
				{
					c_items[i] = temp[i];
				}
				c_items[c_size - 1] = item;
				delete[] temp;

				if (c_func != nullptr)
				{
					c_func(*this, item);
				}
			}
			return *this;
		}

		T& operator[](size_t idx) const
		{

			if (idx < 0 || idx > c_size - 1)
			{
				throw std::out_of_range("Bad index [" + std::to_string(idx) + "]. Collection has [" + std::to_string(c_size) + "] items.");
			}

			return c_items[idx];
		}

		T* operator[](const std::string& title) const
		{
			T* temp = nullptr;

			for (size_t i = 0; i < c_size; i++)
			{

				if (c_items[i].title() == title)
				{
					temp = &c_items[i];
				}
			}
			return temp;
		}
	};

	template <typename T>
	std::ostream& operator<<(std::ostream& os, const Collection<T>& c)
	{
		for (size_t i = 0; i < c.size(); i++)
		{
			os << c[i];
		}
		return os;
	}
}
#endif // !SDDS_COLLECTION_H

