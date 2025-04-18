#include "Admin.h"
#include<iostream>

using namespace std;

Admin::Admin(int id, const string& username, const string& password , InventoryManager& manager):
        User(id, username , password), manager(manager){}

void Admin::displayInfo() const{
    cout<< "Admin ID: " << getId() << endl;
    cout << "Username: " << getUsername() <<endl;
    cout<< "Role: Administrator" << endl;
}

//Destructor
Admin::~Admin() {
    //Nothing special needed here
}

void Admin::addProduct(const Product& product) {
    manager.addProduct(product);
}
void Admin::updateProduct(int id, const Product& updatedProduct){
    manager.updateProductById(id,updatedProduct);
}
void Admin::deleteProduct(int id){
    manager.deleteProductById(id);
}

void Admin :: manageInventory() {

    int choice;
    do{
        cout<<"\n===== Inventory Management Menu =====\n";
        cout<<"1. View all products\n";
        cout<<"2. Add product\n";
        cout<<"3. Delete product by ID\n";
        cout<<"4. Update product by ID\n";
        cout<<"0. Exit\n";
        cout<<"Enter you choice: ";
        cin>>choice;
        if(choice == 1){
            manager.displayAllProducts();
        }else if (choice == 2 ){
        int id, qty;
        double price;
        string name, category;
        cout <<"Enter ID: "; cin>>id;cin.ignore();
        cout <<"Enter Name: ";getline(cin,name);
        cout <<"Enter Category: "; getline(cin,category);
        cout <<"Enter price: ";cin>>price;
        cout <<"Enter Quantity: ";cin>>qty;

        Product newProduct (id, name ,category, price , qty);
        manager.addProduct(newProduct);
        } else if (choice == 3){
            int id;
            cout<<"Enter Product ID to delete: ";
            cin>>id;
            manager.deleteProductById(id);
        } else if (choice == 4) {
            int id, qty;
            double price;
            string name, category;
            cout<< "Enter ID to update: ";cin>>id;
            cout<< "Enter new Name: "; cin.ignore(); getline(cin,name);
            cout<<"Enter new category: "; getline(cin, category);
            cout<<"Enter new Price: "; cin>>price;
            cout<<"Enter new Quantity: ";cin>>qty;

            Product updatedProduct(id, name ,category,price ,qty);
            manager.updateProductById(id, updatedProduct);
        }
    }  while(choice !=0);
    cout << "Inventory changes saved.\n";
}
void Admin::viewAllUsers() {
    cout << "[Admin Action] Viewing all users...(Features to be implemented)" << endl;
}
