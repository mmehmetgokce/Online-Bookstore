// Author: Yusuf Göç
// Date: 22.12.2025

// Dosya Amacý: Cash ödeme türünün davranýþlarýný uygular.
// Not: displayPaymentInfo() ile ödeme detayý ekrana yazdýrýlýr.

#include "Cash.h"

void Cash::performPayment() 
{
    cout << "----------------------------------------" << endl;
    cout << "Processing Cash Payment..." << endl;

    cout << "Cash Received: " << getAmount() << " TL" << endl;

    cout << "Transaction Complete." << endl;
    cout << "----------------------------------------" << endl;
}