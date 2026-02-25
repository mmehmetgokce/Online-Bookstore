// Author: Hayri Baran Vural
// Date: 23.12.2025

// Dosya Amacý: ProductToPurchase yapýsýnýn kurucu ve getter/setter metotlarýný uygular.
// Not: Product* iþaretçisi ile ürün bilgisine, quantity ile adet bilgisine eriþilir.

#include "ProductToPurchase.h"


ProductToPurchase::ProductToPurchase(Product* product, int quantity) 

{
    this->product = product; this->quantity = quantity;
}

Product* ProductToPurchase::getProduct() const 

{
    return product; 
}
void ProductToPurchase::setProduct(Product* product) 

{
    this->product = product; 
}

int ProductToPurchase::getQuantity() const 
{ 
    return quantity;  
}

void ProductToPurchase::setQuantity(int quantity) 
{
    this->quantity = quantity; 
}