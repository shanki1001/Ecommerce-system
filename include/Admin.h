#ifndef ADMIN_H_INCLUDED
#define ADMIN_H_INCLUDED
#include "User.h"
#include "InventoryManager.h"

class Admin : public User {
private:
    InventoryManager& manager;

public:
    Admin(int id, const std::string& username , const std::string& password,InventoryManager& manager);

    ~Admin();
    void displayInfo() const override;

    // Admin-specific actions
    void addProduct(const Product& product);
    void updateProduct(int id, const Product& updatedProduct);
    void deleteProduct(int id);
    void manageInventory();
    void viewAllUsers();
};

#endif // ADMIN_H_INCLUDED
