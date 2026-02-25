// Author: Yusuf Göç
// Date: 22.12.2025

// Dosya Amacý: CreditCard ödeme türünün davranýþlarýný uygular.
// Not: Ödeme tutarýyla birlikte kart bilgileri displayPaymentInfo() içinde gösterilir.

#include "CreditCard.h"

CreditCard::CreditCard(long num, string t, string date) 
{
    this->number = num;
    this->type = t;
    this->expDate = date;
}

void CreditCard::performPayment() 
{
    cout << "----------------------------------------" << endl;
    cout << "Processing Credit Card Payment..." << endl;
    cout << "Card Type   : " << type << endl;
    cout << "Card Number : " << number << endl;
    cout << "Exp Date    : " << expDate << endl;

    cout << "Paid Amount : " << getAmount() << " TL" << endl;
    cout << "----------------------------------------" << endl;
}

long CreditCard::getNumber() 
{ 
    return number; 
}

void CreditCard::setNumber(long num) 
{ 
    this->number = num; 
}

string CreditCard::getType() 
{
    return type; 
}
void CreditCard::setType(string t) 
{
    this->type = t; 
}

string CreditCard::getExpDate() 
{
    return expDate; 
}
void CreditCard::setExpDate(string date) 
{
    this->expDate = date; 
}