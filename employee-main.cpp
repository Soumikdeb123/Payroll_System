#include "Utilities.h"

using namespace std;

int main() {
  // Check if save files exist
  ifstream employeeFile("employees.txt");

  Payroll payroll;
  // if it does not exist, exit the program
  if (!employeeFile.is_open()) {
    cout << "No save file detected. Please ask your manager to create and save "
            "a payroll"
         << endl;
    return 0;
  }

  // Otherwise, load data
  Utilities::loadData(&payroll);

  // Login as Employee
  cout << "Logging in:" << endl;
  Employee *employee_ptr = Utilities::getEmployeeFromId(&payroll);
  cout << "Logged in Successfully as: " << employee_ptr->getName() << endl;

  int response;
  do  // Iterate over all the options until the user exits the program
  {
    // Print options and ask user for response
    cout << "What do you want to do? (Select the number of the option you want)"
         << endl;
    cout << "1. Save and Exit" << endl;
    cout << "2. Set number of hours worked this pay cycle" << endl;
    cout << "3. View amount to be paid this pay cycle" << endl;
    cout << "4. Get other details" << endl;
    cout << "Enter your response: ";

    response = Utilities::sanitizeInput<int>();
    cout << endl;

    switch (response) {
      case 1:  // Exit
        Utilities::saveData(payroll);
        cout << "Exiting program..." << endl;
        break;
      case 2:  // set num_hours
        cout << "Enter Number of Hours: ";
        int hours;
        hours = Utilities::getNonNegativeNumber<int>();
        employee_ptr->setHoursWorked(hours);
        cout << "Hours set successfully";
        break;
      case 3:
        cout << "This cycle you will be paid: $"
             << employee_ptr->calculateGrossPay() << endl;
        break;
      case 4:
        cout << "ID: " << employee_ptr->getEmployeeID() << endl;
        cout << "Name: " << employee_ptr->getName() << endl;
        cout << "Position: " << employee_ptr->getPosition() << endl;
        cout << "Age: " << employee_ptr->getAge() << endl;
        cout << "PayRate: " << employee_ptr->getPayRate() << endl;
        cout << "Hours Worked: " << employee_ptr->getHoursWorked() << endl;

        break;
      default:
        cout << "Invalid option" << endl;
        break;
    }
    cout << endl << endl;
  } while (response != 1);
}