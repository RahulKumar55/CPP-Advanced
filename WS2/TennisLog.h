/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 09\16\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#ifndef SDDS_TENNISLOG_H
#define SDDS_TENNISLOG_H
#include<iostream>

namespace sdds
{
	struct TennisMatch
	{
		char* m_tournid;
		char* m_matchname;
		unsigned int m_matchid;
		char* m_winn;
		char* m_los;
		void setEmpty();
	public:
		TennisMatch();
		TennisMatch(const char* tourn, const char* name, unsigned int id, const char* winn, const char* los);
		TennisMatch(const TennisMatch& t);
		TennisMatch(TennisMatch&& t);
		~TennisMatch();
		TennisMatch& operator=(const TennisMatch& t);
		TennisMatch& operator=(TennisMatch&& t);
		operator bool();
		void display(std::ostream& os);
	};

	std::ostream& operator<<(std::ostream& os, TennisMatch& t);

	class TennisLog
	{
		TennisMatch* m_matches;
		size_t m_cnt;
		void setEmpty();
	public:
		TennisLog();
		TennisLog(const char* file);
		TennisLog(const TennisLog& T);
		TennisLog(TennisLog&& T);
		~TennisLog();
		TennisLog& operator=(const TennisLog& T);
		TennisLog& operator=(TennisLog&& T);
		void addMatch(TennisMatch& t);
		TennisLog& findMatches(const char* name);
		TennisMatch& operator[](size_t s);
		operator size_t();
	};


};

#endif // !TENNISLOG_H

