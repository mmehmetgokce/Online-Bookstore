// Author: Yusuf Göç
// Date: 22.12.2025

// Dosya Amacý: Check ödeme türünün kurucu ve bilgi yazdýrma kýsmýný uygular.
// Not: Kurucuda initialization list kullanýlarak base class ve ek alanlar set edilir.

#include "Check.h"

Check::Check(string n, string id) 
{
    this->name = n;
    this->bankID = id;
}

void Check::performPayment() 
{
    cout << "----------------------------------------" << endl;
    cout << "Processing Check Payment..." << endl;
    cout << "Check Owner : " << name << endl;
    cout << "Bank ID     : " << bankID << endl;
    cout << "Paid Amount : " << getAmount() << " TL" << endl;
    cout << "----------------------------------------" << endl;
}


string Check::getName() 
{
    return name;
}

void Check::setName(string n) 
{
    this->name = n;
}

string Check::getBankID() 
{
    return bankID;
}

void Check::setBankID(string id) 
{
    this->bankID = id;
}
