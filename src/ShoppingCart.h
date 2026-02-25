// Author: Hayri Baran Vural
// Date: 23.12.2025


// Dosya Amacý: ShoppingCart sýnýfýný tanýmlar; sepete ekleme/silme/güncelleme ve toplam hesaplama içerir.
// Not: Invoice çýktýsý için müþteri bilgisi (Customer) ile birlikte çalýþýr.

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

#include <vector>
#include <iostream>
#include <string>
#include <stdexcept>
#include "Payment.h"
#include "ProductToPurchase.h"
#include "Customer.h"

using namespace std;

class AuthenticationException : public runtime_error 
{

public:
    explicit AuthenticationException(const string& msg)
        : runtime_error("Authentication error: " + msg) 
    {
    }
};

class CartEmptyException : public runtime_error 
{
public:
    CartEmptyException() : runtime_error("Cart is empty.") {}
};

class PaymentNotSelectedException : public runtime_error 
{
public:
    PaymentNotSelectedException() : runtime_error("Payment method not selected.") {}
};

class ItemNotFoundException : public runtime_error 
{
public:
    explicit ItemNotFoundException(const string& msg)
        : runtime_error("Item not found: " + msg) 
    {
    }
};

class ShoppingCart 
{

private:
    vector<ProductToPurchase*> productsToPurchase;
    Customer* customer;
    Payment* paymentMethod;
    bool isBonusUsed;

public:
    ShoppingCart();
    ~ShoppingCart();

    void setCustomer(Customer* c);
    void addProduct(Product* p, int qty);
    void removeProduct(Product* p);
    void printProducts();
    void setBonusUsed(bool use);
    void setPaymentMethod(Payment* p);
    void placeOrder();
    void cancelOrder();
    void showInvoice();
};

#endif
