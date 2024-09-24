// Name: Rahul Kumar
// Seneca Student ID: 157197211
// Seneca email: rkumar141@myseneca.ca
// Date of completion: 11/19/2022
//
// I confirm that I am the only author of this file
//   and the content was created entirely by me.
#include <fstream>
#include <algorithm>
#include "LineManager.h"
#include "Utilities.h"

namespace sdds
{
	std::deque<CustomerOrder> g_pending{};
	std::deque<CustomerOrder> g_completed{};
	std::deque<CustomerOrder> g_incomplete{};

	/*
	* Gets a liine from the file and extracts the names of stations that the line contains.
	* iterates through stations vector and checks if a Workstation with name same as first field exists.
	  If finds the Workstation, copies the address to a pointer named first, also iterates through stations to check for
	  next station and assigns it to first's nextstation attribute.
    * Checks if m_activeLine contatins first, if not then adds it to m_activeLine.
	* Iterates through m_activeLine to check if the current Workstation in iteration is nextstation of 
	  any other Workstation. If not, assigns it to m_firstStation.
	* Assigns the count of orders to m_cntCustomerOrder.
	*/
	LineManager::LineManager(const std::string& file, const std::vector<Workstation*>& stations) : m_activeLine{}
	{
		try
		{
			std::ifstream f(file);
			if (!f)
			{
				throw "Bad file name";
			}

			std::string str;
			while (f)
			{
				std::getline(f, str);
				Utilities U;
				size_t pos = 0;
				bool more = false;
				std::string first_field = "", next_field = "";
				Workstation* first = nullptr;
				first_field = U.extractToken(str, pos, more);
				if (more)
				{
					next_field = U.extractToken(str, pos, more);
				}

				std::for_each(stations.begin(), stations.end(), [&](Workstation* w1)
					{
						if (w1->getItemName() == first_field)
						{
							std::for_each(stations.begin(), stations.end(), [&](Workstation* w2)
								{
									if (w2->getItemName() == next_field)
									{
										w1->setNextStation(w2);
									}
								}
							);
							first = w1;
						}
					}
				);

				bool fexists = std::any_of(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* w)
					{
						if (w == first)
						{
							return true;
						}
						return false;
					}
				);

				if (!fexists)
				{
					m_activeLine.push_back(first);
				}

				std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* w1)
					{
						bool isNotFirst = std::any_of(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* w2)
							{
								if (w1 == w2->getNextStation())
								{
									return true;
								}
								return false;
							}
						);

						if (!isNotFirst)
						{
							m_firstStation = w1;
						}
					}
				);

				m_cntCustomerOrder = g_pending.size();
			}
		}
		catch (...)
		{
			throw;
		}
	}

	/*
	* Creats a temporary vector called temp and pushes the first station in line.
	* Creates 2 pointer Nextstation and cont. Goes through Line and finds the nextStation in Line, 
	  Assigns it to cont, pushes cont into temp and assigns to nextStation of cont to nextStation.
	  This gos on until All last station is pushed and nextStation becomes nullptr.
	* Copies temp to m_activeLine.
	*/
	void LineManager::reorderStations()
	{
		std::vector<Workstation*> temp;
		temp.push_back(m_firstStation);
		Workstation* nextStation = m_firstStation->getNextStation();
		Workstation* cont = nullptr;
		while (nextStation)
		{
			for (auto t : m_activeLine)
			{
				if (nextStation == t)
				{
					cont = t;
				}
			}
			temp.push_back(cont);
			nextStation = cont->getNextStation();
		}
		std::copy(temp.begin(), temp.end(), m_activeLine.begin());
	}
	bool LineManager::run(std::ostream& os)
	{
		static size_t num = 1u;
		os << "Line Manager Iteration: " << num << std::endl;
		num++;
		if (g_pending.size())
		{
			*m_firstStation += std::move(g_pending.front());
			g_pending.pop_front();
		}
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* w)
			{
				w->fill(os);
			}
		);
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](Workstation* w)
			{
				w->attemptToMoveOrder();
			}
		);
		return m_cntCustomerOrder == g_completed.size() + g_incomplete.size();
	}
	void LineManager::display(std::ostream& os) const
	{
		std::for_each(m_activeLine.begin(), m_activeLine.end(), [&](const Workstation* w)
			{
				w->display(os);
			}
		);
	}
}