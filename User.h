#ifndef USER_H
#define USER_H

#include <string>

// User is an abstract class from which Employees will Inherit
class User {
 protected:
  std::string name;
  int employee_id;
  int age;
  bool is_active;

 public:
  //Constructor
  User(const std::string &name, int employee_id, int age, bool is_active);

  //Getters
  std::string getName() const;
  int getEmployeeID() const;
  int getAge() const;
  bool getIsActive() const;
};

#endif