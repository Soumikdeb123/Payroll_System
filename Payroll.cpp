#include "Payroll.h"

#include <iostream>

using namespace std;

Payroll::Payroll() {
  this->company_fund = 0;
  this->total_Payroll_Cost = 0;
}

// Constructor that initialises company fund
Payroll::Payroll(long double company_fund) {
  this->company_fund = company_fund;
  this->total_Payroll_Cost = 0;
}

// Pays the outstanding PayRollCost and returns true if funds are sufficient.
// Returns false if not
bool Payroll::processPayRoll() {
  calculateTotalCost();
  if (company_fund < total_Payroll_Cost) {
    return false;
  } else
    company_fund -= total_Payroll_Cost;
  total_Payroll_Cost = 0;
  for (int i = 0; i < employees.size(); i++) {
    // Set hours to 0 again to reset
    employees[i].setHoursWorked(0);
  }
  return true;
}

// Calculates the total money needed from the company fund
void Payroll::calculateTotalCost() {
  // Reset the cost to 0
  total_Payroll_Cost = 0;

  // Go through the employees and calculate their total cost using an iterator
  // to iterate over the vector
  for (auto it = employees.begin(); it != employees.end(); ++it) {
    total_Payroll_Cost += it->calculateGrossPay();
  }
}

// Add an Employee object to the vector
void Payroll::addEmployee(Employee employee) { employees.push_back(employee); }

/* Takes an employee_id and removes the relevant employee from the payroll and
 returns true. Returns false if no such employee exists. */
bool Payroll::removeEmployee(int employee_id) {
  // Search through the array to find the index using an iterator to iterate
  // over the vector
  for (auto it = employees.begin(); it != employees.end();) {
    if (employee_id == it->getEmployeeID()) {
      employees.erase(it);
      return true;
    } else {
      ++it;
    }
  }
  return false;
}

// Add payslip to the payslip array
void Payroll::addPaySlip(PaySlip payslip) { payslips.push_back(payslip); }

// Returns employee details as a list of strings of the form
// id|name|position|age
std::string *Payroll::getEmployeesDetails() {
  std::string *details = new std::string[employees.size()];
  for (int i = 0; i < (int)employees.size(); i++) {
    Employee employee = employees[i];
    details[i] = to_string(employee.getEmployeeID()) + " | " +
                 employee.getName() + " | " + employee.getPosition() + " | " +
                 to_string(employee.getAge());
  }
  return details;
}

Employee *Payroll::getEmployee(int employee_id) {
  for (int i = 0; i < (int)employees.size(); i++) {
    if (employee_id == employees[i].getEmployeeID()) {
      return &employees[i];
    }
  }
  return nullptr;
}

// Generate payslips of all employees and add to outstanding cost
void Payroll::generatePaySlips() {
  for (PaySlip payslip :
       payslips) {  // Iterates over all Payslips in the "payslip" vector and
    // stores in variable payslip
    payslip.generateSlip();
  }
  calculateTotalCost();
}

// Allow managers to add money. This will be done through utility class
void Payroll::setCompanyFund(double add_fund) {
  this->company_fund = company_fund + add_fund;
}

// Getter functions defined
int Payroll::getNumberOfEmployees() { return employees.size(); }
long double Payroll::getCompanyFund() { return company_fund; }
double Payroll::getTotalCost() { return total_Payroll_Cost; }
vector<Employee> Payroll::getEmployees() { return employees; }