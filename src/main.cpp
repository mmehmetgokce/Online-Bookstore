// Author: Zeynep Kurt
// Date: 27.12.2025

// Dosya Amacý: Programýn giriþ noktasýdýr; menü tabanlý akýþla müþteri/ürün/sepet/ödeme iþlemlerini yönetir.
// Not: Sýnýflarý bir araya getirerek uygulamanýn senaryosunu çalýþtýrýr (kayýt, giriþ, sepet, ödeme).

#include <iostream>
#include <vector>
#include <string>

#include "Customer.h" // Customer sýnýfý
#include "Product.h" // Product taban sýnýfý
#include "Book.h" // Book ürün tipi
#include "Magazine.h" // Magazine ürün tipi
#include "MusicCD.h" // MusicCD ürün tipi
#include "ShoppingCart.h" // Alýþveriþ Sepeti
#include "Payment.h" // Payment taban sýnýfý
#include "CreditCard.h" // CreditCard ödeme türü
#include "Cash.h" // Cash ödeme türü
#include "Check.h" // Check ödeme türü

using namespace std;

vector<Customer*> dbCustomers;
vector<Product*> dbProducts;

Customer* currentSession = nullptr;


template <typename T, typename Pred>
T* findFirst(const vector<T*>& items, Pred predicate) {
    for (T* item : items) {
        if (predicate(item)) return item;
    }
    return nullptr;
}

void seedData() {
    cout << "Loading system data...\n";

    // Min: 5 müþteri
    dbCustomers.push_back(new Customer(1, "Ali Yilmaz", "ali123", "pass1", "ali@mail.com"));
    dbCustomers.push_back(new Customer(2, "Ayse Demir", "ayse", "1234", "ayse@mail.com"));
    dbCustomers.push_back(new Customer(3, "Mehmet Kaya", "mehmet", "0000", "mehmet@mail.com"));
    dbCustomers.push_back(new Customer(4, "Elif Sahin", "elif", "1111", "elif@mail.com"));
    dbCustomers.push_back(new Customer(5, "Can Aydin", "can", "2222", "can@mail.com"));

    // Min: en az 3 item
    // kitap
    dbProducts.push_back(new Book(101, "Sefiller", 350.0, "Victor Hugo", "Is Bankasi", 1500));
    dbProducts.push_back(new Book(102, "Kurk Mantolu Madonna", 220.0, "Sabahattin Ali", "Yapi Kredi", 160));
    dbProducts.push_back(new Book(103, "Tutunamayanlar", 450.0, "Oguz Atay", "Iletisim", 724));

    // Magazin
    dbProducts.push_back(new Magazine(201, "Bilim Teknik", 50.0, 202401, "Science"));
    dbProducts.push_back(new Magazine(202, "National Geographic", 90.0, 202402, "Geography"));
    dbProducts.push_back(new Magazine(203, "Level", 75.0, 202403, "Gaming"));

    // MuzikCD
    dbProducts.push_back(new MusicCD(301, "Karma", 150.0, "Tarkan", "Pop"));
    dbProducts.push_back(new MusicCD(302, "Bir Derdim Var", 120.0, "Mor ve Otesi", "Rock"));
    dbProducts.push_back(new MusicCD(303, "Senfonik", 180.0, "Cem Adrian", "Alternative"));
}

Product* findProductByID(int id) 
{
    return findFirst<Product>(dbProducts, [id](Product* p) { return p->getID() == id; });
}

void showShoppingMenu() 
{
    string kim = (currentSession) ? currentSession->getName() : "Guest";

    cout << "\n========================================\n";
    cout << "    Shopping Menu (" << kim << ")\n";
    cout << "========================================\n";
    cout << "1. Login \n";
    cout << "2. Logout \n";
    cout << "----------------------------------------\n";
    cout << "3. Add Product\n";
    cout << "4. Remove Product\n";
    cout << "5. List Shopping Cart\n";
    cout << "6. Show Bonus\n";
    cout << "7. Use Bonus\n";
    cout << "8. Place Order\n";
    cout << "9. Cancel Order\n";
    cout << "10. Show Invoice\n";
    cout << "11. Back to Main Menu\n";
    cout << "Choose: ";
}

void showMainMenu() 
{
    cout << "\n--- Main Menu ---\n";
    cout << "1. Customer Menu\n";
    cout << "2. Show Products\n";
    cout << "3. Shopping Menu\n";
    cout << "4. Exit\n";
    cout << "Choose: ";
}

void showCustomerMenu() 
{
    cout << "\n--- Customer Menu ---\n";
    cout << "1. Add New Customer\n";
    cout << "2. List Customers\n";
    cout << "3. Back\n";
    cout << "Choose: ";
}

