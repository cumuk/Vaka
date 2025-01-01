# Oklidis Case Study

This repository is created for the **Oklidis Case Study**. The program processes the provided `Data_Processor_Case_Study.csv` file and generates the following outputs:

### Outputs
- **Total salary** of all employees.
- **Average age** of employees.
- The **department** with the highest total salary.
- The **number of employees** in each department.

### CSV File Format
The input CSV file should be structured as follows:

| ID   | Name         | Age  | Department | Salary  |
|------|--------------|------|------------|---------|
| 1    | John Doe     | 34   | IT         | 70000   |
| 2    | Jane Smith   | 28   | HR         | 48000   |
| 3    | Bob Johnson  | 45   | Finance    | 120000  |

### Building and Running the Program
1. Double-click on `build.bat`.
2. The script will compile the program and generate an executable file named `DataProcessor.exe`.
3. Executable runs automatically after build to process the CSV file and generate the outputs.

### Sample Output
```
Total Salary: $9,801,086
Average Age: 41.71
Department with Highest Salary: Sales ($2,607,639)
Employees per Department:
	Marketing: 17
	IT: 18
	Sales: 25
	Finance: 20
	HR: 20
```


