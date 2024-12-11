#include "Employee.h"

// Constructor initialization
Employee::Employee(const std::string &name, int employee_id, int age,
                   bool is_active, std::string position, WorkType work_type,
                   float pay_rate, int hours_worked)
    : User(name, employee_id, age, is_active),
      position(position),
      work_type(work_type),
      pay_rate(pay_rate),
      hours_worked(hours_worked) {}

// Getter for pay_rate
float Employee::getPayRate() const { return pay_rate; }

// Getter for work_type
WorkType Employee::getWorkType() const { return work_type; }

// Getter for hours_worked
int Employee::getHoursWorked() const { return hours_worked; }

// Getter for position
std::string Employee::getPosition() const { return position; }

// Setter for hours_worked
void Employee::setHoursWorked(int hours) { this->hours_worked = hours; }

// Method to calculate total payment
float Employee::calculateGrossPay() const {
  if (work_type == FullTime) {
    // Full-time employees have a fixed salary (pay_rate represents salary)
    return pay_rate;
  } else {
    // For other work types, pay_rate is hourly, so multiply by hours worked
    return pay_rate * hours_worked;
  }
}