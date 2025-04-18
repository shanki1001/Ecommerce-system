#include "Product.h"
#include<iostream>

using namespace std;

Product::Product(int id , string name, string category , double price, int quantity )
    :id(id) , name(name),category(category),price(price), quantity(quantity) {

}

int Product::getId() const{
    return id;
}
string Product :: getName() const{
    return name;
}
string Product:: getCategory() const{
return category;
}
double Product:: getPrice() const{
    return price;
}
int Product::getQuantity() const{
    return quantity;
}
void Product::setName(const string& newName){
    name = newName;
}
void Product::setCategory(const string& newCategory){
    category= newCategory;
}
void Product::setPrice(double newPrice){
    price = newPrice;
}
void Product::setQuantity(int newQuantity){
    quantity=newQuantity;
}

void Product::display() const{
    cout<<"Product Id: "<<id<<endl;
    cout<<"Name      : "<<name<<endl;
    cout<<"Category  : "<<category<<endl;
    cout<<"Price     : $"<<price<<endl;
    cout<<"Quantity  : "<<quantity<<endl;
}





