// Author: Yusuf Göç
// Date: 22.12.2025

// Dosya Amacý: Payment taban sýnýfýnýn kurucu ve varsayýlan davranýþýný uygular.
// Not: Alt sýnýflar isterse displayPaymentInfo() fonksiyonunu kendi ihtiyaçlarýna göre ezebilir.

#include "Payment.h"

Payment::Payment() {
    amount = 0.0;
}

Payment::~Payment() 
{
}

double Payment::getAmount() 
{
    return amount;
}

void Payment::setAmount(double amount) 
{
    this->amount = amount;
}
