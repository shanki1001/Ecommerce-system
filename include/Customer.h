#ifndef CUSTOMER_H_INCLUDED
#define CUSTOMER_H_INCLUDED
#include "User.h"
#include "Cart.h"
#include "InventoryManager.h"
#include<string>

class Customer : public User{

private :
    std::string address;
    std::string phone;
    Cart cart;

public:

    Customer(int id, const std::string& username, const std::string& password, const std::string& address, const std::string& phoneNumber);

    // Destructor
    ~Customer();

    // Getter for cart
    const Cart& getCart() const;
    Cart& getCart();

    //Getters
    std::string getAddress() const;
    std::string getPhoneNumber() const;


    //setters
    void setAddress(const std::string& addr);
    void setPhone(const std::string& phone);


    //Override display
    void displayInfo() const override;

    void browseProducts();
    void addToCart(const Product& product);
    void viewCart();
    void checkout();

};


#endif // CUSTOMER_H_INCLUDED
