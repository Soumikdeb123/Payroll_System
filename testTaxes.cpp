#include <cassert>
#include <iostream>

#include "Taxes.h"

void testConstructor() {
  Taxes tax(0.2f);  // 20% tax rate
  std::cout << "Constructor test passed." << std::endl;
}

void testCalculateAdjustment() {
  Taxes tax(0.2f);  // 20% tax rate

  float income1 = 1000.0f;
  float expectedTax1 = -(income1 * 0.2f);  // Tax deducted should be -200
  assert(tax.calculateAdjustment(income1) == expectedTax1);
  std::cout << "testCalculateAdjustment for income1 passed." << std::endl;

  float income2 = 5000.0f;
  float expectedTax2 = -(income2 * 0.2f);  // Tax deducted should be -1000
  assert(tax.calculateAdjustment(income2) == expectedTax2);
  std::cout << "testCalculateAdjustment for income2 passed." << std::endl;

  float income3 = 0.0f;
  float expectedTax3 = 0.0f;  // No tax deducted
  assert(tax.calculateAdjustment(income3) == expectedTax3);
  std::cout << "testCalculateAdjustment for income3 passed." << std::endl;

  // Optionally add tests for negative income, if applicable
}

int main() {
  testConstructor();
  testCalculateAdjustment();
  std::cout << "All tests for Taxes passed!" << std::endl;
  return 0;
}