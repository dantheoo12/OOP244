#ifndef SDDS_EMPLOYEE_H_
#define SDDS_EMPLOYEE_H_

#define DATAFILE "employees.csv"
namespace sdds {
    struct Employee {
        char* m_name;
        int m_empNo;
        double m_salary;
    };
    //sorts the dynamic array of employees based on the GPA of the employees.
    void sort();
    // loads a employee structue with its values from the file
    bool load(Employee& emp);
    // allocates the dyanmic array of employees and loads all the file
    // recoreds into the array
    bool load();

    // displays a employee record on the screen:
    void display(const Employee& emp);

    // sorts the employees then displays all the employees on the screen
    void display();

    // deallocates names of employees and employees array
    void deallocateMemory();
}
#endif // SDDS_EMPLOYEE_H_