/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 09\16\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TIMER_H
#define SDDS_TIMER_H
#include <chrono>
namespace sdds
{
	class Timer
	{
		std::chrono::high_resolution_clock::time_point currtime;
	public:
		Timer();
		void start();
		long long stop();
	};
}
#endif
