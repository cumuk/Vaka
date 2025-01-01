#ifndef VAKA_H
#define VAKA_H


#define Nof_employees 100  // Maximum number of employees
typedef enum {
    Marketting,   // 0
    IT,           // 1
    Sales,        // 2
    Finance,      // 3
    HR,           // 4
    depatment_count  // The total number of departments (5)
}enumdp;

typedef struct{
    int id;                // Employee ID
    char name[50];         // Employee Name
    unsigned int age;      // Employee Age
    enumdp department;     // Employee Department (represented as an enum)
    unsigned int salary;   // Employee Salary
}ty_employee;

// Function declarations
int readcsv(ty_employee* employee, const char *filename); // Reads data from a CSV file
int calculate_total_salary(const ty_employee* employee);  // Calculates total salary of all employees
float calculate_avg_age(const ty_employee* employee);     // Calculates average age of employees
int calculate_department_total_salary(const ty_employee* employee, enumdp departmenttype); // Calculates total salary for a specific department
enumdp find_highest_paid_department(const ty_employee* employee);  // Finds the department with the highest total salary
int deptEmployeeCount(const ty_employee* employee, enumdp departmenttype); // Counts the number of employees in a specific department
char* formatNumber(int number);

#endif