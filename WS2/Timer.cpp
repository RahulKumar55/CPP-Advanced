/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 09\16\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#include <iostream>
#include "Timer.h"
namespace sdds
{
	sdds::Timer::Timer() 
	{
		currtime;
	}

	void sdds::Timer::start()
	{
		currtime = std::chrono::high_resolution_clock::now();
	}

	long long sdds::Timer::stop()
	{
		auto end = std::chrono::high_resolution_clock::now();
		auto time = std::chrono::duration_cast<std::chrono::nanoseconds>(end - currtime);
		return time.count();
	}
}