// Author: Sena Ülkü
// Date: 23.12.2025

// Dosya Amacý: Customer (Müþteri) modelini tanýmlar; giriþ bilgileri ve adres bilgisini tutar.
// Not: Getter/Setter yapýsýyla alanlara kontrollü eriþim saðlanýr.

#ifndef CUSTOMER_H
#define CUSTOMER_H

#include <string>
#include <iostream>

class ShoppingCart;

using namespace std;

class Customer 
{
private:
    long customerID;
    string name;
    string username;
    string password;
    string email;
    double bonus;
    ShoppingCart* myCart;

public:
    Customer(long id, string n, string user, string pass, string mail);
    ~Customer();
    string getUsername() const;
    string getPassword() const;
    string getName() const;
    string getEmail() const;

    long getCustomerID() const;
    double getBonus() const;
    void addBonus(double amount);
    void useBonus();
    bool checkAccount(string user, string pass);

    ShoppingCart* getCart();
};

#endif
