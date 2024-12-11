#ifndef EMPLOYEE_H
#define EMPLOYEE_H

#include "User.h"

enum WorkType { FullTime, PartTime, Casual, Contract };

class Employee : public User {
 private:
  std::string position;
  WorkType work_type;
  float pay_rate;    // Hourly or salary rate depending on the work type
  int hours_worked;  // Track the number of hours worked

 public:
  Employee(const std::string &name, int employee_id, int age, bool is_active,
           std::string position, WorkType work_type, float pay_rate,
           int hours_worked = 0);

  // Getter for pay_rate
  float getPayRate() const;

  // Getter for work_type
  WorkType getWorkType() const;

  // Getter for hours_worked
  int getHoursWorked() const;

  // Getter for position
  std::string getPosition() const;

  // Method to calculate total payment based on work type and pay rate
  float calculateGrossPay() const;

  // Method to set hours worked
  void setHoursWorked(int hours);
};

#endif