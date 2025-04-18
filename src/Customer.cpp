#include "Customer.h"
#include <iostream>
using namespace std;

// Constructor using initializer list, also calls base class (User) constructor

Customer::Customer(int id, const string& username, const string& password , const string&address, const string& phoneNumber):
        User(id, username, password), address(address), phone(phoneNumber){}

// Destructor
Customer:: ~Customer() {
    // If we had dynamic memory or resources to free, we'd do it here
}
//Setters
void Customer::setAddress(const string& addr){
    address=addr;
}
void Customer::setPhone(const string& phone){
    this->phone = phone;
}

//Getters
string Customer::getAddress() const{
    return address;
}
string Customer::getPhoneNumber() const{
    return this->phone;
}

// Cart access
const Cart& Customer::getCart() const{
    return cart;
}
Cart& Customer::getCart() { return cart;}

// Overridden display
void Customer::displayInfo() const {
    cout << "Customer ID: " << getId() <<endl;
    cout << "Username: "<< getUsername()<<endl;
    cout << "Address: "<< address <<endl;
    cout << "Phone: "<< this->phone<<endl;
}
void Customer::browseProducts() {
    InventoryManager inv;
    if(!inv.loadFromFile("data/products.csv")){
        cout<<" Failed to load product data.\n";
       return;
    }
    inv.displayAllProducts();
}
void Customer::addToCart(const Product& product){
    cart.addProduct(product);
    cout<<" Product added to cart.\n";
}
void Customer::viewCart() {
    cout << "\n Your Cart:\n";
    cart.viewCart();
}
void Customer::checkout() {
    cout << "\n Checking out...\n";
    cart.viewCart();
//    cart.clearCart();
    cout<< " Checkout complete! Cart is now empty.\n";

}



