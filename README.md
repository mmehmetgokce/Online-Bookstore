# Online Bookstore

This project is a C++-based console application. Its primary purpose is to simulate the product listing, shopping cart management, and payment processes of an e-commerce system.


## Features

* **Product Variety:** Product management in the Books, Magazines, and Music CDs categories.

* **Customer Management:** Registration, login, and a system to earn **1% bonus points** from every purchase.

* **Advanced Shopping Cart:** Adding/removing products, calculating the total amount, and paying with discounts using bonus points.

* **Flexible Payment Methods:** Credit card, cash, and check payment options.

* **Invoicing System:** Detailed invoice breakdown after the purchase.


## Technical Architecture

The project is built on OOP (Object-Oriented Programming) principles:

* **Abstraction & Inheritance:** The `Product` and `Payment` classes are defined as abstract base classes, and other classes are derived from them.

* **Polymorphism:** Payment processes and product attribute printing are determined dynamically at runtime.

* **File Structure:** Each class is separated into `.h` (header) and `.cpp` (source) files, in accordance with professional standards.

* **Data Structures:** STL `std::list` is used for the dynamic product list.


-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------
-------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------------


Bu proje, C++ tabanlı bir konsol uygulamasıdır. Temel amacı, bir e-ticaret sisteminin ürün listeleme, sepet yönetimi ve ödeme süreçlerini simüle etmektir.


## Özellikler

* **Ürün Çeşitliliği:** Kitap, Dergi ve Müzik CD'si kategorilerinde ürün yönetimi.

* **Müşteri Yönetimi:** Kayıt olma, giriş yapma ve her alışverişten **%1 bonus puan** kazanma sistemi.

* **Gelişmiş Sepet:** Ürün ekleme/çıkarma, toplam tutar hesaplama ve bonus puan kullanarak indirimli ödeme.

* **Esnek Ödeme Yöntemleri:** Kredi Kartı, Nakit ve Çek ile ödeme seçenekleri.

* **Fatura Sistemi:** Satın alma işlemi sonrası detaylı fatura dökümü.


## Teknik Mimari

Proje, OOP (Nesne Tabanlı Programlama) prensipleri üzerine inşa edilmiştir:

* **Soyutlama & Kalıtım:** `Product` ve `Payment` sınıfları abstract (soyut) taban sınıflar olarak tanımlanmış, diğer sınıflar bunlardan türetilmiştir.

* **Çok Biçimlilik (Polymorphism):** Ödeme işlemleri ve ürün özelliklerinin yazdırılması çalışma zamanında (runtime) dinamik olarak belirlenir.

* **Dosya Yapısı:** Her sınıf, profesyonel standartlara uygun olarak `.h` (header) ve `.cpp` (source) dosyalarına ayrılmıştır.

* **Veri Yapıları:** Dinamik ürün listesi için STL `std::list` kullanılmıştır.
