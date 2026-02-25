// Author: Muhammed Mehmet Gökçe
// Date: 21.12.2025

// Dosya Amacý: MusicCD sýnýfýnýn metotlarýný (kurucu, getter/setter, display) uygular.
// Not: artist alaný ile ürün bilgisi ekrana yazdýrma özelleþtirilir.

#include "MusicCD.h"

MusicCD::MusicCD(int id, string name, double price, string singer, string type)  :  Product(id, name, price), singer(singer), type(type) {}

string MusicCD::getSinger() const 
{
    return singer; 
}
void MusicCD::setSinger(string singer) 
{ 
    this->singer = singer; 
}
string MusicCD::getType() const 
{
    return type; 
}
void MusicCD::setType(string type) 
{
    this->type = type; 
}
void MusicCD::printProperties() const 
{
    cout << "MusicCD - ID: " << id << ", Name: " << name << ", Price: " << price << endl;
    cout << "Singer: " << singer << ", Type: " << type << endl;
}
