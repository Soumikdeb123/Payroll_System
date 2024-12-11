#ifndef SUPERANNUATION_H
#define SUPERANNUATION_H

#include <string>

#include "Adjustment.h"

class SuperAnnuation : public Adjustment {
 private:
  std::string provider;

 public:
  // Constructor
  SuperAnnuation(float rate, const std::string &provider);

  // Overrides abstract base class
  float calculateAdjustment(float income);

  // Company’s contribution based on income
  float calculateCompanyContribution(float income);

  // getter
  std::string getProvider() const;
};

#endif