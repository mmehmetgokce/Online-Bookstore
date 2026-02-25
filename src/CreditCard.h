// Author: Yusuf Göç
// Date: 22.12.2025

// Dosya Amacý: CreditCard (Kredi Kartý) ödeme türünü Payment sýnýfýndan türeterek tanýmlar.
// Not: Kart numarasý ve kart sahibi gibi ek alanlar içerir ve bilgi yazdýrma override edilir.

#ifndef CREDITCARD_H
#define CREDITCARD_H

#include "Payment.h" 
#include <string>
#include <iostream>

using namespace std;

class CreditCard : public Payment 
{
private:
    long number;
    string type;
    string expDate;

public:
    CreditCard(long num, string type, string expDate);
    void performPayment() override;
    long getNumber();
    void setNumber(long number);
    string getType();
    void setType(string type);
    string getExpDate();
    void setExpDate(string expDate);
};

#endif