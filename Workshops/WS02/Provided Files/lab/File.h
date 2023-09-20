#ifndef SDDS_FILE_H_
#define SDDS_FILE_H_
namespace sdds {
   bool openFile(const char filename[]);
   void closeFile();
   int noOfRecords();
 
   bool read(char* employeeName);
   bool read(int &employeeNumber);
   bool read(double &employeeSalary);
}
#endif // !SDDS_FILE_H_
