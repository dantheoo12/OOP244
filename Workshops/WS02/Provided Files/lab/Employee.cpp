#include <iostream>
#include "cstring.h"  // implemented in workshop 1 part 2 (DIY)
#include "Employee.h"
#include "File.h"
using namespace std;
namespace sdds {

   int noOfEmployees;
   Employee* employees;


   void sort() {
      int i, j;
      Employee temp;
      for (i = noOfEmployees - 1; i > 0; i--) {
         for (j = 0; j < i; j++) {
            if (employees[j].m_empNo > employees[j + 1].m_empNo) {
               temp = employees[j];
               employees[j] = employees[j + 1];
               employees[j + 1] = temp;
            }
         }
      }
   }

   // load a single employee record into an Employee
   bool load(Employee &emp) {
      bool ok = false;
      char name[128];
      if (read(emp.m_empNo) && read(emp.m_salary) && read(name)) {
          emp.m_name = new char[strLen(name) + 1];
          strCpy(emp.m_name, name);
          ok = true;
      }
      return ok;
   }

   // load all employees from file to employees array
   bool load() {
      bool ok = false;
      int i = 0;
      if (openFile(DATAFILE)) {
          noOfEmployees = noOfRecords();
          employees = new Employee[noOfEmployees];
          for (i = 0; i < noOfEmployees; i++) {
              load(employees[i]);
          }
          if (i != noOfEmployees) {
              cout << "Error: incorrect number of records read; the data is possibly corrupted";
          }
          else {
              ok = true;
          }
      }
      else {
         cout << "Could not open data file: " << DATAFILE<< endl;
      }
      closeFile();
      return ok;
   }

   // display a single employee record
   void display(const Employee& emp) {
       cout << emp.m_empNo << ": " << emp.m_name << ", " << emp.m_salary << endl;
   }

   // sort employees, display employee header and employee records
   void display() {
       int i = 0;
       cout << "Employee Salary report, sorted by employee number\n";
       cout << "no- Empno, Name, Salary\n";
       cout << "------------------------------------------------\n";
       sort(); 

       for (i = 0; i < noOfEmployees; i++) {
           cout << i + 1 << "- ";
           display(employees[i]);
       }
   }

   // deallocates names of employees and employees array
   void deallocateMemory() {
       int i = 0;
       for (i = 0; i < noOfEmployees; i++) {
           delete [] employees[i].m_name;
           employees[i].m_name = nullptr;
       }
       delete [] employees;
       employees = nullptr;
   }


}