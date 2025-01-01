#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

// Array of department names (for display purposes)
const char* departmentStrings[] = {"Marketting", "IT", "Sales","Finance","HR"};
ty_employee employee[Nof_employees];  // Array to hold employee data

// Function declarations
int readcsv(ty_employee* employee, const char *filename); // Reads data from a CSV file
int calculate_total_salary(const ty_employee* employee);  // Calculates total salary of all employees
float calculate_avg_age(const ty_employee* employee);     // Calculates average age of employees
int calculate_department_total_salary(const ty_employee* employee, enumdp departmenttype); // Calculates total salary for a specific department
enumdp find_highest_paid_department(const ty_employee* employee);  // Finds the department with the highest total salary
int deptEmployeeCount(const ty_employee* employee, enumdp departmenttype); // Counts the number of employees in a specific department
char* formatNumber(int number);

int main()
{
    
    // If the CSV file is successfully read
    if(readcsv(employee,"Data_Processor_Case_Study.csv"))
    {
        int totalsalary = calculate_total_salary(employee);

        char* s_totalsalary = formatNumber(totalsalary);
        // Print total salary of all employees
        printf("Total Salary: $%s\n",s_totalsalary );
        free(s_totalsalary); // Free dynamically allocated memory

        // Print average age of all employees
        printf("Average Age: %.2f\n", calculate_avg_age(employee));

        // Find the department with the highest salary
        enumdp highPayDept = find_highest_paid_department(employee);
        int topdeptsalary = calculate_department_total_salary(employee, highPayDept);
        
        char* s_topdeptsalary = formatNumber(topdeptsalary);
        // Print the department with the highest salary and its total salary
        printf("Department with Highest Salary: %s ($%s) \n", departmentStrings[highPayDept], s_topdeptsalary);
        free(s_topdeptsalary); // Free dynamically allocated memory
        
        // Print the number of employees per department
        printf("Employees per Department:\n");
        for(int i = 0; i < depatment_count; i++)  // Loop through each department
        {
            printf("\t%s: %d\n", departmentStrings[i], deptEmployeeCount(employee, i));  // Display number of employees in the department
        }

    }
 
    return 0;
}

// Function to read employee data from a CSV file and store it in the employee array
int readcsv(ty_employee *employee, const char *filename)
{
    char buffer[100];  // Buffer to store a line from the file
    FILE *file = fopen(filename, "r");

    if (file == NULL)
    {
        printf("Error: %s not found.", filename);  // If the file doesn't open, print an error message
        return 0;
    }

    // Check if the file format is correct (the first line should match this format)
    fgets(buffer, sizeof(buffer), file);
    if (strcmp(buffer, "ID,Name,Age,Department,Salary\n") != 0)
    {
        printf("Error: Invalid file format.");  // If the file format doesn't match, print an error message
        return 0;
    }

    // Parse the data line by line and store it in the employee array
    int row = 0;
    while (fgets(buffer, sizeof(buffer), file))
    {
        char *token;
    
        // Extract the employee ID
        token = strtok(buffer, ",");
        if(token != NULL)
        {
            employee[row].id = atoi(token);  // Convert the token to an integer and store it
        }

        // Extract the employee name
        token = strtok(NULL, ",");
        if(token != NULL)
        {
            strcpy(employee[row].name, token);  // Copy the token into the employee's name field
        }

        // Extract the employee age
        token = strtok(NULL, ",");
        if(token != NULL)
        {
            employee[row].age = atoi(token);  // Convert the token to an integer and store it
        }

        // Extract the employee's department and store it as an enum
        token = strtok(NULL, ",");
        if(token != NULL)
        {
            if(strcmp(token, "Marketting") == 0)
                employee[row].department = Marketting;
            else if(strcmp(token, "IT") == 0)
                employee[row].department = IT;
            else if(strcmp(token, "Sales") == 0)
                employee[row].department = Sales;
            else if(strcmp(token, "Finance") == 0)
                employee[row].department = Finance;
            else if(strcmp(token, "HR") == 0)
                employee[row].department = HR;
        }

        // Extract the employee salary
        token = strtok(NULL, ",");
        if(token != NULL)
        {
            employee[row].salary = atoi(token);  // Convert the token to an integer and store it
        }

        row++;  // Move to the next row in the employee array
    }

    return 1;  // Successfully read the file
}

// Function to calculate the total salary of all employees
int calculate_total_salary(const ty_employee* employee)
{
    int total = 0;
    for(int i = 0; i < Nof_employees; i++)  // Loop through all employees
    {
        total += employee[i].salary;  // Add the salary of each employee to the total
    }
    return total;  // Return the total salary
}

// Function to calculate the average age of all employees
float calculate_avg_age(const ty_employee* employee)
{
    float avg_age = 0;
    int total_age = 0;
    for(int i = 0; i < Nof_employees; i++)  // Loop through all employees
    {
        total_age += employee[i].age;  // Add the age of each employee to the total
    }
    avg_age = (float)total_age / Nof_employees;  // Calculate the average age
    return avg_age;  // Return the average age
}

// Function to calculate the total salary of employees in a specific department
int calculate_department_total_salary(const ty_employee* employee, enumdp departmenttype)
{
    int total = 0;
    for(int i = 0; i < Nof_employees; i++)  // Loop through all employees
    {
        if(employee[i].department == departmenttype)  // Check if the employee belongs to the specified department
        {
            total += employee[i].salary;  // Add the employee's salary to the total
        }
    }
    return total;  // Return the total salary for the specified department
}

// Function to find the department with the highest total salary
enumdp find_highest_paid_department(const ty_employee* employee)
{
    int highestsalary = 0;
    enumdp topdp = 0;
    for(int i = 0; i < depatment_count; i++)  // Loop through each department
    {
        int topsalary = calculate_department_total_salary(employee, i);  // Calculate the total salary for the department
        if(highestsalary < topsalary)  // Check if this department has the highest salary so far
        {
            highestsalary = topsalary;  // Update the highest salary
            topdp = i;  // Update the department with the highest salary
        }
    }
    return topdp;  // Return the department with the highest salary
}

// Function to count the number of employees in a specific department
int deptEmployeeCount(const ty_employee* employee, enumdp departmenttype)
{
    int total = 0;
    for(int i = 0; i < Nof_employees; i++)  // Loop through all employees
    {
        if(employee[i].department == departmenttype)  // Check if the employee belongs to the specified department
        {
            total++;  // Increment the employee count for this department
        }
    }
    return total;  // Return the total number of employees in the specified department
}

char* formatNumber(int number) {
    char buffer[50]; // Temporary buffer to hold the number as a string
    char* formatted; // Pointer for the formatted output string
    int length, commaCount = 0, j = 0;

    // Convert the number to a string
    sprintf(buffer, "%d", number);
    length = strlen(buffer);

    // Set the starting index for negative numbers
    int startIndex = 0;
    if (buffer[0] == '-') {
        startIndex = 1;
    }

    // Calculate the number of commas needed
    commaCount = (length - startIndex - 1) / 3;

    // Allocate memory for the formatted string
    formatted = (char*)malloc(length + commaCount + 1); // Extra commas + null terminator

    // Build the formatted string
    if (startIndex == 1) {
        formatted[j++] = '-';
    }

    for (int i = startIndex; i < length; i++) {
        formatted[j++] = buffer[i];
        if ((length - i - 1) % 3 == 0 && i != length - 1) {
            formatted[j++] = ',';
        }
    }

    formatted[j] = '\0'; // Add null terminator
    return formatted;
}
