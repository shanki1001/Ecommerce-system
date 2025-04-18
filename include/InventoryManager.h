#ifndef INVENTORYMANAGER_H_INCLUDED
#define INVENTORYMANAGER_H_INCLUDED

#include<vector>
#include "Product.h"
#include<string>

class InventoryManager{

private:
    std::vector<Product> products;

public:

    //Load and save
    bool loadFromFile(const std::string& filename);
    bool saveToFile(const std::string& filename) const;

    //CRUD Operations
    void addProduct(const Product& product);
    void deleteProductById(int id);
    void updateProductById(int id, const Product& updatedProduct);
    void displayAllProducts() const;

    // Utility
    Product* findProductById(int id);

};



#endif // INVENTORYMANAGER_H_INCLUDED
