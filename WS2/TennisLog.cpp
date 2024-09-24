/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 09\16\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/

#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <fstream>
#include "TennisLog.h"

using namespace sdds;

namespace sdds
{
	
	TennisMatch::TennisMatch()
	{
		m_tournid = nullptr;
		m_matchname = nullptr;
		m_winn = nullptr;
		m_los = nullptr;
		m_matchid = 0;
	}

	// Custom constructor, Stores character strings Dynamically 
	TennisMatch::TennisMatch(const char* tourn, const char* name, unsigned int id, const char* winn, const char* los)
	{
		m_matchid = id;

		if (tourn)
		{
			m_tournid = new char[strlen(tourn) + 1];
			strcpy(m_tournid, tourn);
		}
		else m_tournid = nullptr;

		if (name)
		{
			m_matchname = new char[strlen(name) + 1];
			strcpy(m_matchname, name);
		}
		else m_matchname = nullptr;

		if (winn)
		{
			m_winn = new char[strlen(winn) + 1];
			strcpy(m_winn, winn);
		}
		else m_winn = nullptr;

		if (los)
		{
			m_los = new char[strlen(los) + 1];
			strcpy(m_los, los);
		}
		else m_los = nullptr;
	}

	TennisMatch::TennisMatch(const TennisMatch& t)
	{
		m_tournid = nullptr;
		m_matchname = nullptr;
		m_winn = nullptr;
		m_los = nullptr;
		*this = t;
	}

	TennisMatch::TennisMatch(TennisMatch&& t)
	{
		m_tournid = nullptr;
		m_matchname = nullptr;
		m_winn = nullptr;
		m_los = nullptr;
		*this = std::move(t);
	}

	TennisMatch::~TennisMatch()
	{
		setEmpty();
	}

	TennisMatch& TennisMatch::operator=(const TennisMatch& t)
	{
		if (this != &t)
		{
			setEmpty();
			m_matchid = t.m_matchid;
	
			m_tournid = new char[strlen(t.m_tournid) + 1];
			strcpy(m_tournid, t.m_tournid);

			m_matchname = new char[strlen(t.m_matchname) + 1];
			strcpy(m_matchname, t.m_matchname);
			
			m_winn = new char[strlen(t.m_winn) + 1];
			strcpy(m_winn, t.m_winn);
			
			m_los = new char[strlen(t.m_los) + 1];
			strcpy(m_los, t.m_los);
			
		}
		else
		{
			setEmpty();
		}
		return *this;
	}

	TennisMatch& TennisMatch::operator=(TennisMatch&& t)
	{
		if (this != &t)
		{
			
			setEmpty();
			m_matchid = t.m_matchid;

			m_tournid = t.m_tournid;
			t.m_tournid = nullptr;

			m_matchname = t.m_matchname;
			t.m_matchname = nullptr;

			m_winn = t.m_winn;
			t.m_winn = nullptr;

			m_los = t.m_los;
			t.m_los = nullptr;

			t.m_matchid = 0;

		}
		else
		{
			setEmpty();
		}
		return *this;
	}

	TennisMatch::operator bool()
	{
		return m_matchid != 0;
	}

	void TennisMatch::display(std::ostream& os)
	{
		if (*this)
		{
			os.fill('.');
			os.width(20);
			os.setf(std::ios::right);
			os << "Tourney ID" << " : ";
			os.unsetf(std::ios::right);
			os.width(30);
			os.setf(std::ios::left);
			os << m_tournid << std::endl;
			os.unsetf(std::ios::left);

			os.width(20);
			os.setf(std::ios::right);
			os << "Match ID" << " : ";
			os.unsetf(std::ios::right);
			os.width(30);
			os.setf(std::ios::left);
			os << m_matchid << std::endl;
			os.unsetf(std::ios::left);

			os.width(20);
			os.setf(std::ios::right);
			os << "Tourney" << " : ";
			os.unsetf(std::ios::right);
			os.width(30);
			os.setf(std::ios::left);
			os << m_matchname << std::endl;
			os.unsetf(std::ios::left);

			os.width(20);
			os.setf(std::ios::right);
			os << "Winner" << " : ";
			os.unsetf(std::ios::right);
			os.width(30);
			os.setf(std::ios::left);
			os << m_winn << std::endl;
			os.unsetf(std::ios::left);

			os.width(20);
			os.setf(std::ios::right);
			os << "Loser" << " : ";
			os.unsetf(std::ios::right);
			os.width(30);
			os.setf(std::ios::left);
			os << m_los << std::endl;
			os.unsetf(std::ios::left);
		}
		else
		{
			os << "Empty Match";
		}
	}

