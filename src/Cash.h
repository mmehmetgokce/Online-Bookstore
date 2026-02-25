// Author: Yusuf Göç
// Date: 22.12.2025

// Dosya Amacý: Cash (Nakit) ödeme türünü Payment sýnýfýndan türeterek tanýmlar.
// Not: Ödeme bilgisi yazdýrma iþlemi override edilerek polymorphism mantýðý kullanýlýr.
#ifndef CASH_H
#define CASH_H
#include "Payment.h"
#include <iostream>

using namespace std;

class Cash : public Payment 
{
public:
    void performPayment() override;
};
#endif