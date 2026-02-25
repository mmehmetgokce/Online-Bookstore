// Author: Hayri Baran Vural
// Date: 23.12.2025
// Author: Zeynep Kurt
// Date: 27.12.2025

// Dosya Amacý: ShoppingCart fonksiyonlarýný uygular.
// Not: Invoice kýsmýnda müþteri adý/e-posta/adres bilgileri de gösterilir.

#include "ShoppingCart.h"

ShoppingCart::ShoppingCart() : customer(nullptr), paymentMethod(nullptr), isBonusUsed(false) {}

ShoppingCart::~ShoppingCart() 
{
    if (paymentMethod) 
    {
        delete paymentMethod;
        paymentMethod = nullptr;
    }
    for (auto item : productsToPurchase) 
    {
        delete item;
    }
    productsToPurchase.clear();
}

void ShoppingCart::setCustomer(Customer* c) 
{ customer = c; }
void ShoppingCart::setBonusUsed(bool use) 
{ isBonusUsed = use; }

void ShoppingCart::setPaymentMethod(Payment* p) 
{
    if (paymentMethod && paymentMethod != p) 
    {
        delete paymentMethod;
    }
    paymentMethod = p;
}

void ShoppingCart::addProduct(Product* p, int qty) 
{
    productsToPurchase.push_back(new ProductToPurchase(p, qty));
    cout << ">> Added to cart: " << p->getName() << " x" << qty << endl;
}

void ShoppingCart::removeProduct(Product* p) 
{
    for (auto it = productsToPurchase.begin(); it != productsToPurchase.end(); ) 
    {
        if ((*it)->getProduct()->getID() == p->getID()) 
        {
            delete* it;
            it = productsToPurchase.erase(it);
            cout << ">> Deleted from cart.\n";
            return;
        }
        else 
        {
            ++it;
        }
    }
    throw ItemNotFoundException("Product is not in cart.");
}

void ShoppingCart::printProducts() 
{
    if (productsToPurchase.empty()) 
    {
        cout << "Cart is empty.\n";
        return;
    }
    cout << "\n--- YOUR CART ---\n";
    for (auto item : productsToPurchase) 
    {
        cout << item->getProduct()->getName()
            << " (" << item->getQuantity() << " Quantity) - "
            << item->getProduct()->getPrice() * item->getQuantity()
            << " TL" << endl;
    }
    cout << "-----------------\n";
}

void ShoppingCart::placeOrder() 
{
    if (productsToPurchase.empty()) throw CartEmptyException();
    if (!paymentMethod) throw PaymentNotSelectedException();

    double total = 0;
    for (auto item : productsToPurchase) 
    {
        total += item->getProduct()->getPrice() * item->getQuantity();
    }

    double finalAmount = total;
    double bonusDiscount = 0;

    cout << "\n-- INVOICE ---\n";

    if (isBonusUsed && customer) 
    {
        double bonus = customer->getBonus();
       
        if (bonus >= total) 
        {
            bonusDiscount = total;
            finalAmount = 0;
        }
        
        else 
        {
            bonusDiscount = bonus;
            finalAmount = total - bonus;
        }

        cout << "Original Price: " << total << " TL\n";
        cout << "Bonus Discount: " << bonusDiscount << " TL\n";
        cout << "Net Total:      " << finalAmount << " TL\n";
        customer->useBonus();
    }
    else 
    {
        cout << "Net Total: " << finalAmount << " TL\n";
    }

    paymentMethod->setAmount(finalAmount);
    paymentMethod->performPayment();

    // PDF: invoice email simülasyonu (console)
    if (customer) {
        cout << "[EMAIL] Invoice sent to: " << customer->getEmail() << "\n";
        customer->addBonus(finalAmount);
    }

    for (auto item : productsToPurchase) delete item;
    productsToPurchase.clear();

    isBonusUsed = false;

    delete paymentMethod;
    paymentMethod = nullptr;
}

void ShoppingCart::cancelOrder() 
{
    if (productsToPurchase.empty()) throw CartEmptyException();

    for (auto item : productsToPurchase) delete item;
    productsToPurchase.clear();

    isBonusUsed = false;

    if (paymentMethod) 
    {
        delete paymentMethod;
        paymentMethod = nullptr;
    }

    cout << "Order cancelled.\n";
}

void ShoppingCart::showInvoice() 
{
    cout << "\nBill Preview\n";
    cout << "Guest: " << (customer ? customer->getName() : "Guest") << endl;
    printProducts();
    cout << "*****************************\n";
}
