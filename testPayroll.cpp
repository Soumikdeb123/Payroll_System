// This unit test ensures that call the components in the payroll class is
// working without any errors
#include <iomanip>
#include <iostream>

#include "Payroll.h"
using namespace std;

class PayRollTest {
 private:
  // Using default constructor for unit test
  Payroll payroll;

  void testDefinedConstructor() {
    // Parameterized constructor
    Payroll payFund(99000);
    if (payFund.getCompanyFund() < 0) {
      cout << "Company fund was not updated. Test failed!" << endl;
    } else {
      cout << "Company fund initialised! The current fund is: "
           << payFund.getCompanyFund() << endl;
    }
    // Current employee cost should be 0 without any calculations
    if (payFund.getTotalCost() > 0) {
      cout << "The cost for employees is not $0! Test failed!" << endl;
    } else {
      cout << "The current cost for employee is $0. Test passed!" << endl;
    }
  }

  // Adding employee feature unit test
  void testAddEmployee() {
    cout << "Testing adding employee feature..." << endl;
    cout << "\n";
    // Create different employees
    Employee employee1("Jacky", 1, 33, true, "Sales", FullTime, 1000,
                       40);  // Constructor from the employee class
    Employee employee2("Anna", 2, 29, false, "Marketing", PartTime, 20.5, 25);
    Employee employee3("Brian", 3, 45, true, "HR", FullTime, 40.0, 38);
    Employee employee4("Sophia", 4, 22, true, "Engineering", FullTime, 50000,
                       40);
    Employee employee5("Michael", 5, 38, false, "Finance", PartTime, 19.223,
                       20);
    Employee employee6("Emily", 6, 50, true, "Management", FullTime, 55.2,
                       45000);
    // Add employee
    payroll.addEmployee(employee1);
    payroll.addEmployee(employee2);
    payroll.addEmployee(employee3);
    payroll.addEmployee(employee4);
    payroll.addEmployee(employee5);
    payroll.addEmployee(employee6);

    for (int i = 0; i < payroll.getNumberOfEmployees(); i++) {
      if (i < payroll.getNumberOfEmployees()) {
        cout << "Employee " << i + 1 << " added successfully!" << endl;
      } else {
        cout << "Employee " << i + 1 << " could not be added!" << endl;
      }
    }
  }

  // Calculate employee salary test
  void testTotalCost() {
    cout << "\n";
    cout << "Testing the calculations system for employees..." << endl;
    cout << "\n";
    // Check the total cost before calculation
    if (payroll.getTotalCost() > 0) {
      cout << "Variable not initialised!" << endl;
    } else {
      cout << "Variable is set to 0 as calculations has not been done! Test "
              "passed!"
           << endl;
    }
    payroll.calculateTotalCost();
    double totalSalary = payroll.getTotalCost();

    cout << "After calculations, the total cost for the above employees is: $"
         << totalSalary << endl;
  }

  // Unit test removeEmployee
  void testRemoveEmployee() {
    cout << "\n";
    cout << "Testing removing employee feature..." << endl;
    cout << "\n";

    // Get the number of employees before removing
    int totalEmployees = payroll.getNumberOfEmployees();
    cout << "The number of employees before removing from the system is: "
         << totalEmployees << endl;
    // Remove employee
    bool deleteEmployee = payroll.removeEmployee(2);

    if (deleteEmployee == true) {
      cout << "Employee removed successfully! Current number of employees in "
              "the system is: "
           << payroll.getNumberOfEmployees() << endl;
    } else {
      cout << "Employee id could not be found or failed to remove employee!"
           << endl;
    }
  }

  // Unit test process payroll
  void testProcessPayroll() {
    cout << "\n";
    cout << "Testing the processing payroll feature..." << endl;
    cout << "\n";

    // Initialise with the company fund
    Payroll companyX(5000000);

    // Create some employees
    Employee employee1("Jacky", 1, 33, true, "Sales", FullTime, 32500,
                       40);  // Constructor from the employee class
    Employee employee2("Anna", 2, 29, false, "Marketing", PartTime, 28.5, 25);
    Employee employee3("Brian", 3, 45, true, "HR", FullTime, 40.0, 38);
    Employee employee4("Sophia", 4, 22, true, "Engineering", FullTime, 40000,
                       40);
    // Add employee
    companyX.addEmployee(employee1);
    companyX.addEmployee(employee2);
    companyX.addEmployee(employee3);
    companyX.addEmployee(employee4);

    // Check balance before automating payroll
    cout << "You have $" << std::fixed << std::setprecision(3)
         << companyX.getCompanyFund() << " before processing money." << endl;

    // Calculate total payment
    companyX.calculateTotalCost();

    // Check the total spending
    cout << "The total money required to be processed: $" << std::fixed
         << std::setprecision(3) << companyX.getTotalCost() << endl;

    cout << "\n";

    // Automate money
    bool processMoney = companyX.processPayRoll();

    if (processMoney == true) {
      cout << "Salary has been processed for all the employees!" << endl;
      cout << "Your current balance is: " << companyX.getCompanyFund() << endl;
    } else {
      cout << "Failed to process money. No sufficient fund" << endl;
    }
  }
  void testGenerateSlip() {
    cout << "\n";
    cout << "Testing payslip generation..." << endl;
    // Create a payslip
    PaySlip payslip(3, 3222);

    // Add it to the payslip array
    payroll.addPaySlip(payslip);

    // Now generate
    payroll.generatePaySlips();
  }

 public:
  void runTests() {
    testDefinedConstructor();
    testAddEmployee();
    testTotalCost();
    testRemoveEmployee();
    testProcessPayroll();
    testGenerateSlip();
  }
};
// Testing in main function
int main() {
  PayRollTest payroll_tests;

  cout << "Starting unit test for payroll class..." << endl;
  cout << "\n";

  // Test all the functionalities
  payroll_tests.runTests();

  return 0;
}