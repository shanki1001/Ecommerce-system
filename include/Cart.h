#ifndef CART_H_INCLUDED
#define CART_H_INCLUDED

#include "Product.h"
#include<vector>

class Cart{
private:
    std::vector<Product> items;

public:

    // Add a product to the cart
    void addProduct(const Product& product);

    //Remove a product by ID
    void removeProduct(int productId);

    //Display all items
    void viewCart() const;

    // Get total cart value
    double getTotal() const;

    // Get reference to items (if needed later)
    const std:: vector<Product>& getItems() const;
};


#endif // CART_H_INCLUDED
