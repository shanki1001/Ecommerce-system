#include "InventoryManager.h"
#include <fstream>
#include <sstream>
#include <iostream>

using namespace std;

bool InventoryManager::loadFromFile(const string& filename){
    products.clear();
    ifstream file(filename);
    if(!file.is_open()){
        cerr<< " Failed to open " << filename<<endl;
        return false;
    }
    string line;
    while(getline(file,line)){
        stringstream ss(line);
        string idStr , name, category, priceStr , quantityStr;
        getline(ss, idStr, ',');
        getline(ss, name, ',');
        getline(ss, category, ',');
        getline(ss, priceStr, ',');
        getline(ss, quantityStr, ',');

        int id = stoi(idStr);
        double price = stod(priceStr);
        int quantity = stoi(quantityStr);

        products.emplace_back(id , name, category, price , quantity);
    }
    file.close();
    return true;
}
bool InventoryManager:: saveToFile(const string&filename) const{
    ofstream file(filename);
    if(!file.is_open()){
        cerr<<" Failed to write to "<< filename<< endl;
        return false;
    }
    for(const auto& p: products){
        file<<p.getId()<<","
            <<p.getName()<<","
            <<p.getCategory()<<","
            <<p.getPrice()<<","
            <<p.getQuantity()<<"\n";
    }
    file.close();
    true;
}
// Add new product
void InventoryManager::addProduct(const Product& product){
    products.push_back(product);
    cout<<" Product added successfully.\n";
}

// Remove product by ID
void InventoryManager::deleteProductById(int id){
    auto it = products.begin();
    while(it != products.end()){
        if(it->getId()==id){
            it = products.erase(it);
            cout<< " Product removed successfully.\n";
            return;
        } else {
            ++it;
        }
    }
    cout<<" Product not found.\n";
}

// Update product by ID
void InventoryManager::updateProductById(int id, const Product& updatedProduct){
    for(auto& p : products) {
        if (p.getId() == id){
            p=updatedProduct;
            cout<< " Product updated successfully.\n";
            return;
        }
    }
    cout<< " Product not found.\n";
}
// Display all products
void InventoryManager::displayAllProducts() const{
    cout<< "\n All products:\n";
    for(const auto& p: products){
        p.display();
        cout << "--------------------\n";
    }
}

// Find product by ID
Product* InventoryManager::findProductById(int id){
    for(auto& p: products){
        if(p.getId()==id){
            return &p;
        }
    }
    return nullptr;
}
