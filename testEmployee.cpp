#include <iostream>

#include "Employee.h"

using namespace std;

class EmployeeTest {
 private:
  void testConstructor() {
    cout << "Testing Employee Constructor..." << endl;

    Employee employee("John Doe", 101, 30, true, "Developer", FullTime,
                      60000.0);

    // Check if the employee's attributes are set correctly
    if (employee.getName() != "John Doe") {
      cout << "Test failed: Name is incorrect!" << endl;
    } else {
      cout << "Test passed: Name is correct!" << endl;
    }

    if (employee.getEmployeeID() != 101) {
      cout << "Test failed: Employee ID is incorrect!" << endl;
    } else {
      cout << "Test passed: Employee ID is correct!" << endl;
    }

    if (employee.getAge() != 30) {
      cout << "Test failed: Age is incorrect!" << endl;
    } else {
      cout << "Test passed: Age is correct!" << endl;
    }

    if (employee.getPosition() != "Developer") {
      cout << "Test failed: Position is incorrect!" << endl;
    } else {
      cout << "Test passed: Position is correct!" << endl;
    }
  }

  void testCalculateTotalPayment_FullTime() {
    cout << "\nTesting Total Payment Calculation for Full-Time Employee..."
         << endl;

    Employee employee("Jane Smith", 102, 28, true, "Manager", FullTime,
                      80000.0);
    float expectedPayment = 80000.0;  // Full-time employees have fixed salary

    float calculatedPayment = employee.calculateGrossPay();

    if (calculatedPayment != expectedPayment) {
      cout << "Test failed: Total payment for full-time is incorrect!" << endl;
      cout << "Expected: $" << expectedPayment << ", Calculated: $"
           << calculatedPayment << endl;
    } else {
      cout << "Test passed: Total payment for full-time is correct!" << endl;
    }
  }

  void testCalculateTotalPayment_PartTime() {
    cout << "\nTesting Total Payment Calculation for Part-Time Employee..."
         << endl;

    Employee employee("Alice Johnson", 103, 22, true, "Intern", PartTime, 20.0);
    employee.setHoursWorked(30);  // Setting hours worked for part-time

    float expectedPayment = 20.0 * 30;  // Hourly rate * hours worked
    float calculatedPayment = employee.calculateGrossPay();

    if (calculatedPayment != expectedPayment) {
      cout << "Test failed: Total payment for part-time is incorrect!" << endl;
      cout << "Expected: $" << expectedPayment << ", Calculated: $"
           << calculatedPayment << endl;
    } else {
      cout << "Test passed: Total payment for part-time is correct!" << endl;
    }
  }

  void testSetHoursWorked() {
    cout << "\nTesting Set Hours Worked..." << endl;

    Employee employee("Bob Brown", 104, 35, true, "Technician", PartTime, 15.0);
    employee.setHoursWorked(40);  // Set hours worked

    if (employee.getHoursWorked() != 40) {
      cout << "Test failed: Hours worked not set correctly!" << endl;
    } else {
      cout << "Test passed: Hours worked set correctly!" << endl;
    }
  }

  void testGetWorkType() {
    cout << "\nTesting Get Work Type..." << endl;

    Employee employee("Eve White", 105, 26, true, "Designer", Casual, 25.0);
    if (employee.getWorkType() != Casual) {
      cout << "Test failed: Work type is incorrect!" << endl;
    } else {
      cout << "Test passed: Work type is correct!" << endl;
    }
  }

 public:
  void runTests() {
    testConstructor();
    testCalculateTotalPayment_FullTime();
    testCalculateTotalPayment_PartTime();
    testSetHoursWorked();
    testGetWorkType();
  }
};

// Testing in main function
int main() {
  EmployeeTest employeeTests;

  cout << "Starting unit tests for Employee class..." << endl;

  // Run all the tests
  employeeTests.runTests();

  return 0;
}