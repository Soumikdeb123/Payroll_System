#ifndef TAXES_H
#define TAXES_H

#include "Adjustment.h"

class Taxes : public Adjustment {
 public:
  // Constructor
  Taxes(float rate);

  // Overides abstract base class
  float calculateAdjustment(float income);
};

#endif