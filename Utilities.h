#ifndef Utilities_h
#define Utilities_h

#include <fstream>
#include <iostream>

#include "Employee.h"
#include "PaySlip.h"
#include "Payroll.h"
#include "SuperAnnuation.h"
#include "Taxes.h"

class Utilities {
 public:
  // Add and remove employees
  static void removeEmployee(Payroll *payroll_ptr);
  static void addNewEmployee(Payroll *payroll_ptr);

  // View all details of all employees stored in the form:
  // id | name | position | age
  static void viewEmployeeDetails(Payroll payroll);

// Save and load data to file
  static void saveData(Payroll payroll);
  static void loadData(Payroll *payroll_ptr);

// Start a new payroll
  static void initialisePayroll(Payroll *payroll_ptr);

  //Input an ID and return an employee ptr
  static Employee *getEmployeeFromId(Payroll *payroll);
  
  // Create payslip and add it to the vector
  static void CreatePayslip(Payroll *payroll_ptr);

  //Add more to company fund
  static void addCompanyFund(Payroll *payroll_ptr);

  // Input validation to ensure it is the right type
  template <typename T>
  static T sanitizeInput();

// Ensure a non-negative number is inputted
  template <typename T>
  static T getNonNegativeNumber();
};

#endif