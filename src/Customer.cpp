// Author: Sena Ülkü
// Date: 23.12.2025
// Author: Zeynep Kurt
// Date: 27.12.2025

// Dosya Amacý: Customer sýnýfýnýn kurucu ve getter/setter metotlarýný uygular.
// Not: Adres (address) alaný da müþteri verisi olarak saklanýr ve gerektiðinde okunur.

#include "Customer.h"
#include "ShoppingCart.h"

Customer::Customer(long id, string n, string user, string pass, string mail) 
{
    this->customerID = id;
    this->name = n;
    this->username = user;
    this->password = pass;
    this->email = mail;
    this->bonus = 0.0;

    this->myCart = new ShoppingCart();
    this->myCart->setCustomer(this);
}

Customer::~Customer() 
{
    if (myCart) {
        delete myCart;
        myCart = nullptr;
    }
}

string Customer::getUsername() const 
{
    return username; 
}
string Customer::getPassword() const 
{
    return password; 
}
string Customer::getName() const 
{
    return name; 
}
string Customer::getEmail() const 
{
    return email; 
}

long Customer::getCustomerID() const 
{
    return customerID; 
}
double Customer::getBonus() const 
{
    return bonus; 
}

void Customer::addBonus(double amount) 
{
    bonus += (amount * 0.01); 
}
void Customer::useBonus() 
{
    bonus = 0.0; 
}

bool Customer::checkAccount(string user, string pass) 
{
    return (username == user && password == pass);
}

ShoppingCart* Customer::getCart() 
{
    return myCart;
}
