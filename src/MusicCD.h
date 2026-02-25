// Author: Muhammed Mehmet Gökçe
// Date: 21.12.2025

// Dosya Amacý: MusicCD ürün tipinin arayüzünü tanýmlar; Product sýnýfýndan türetilmiþtir.
// Not: MusicCD’ye özel "artist" alaný bulunur; detaylar MusicCD.cpp dosyasýndadýr.

#ifndef MUSICCD_H
#define MUSICCD_H
#include "Product.h"

class MusicCD : public Product 
{
private:
    string singer, type;

public:
    MusicCD(int id, string name, double price, string singer, string type);
    string getType() const;
    void setType(string type);
    string getSinger() const;
    void setSinger(string singer);
    void printProperties() const override;
};
#endif