	//Private function, Sets the class to a safe empty state
	void TennisMatch::setEmpty()
	{
		delete[] m_tournid;
		m_tournid = nullptr;
		delete[] m_matchname;
		m_matchname = nullptr;
		delete[] m_winn;
		m_winn = nullptr;
		delete[] m_los;
		m_los = nullptr;
		m_matchid = 0;
	}

	std::ostream& operator<<(std::ostream& os, TennisMatch& t)
	{
		t.display(os);
		return os;
	}






	TennisLog::TennisLog()
	{
		m_matches = nullptr;
		m_cnt = 0;
	}

	TennisLog::TennisLog(const char* file)
	{
		size_t recs = 0;
		char tournid[100];
		char matchname[100];
		unsigned int matchid;
		char winn[100];
		char los[100];
		std::ifstream f(file);
		if (f.is_open())
		{
			f.ignore(2000,'\n');
			while (!f.eof())
			{
				if (f.get() == '\n')
				{
					recs++;
				}
			}
			f.close();
		}

		if (recs != 0)
		{
			m_cnt = recs;
			m_matches = new TennisMatch[m_cnt];
			std::ifstream f(file);
			if (f.is_open())
			{
				f.ignore(2000, '\n');
			}
			for (size_t i = 0; i < m_cnt; i++)
			{
				f.get(tournid, 100, ',');
				f.ignore();
				f.get(matchname, 100, ',');
				f.ignore();
				f >> matchid;
				f.ignore();
				f.get(winn, 100, ',');
				f.ignore();
				f.get(los, 100, '\n');
				f.ignore();

				m_matches[i] = TennisMatch(tournid, matchname, matchid, winn, los);
			}
		}
	}


	TennisLog::TennisLog(const TennisLog& T)
	{
		m_matches = nullptr;
		*this = T;
	}
	TennisLog::TennisLog(TennisLog&& T)
	{
		m_matches = nullptr;
		*this = std::move(T);
	}
	TennisLog::~TennisLog()
	{
		delete[] m_matches;
	}

	TennisLog& TennisLog::operator=(const TennisLog& T)
	{
		if (this != &T)
		{
			m_cnt = T.m_cnt;
			if (m_cnt)
			{
				delete[] m_matches;
				m_matches = new TennisMatch[m_cnt];
				for (size_t i = 0; i < m_cnt; i++)
				{
					m_matches[i] = T.m_matches[i];
				}
			}
		}
		return *this;
	}

	TennisLog& TennisLog::operator=(TennisLog&& T)
	{
		if (this != &T)
		{
			m_cnt = T.m_cnt;
			if (m_cnt)
			{
				delete[] m_matches;
			    m_matches = T.m_matches;
				T.m_matches = nullptr;
				T.m_cnt = 0;
			}
		}
		return *this;
	}

	void TennisLog::addMatch(TennisMatch& t)
	{
		if (t)
		{
			TennisMatch* temp = new TennisMatch[m_cnt + 1];
			for (size_t i = 0; i < m_cnt; i++)
			{
				temp[i] = m_matches[i];
			}
			temp[m_cnt] = t;
			m_cnt++;
			delete[] m_matches;
			m_matches = new TennisMatch[m_cnt];
			for (size_t i = 0; i < m_cnt; i++)
			{
				m_matches[i] = temp[i];
			}
			delete[] temp;
		}
	}

	TennisLog& TennisLog::findMatches(const char* name)
	{
		static TennisLog T1;
		T1.setEmpty();
		for (size_t i = 0; i < m_cnt; i++)
		{
			if(!strcmp(name, m_matches[i].m_winn) || !strcmp(name, m_matches[i].m_los))
			{
				T1.addMatch(m_matches[i]);
			}
		}
		return T1;
	}

	TennisMatch& TennisLog::operator[](size_t s)
	{
		static TennisMatch t1;
		t1.setEmpty();
		if (m_cnt != 0)
		{
			t1 = m_matches[s];
		}
		return t1;
	}

	TennisLog::operator size_t()
	{
		return m_cnt;
	}

	//Private function, Sets the class a safe empty state
	void TennisLog::setEmpty()
	{
		m_cnt = 0;
		delete[] m_matches;
		m_matches = nullptr;
	}
}