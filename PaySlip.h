#ifndef PAYSLIP_H
#define PAYSLIP_H

#include <string>
#include <vector>

#include "Adjustment.h"

using namespace std;

class PaySlip {
 private:
  vector<Adjustment *> adjustment_ptrs;
  int employee_id;
  float gross_pay, net_pay;

 public:
  // Constructors
  PaySlip();
  PaySlip(int employee_id, int gross_pay);

  // Adding and removing from adjustment_ptrs 
  void addAdjustment(Adjustment *adjustment);
  void removeLastAdjustment();

  // Generate a Payslip
  void generateSlip();

  // Getters
  float getGrossPay();
  float getNetPay();

  // Setters
  void setGrossPay(float gross_pay);
  void setNetPay(float gross_pay);

};

#endif