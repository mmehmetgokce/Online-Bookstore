// Author: Yusuf Göç
// Date: 22.12.2025

// Dosya Amacý: Tüm ödeme türleri için ortak Payment taban sýnýfýný tanýmlar.
// Not: displayPaymentInfo() sanal (virtual) metottur; alt sýnýflar bunu override edebilir.

#ifndef PAYMENT_H
#define PAYMENT_H

class Payment 
{

private:
    double amount; 

public:
    Payment();
    virtual ~Payment(); 
    double getAmount();
    void setAmount(double amount);
    virtual void performPayment() = 0;
};

#endif
