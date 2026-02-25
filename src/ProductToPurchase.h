// Author: Hayri Baran Vural
// Date: 23.12.2025

// Dosya Amacý: Sepette/invoice’da kullanýlacak “satýn alýnan ürün + adet” yapýsýný tanýmlar.
// Not: Katalogdaki Product ile, sepetteki “quantity” bilgisini ayrý bir yapýda birleþtirir.


#ifndef PRODUCTTOPURCHASE_H
#define PRODUCTTOPURCHASE_H

#include "Product.h"

class ProductToPurchase 
{
private:
    Product* product;
     int quantity;

public:
    ProductToPurchase(Product* product, int quantity);
    Product* getProduct() const;
    void setProduct(Product* product);
    int getQuantity() const;
    void setQuantity(int quantity);
};
#endif
