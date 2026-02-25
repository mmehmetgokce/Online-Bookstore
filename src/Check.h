// Author: Yusuf Göç
// Date: 22.12.2025

// Dosya Amacý: Check (Çek) ödeme türünü ve bankaya ait ek bilgileri tanýmlar.
// Not: Payment taban sýnýfýna ek olarak bankName ve checkNumber alanlarý bulunur.

#ifndef CHECK_H
#define CHECK_H

#include "Payment.h" // Base class
#include <string>
#include <iostream>

using namespace std;

class Check : public Payment 
{
private:
    string name;
    string bankID;

public:
    Check(string name, string bankID);

    void performPayment() override; 
    string getName();
    void setName(string name);
    string getBankID();
    void setBankID(string bankID);
};

#endif
