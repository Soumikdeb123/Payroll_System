#ifndef ADJUSTMENT_H
#define ADJUSTMENT_H

// Adjustment is an abstract and fully virtual class that Superannuation and
// Taxes Inherit from
class Adjustment {
 protected:
  float rate;

 public:
  Adjustment(float rate);
  virtual ~Adjustment();
  virtual float calculateAdjustment(float income);
};

#endif