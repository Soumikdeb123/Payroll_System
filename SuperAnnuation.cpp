#include "SuperAnnuation.h"

SuperAnnuation::SuperAnnuation(float rate, const std::string &provider)
    : Adjustment(rate), provider(provider) {}

float SuperAnnuation::calculateAdjustment(float income) {
  // Example calculation: Superannuation contribution as a percentage of income
  return income * rate;
}

float SuperAnnuation::calculateCompanyContribution(float income) {
  // Example: Company contributes 10% of income as part of superannuation
  return income * 0.10f;  // This can be adjusted based on company policy
}

std::string SuperAnnuation::getProvider() const { return provider; }