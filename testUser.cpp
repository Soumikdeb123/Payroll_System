#include <cassert>
#include <iostream>

#include "User.h"

void testConstructor() {
  User user("Alice", 12345, 30, true);
  assert(user.getName() == "Alice");
  assert(user.getEmployeeID() == 12345);
  assert(user.getAge() == 30);
  assert(user.getIsActive() == true);
  std::cout << "Constructor test passed." << std::endl;
}

void testGetters() {
  User user("Bob", 67890, 25, false);
  assert(user.getName() == "Bob");
  assert(user.getEmployeeID() == 67890);
  assert(user.getAge() == 25);
  assert(user.getIsActive() == false);
  std::cout << "Getters test passed." << std::endl;
}

int main() {
  testConstructor();
  testGetters();
  std::cout << "All tests for User passed!" << std::endl;
  return 0;
}