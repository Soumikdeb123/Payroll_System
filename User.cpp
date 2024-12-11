#include "User.h"

// Constructor
User::User(const std::string &name, int employee_id, int age, bool is_active)
    : name(name), employee_id(employee_id), age(age), is_active(is_active) {}

// Getters and setters for user
std::string User::getName() const { return name; }

int User::getEmployeeID() const { return employee_id; }

int User::getAge() const { return age; }

bool User::getIsActive() const { return is_active; }