#ifndef PAYROLL_H
#define PAYROLL_H

#include <vector>

#include "Employee.h"
#include "PaySlip.h"

class Payroll {
 private:
  float total_Payroll_Cost;  // Cost of total wages
  float company_fund;        // Salaries are paid from the company fund
  // Array of payslips
  vector<PaySlip> payslips;
  // employees in the company
  vector<Employee> employees;

 public:
  // Constructor
  Payroll();
  Payroll(long double company_fund);
  // Process payroll
  bool processPayRoll();      // Process the payroll for all employees
  void calculateTotalCost();  // Calculates the total cost (including tax and
                              // superannuation)
  // Adding and removing employees from employees
  void addEmployee(Employee employee);
  bool removeEmployee(int employee_id);

  // Generates payslips for employees
  void generatePaySlips();

  // Adds Payslip to payslips
  void addPaySlip(PaySlip payslip);

  // Setters
  void setCompanyFund(double add_fund);

  // Getter functions for data members
  std::string *getEmployeesDetails();
  Employee *getEmployee(int employee_id);
  double getTotalCost();
  long double getCompanyFund();
  int getNumberOfEmployees();
  vector<Employee> getEmployees();
};

#endif