int main() 
{
    seedData();
    int choice;

    while (true) 
    {
        showMainMenu();
        if (!(cin >> choice)) 
        {
            cin.clear();
            cin.ignore(1000, '\n');
            continue;
        }

        if (choice == 1) 
        {
            int custChoice;
            showCustomerMenu();
            cin >> custChoice;

            if (custChoice == 1) 
            {
                string n, u, p, e;
                cout << "Name: "; cin.ignore(); getline(cin, n);
                cout << "Username: "; cin >> u;
                cout << "Password: "; cin >> p;
                cout << "E-mail: "; cin >> e;

                long newID = (long)(dbCustomers.size() + 1ULL);
                dbCustomers.push_back(new Customer(newID, n, u, p, e));
                cout << "Customer added successfully!\n";
            }
            else if (custChoice == 2) 
            
            {
                cout << "\n--- Customer List ---\n";
                for (auto c : dbCustomers) 
                {
                    cout << "ID: " << c->getCustomerID() << " - " << c->getName()
                        << " (" << c->getEmail() << ")\n";
                }
            }
        }
        else if (choice == 2) 
        {
            cout << "\n--- Product List ---\n";
            for (auto p : dbProducts) { p->printProperties(); cout << "---\n"; }
        }
        else if (choice == 3) 
        {
            int shopChoice;
            bool back = false;

            while (!back) 
            {
                showShoppingMenu();
                cin >> shopChoice;

                if (!currentSession && shopChoice >= 3 && shopChoice <= 10) {
                    cout << "Login first!\n";
                    continue;
                }

                try {
                    switch (shopChoice) 
                    {
                    case 1: 
                    {
                        if (currentSession) 
                        { cout << "Already logged in\n"; break; }
                        string u, p;
                        cout << "Username: "; cin >> u;
                        cout << "Password: "; cin >> p;

                        Customer* match = findFirst<Customer>(dbCustomers, [&](Customer* c) 
                            {
                            return c->checkAccount(u, p);
                            });

                        if (!match) throw AuthenticationException("Wrong username or password.");

                        currentSession = match;
                        currentSession->getCart()->setCustomer(currentSession);
                        cout << "Login success!\n";
                        break;
                    }
                    case 2: 
                    {
                        if (currentSession) 
                        {
                            cout << "\nBye bye " << currentSession->getName() << ". Logged out.\n";
                            currentSession = nullptr;
                        }
                        else 
                        {
                            cout << "Already not logged in\n";
                        }
                        break;
                    }
                    case 3: 
                    {
                        int pid, qty;
                        cout << "Product ID: "; cin >> pid;
                        cout << "Quantity: "; cin >> qty;

                        Product* prod = findProductByID(pid);
                        if (!prod) { cout << "No product!\n"; break; }

                        currentSession->getCart()->addProduct(prod, qty);
                        break;
                    }
                    case 4: 
                    {
                        int pid; cout << "To delete ID: "; cin >> pid;
                        Product* prod = findProductByID(pid);
                        if (!prod) { cout << "No product!\n"; break; }

                        currentSession->getCart()->removeProduct(prod);
                        break;
                    }
                    case 5:
                        currentSession->getCart()->printProducts();
                        break;
                    case 6:
                        cout << "Bonus: " << currentSession->getBonus() << "\n";
                        break;
                    case 7:
                        currentSession->getCart()->setBonusUsed(true);
                        cout << "Bonus activated.\n";
                        break;
                    case 8: 
                    {
                        cout << "Select Payment: 1. Credit Card / 2. Cash / 3. Check: ";
                        int m; cin >> m;

                        Payment* pay = nullptr;

                        if (m == 1) pay = new CreditCard(111, "Visa", "12/26");
                        else if (m == 2) pay = new Cash();
                        else if (m == 3) {
                            string name, bankID;
                            cout << "Name: "; cin >> name;
                            cout << "Bank ID: "; cin >> bankID;
                            pay = new Check(name, bankID);
                        }
                        else {
                            cout << "Invalid Payment Method!\n";
                            break;
                        }

                        currentSession->getCart()->setPaymentMethod(pay);
                        currentSession->getCart()->placeOrder();
                        break;
                    }
                    case 9:
                        currentSession->getCart()->cancelOrder();
                        break;
                    case 10:
                        currentSession->getCart()->showInvoice();
                        break;
                    case 11:
                        back = true;
                        break;
                    default:
                        cout << "Invalid button!\n";
                    }
                }
                catch (const exception& ex) 
                {
                    cout << "ERROR: " << ex.what() << "\n";
                }
            }
        }
        else if (choice == 4) 
        {
            break;
        }
    }

    for (auto c : dbCustomers) delete c;
    for (auto p : dbProducts) delete p;

    return 0;
}
