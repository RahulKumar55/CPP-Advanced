/*Name: Rahul Kumar
* Student ID: 157197211
* Email ID: rkumar141@myseneca.ca
* Date: 11\19\2022
* I have done all the coding by myself and only copied the code that my professor provided to complete my workshops and assignments.
*/
#include "GeneratingList.h"
#include "EmpProfile.h"
#include "WritingRecord.h"

using namespace std;

namespace sdds {
	GeneratingList<EmployeeWage> writeRaw(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal) {
		GeneratingList<EmployeeWage> activeEmp;
		
		// TODO: Add your code here to build a list of employees
		//         using raw pointers
		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id)
				{
					EmployeeWage* e = new EmployeeWage(emp[i].name, sal[j].salary);
					
					
					try
					{
						e->rangeValidator();
						if (!activeEmp.checkSIN(emp[i].id))
						{
							std::string s = "SIN not valid";
							throw s;
						}
						activeEmp += e;
					}
					catch (...)
					{
						delete e;
						throw;
					}
					delete e;
				}
			}
		}
		
		return activeEmp;
	}

	GeneratingList<EmployeeWage> writeSmart(const GeneratingList<Employee>& emp, const GeneratingList<Salary>& sal)
	{
		GeneratingList<EmployeeWage> activeEmp;

		for (size_t i = 0; i < emp.size(); i++)
		{
			for (size_t j = 0; j < sal.size(); j++)
			{
				if (emp[i].id == sal[j].id)
				{
					std::unique_ptr<EmployeeWage> e(new EmployeeWage(emp[i].name, sal[j].salary));

					
					try
					{
						e->rangeValidator();
						if (!activeEmp.checkSIN(emp[i].id))
						{
							std::string s = "SIN not valid";
							throw s;
						}
						activeEmp += std::move(e);
					}
					catch (...)
					{
						throw;
					}
					
				}
			}
		}

		return activeEmp;
	}

}