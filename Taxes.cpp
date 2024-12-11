#include "Taxes.h"

Taxes::Taxes(float rate) : Adjustment(rate) {}

float Taxes::calculateAdjustment(float income) {
  // Example calculation: Flat tax rate
  // You can modify this to include tax brackets or other logic
  // Simply apply the tax rate to the income and make it negative as it is a
  // deduction
  return -(income * rate);
}