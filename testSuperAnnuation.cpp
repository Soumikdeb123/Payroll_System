#include <iostream>

#include "SuperAnnuation.h"

void testSuperAnnuation() {
  // Test data
  float rate = 0.09f;  // 9% superannuation rate
  std::string provider = "Super Fund Provider";
  float income = 5000.0f;  // Example income

  // Create a SuperAnnuation object
  SuperAnnuation super(rate, provider);

  // Test calculateAdjustment method
  float employeeContribution = super.calculateAdjustment(income);
  std::cout << "Employee contribution (9% of income): $" << employeeContribution
            << std::endl;

  // Test calculateCompanyContribution method
  float companyContribution = super.calculateCompanyContribution(income);
  std::cout << "Company contribution (10% of income): $" << companyContribution
            << std::endl;

  // Test getProvider method
  std::string providerName = super.getProvider();
  std::cout << "Superannuation provider: " << providerName << std::endl;
}

int main() {
  std::cout << "Testing SuperAnnuation Class:" << std::endl;
  testSuperAnnuation();
  return 0;
}