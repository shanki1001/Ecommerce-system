#include "Cart.h"
#include <iostream>
using namespace std;

// Add a product to the Cart
void Cart::addProduct(const Product& product){
    items.push_back(product);
    cout<< "Product added to cart successfully."<<endl;
}

//Remove a product by ID

void Cart::removeProduct(int productId){
    for(auto it = items.begin() ; it!= items.end() ; ++it){
        if(it->getId() == productId){
            items.erase(it);
            cout<< "Product removed from cart."<<endl;
            return;
        }
    }
    cout<<"Product not found in cart."<<endl;
}

//Display all items in the Cart
void Cart::viewCart() const{
    if(items.empty()){
        cout<< "Cart is empty."<<endl;
        return;
    }
    cout << "Items in Cart:" << endl;
    for(const auto& product : items) {
        product.display();
        cout << "-----------------------" << endl;
    }
}

// Calculate total value of cart
double Cart::getTotal() const{
    double total=0.0;
    for(const auto& product : items) {
        total+= product.getPrice() * product.getQuantity();
    }
    return total;
}

// Return read-only access to cart items
const vector<Product>& Cart::getItems() const {
    return items;
}
