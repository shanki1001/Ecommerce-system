#include<fstream>
#include<sstream>
#include<vector>
#include<algorithm>
#include "Product.h"
#include <iostream>
#include "Customer.h"
#include "Admin.h"
#include "InventoryManager.h"

using namespace std;

int getNextUserId(const string& filename){
    ifstream file(filename);
    string line ;
    int maxId = 0;

    while(getline(file,line)){
        stringstream ss(line);
        string idStr;
        getline(ss,idStr,',');
        int id = stoi(idStr);
        maxId = max(maxId, id);
    }
    return maxId +1;
}
void registerUser(const string& filename){
    string username, password, role;
    cout<<"Enter username: ";
    cin>>username;
    cout<<"Enter password: ";
    cin>>password;

    do{
        cout<<"Enter role(admin/customer): ";
        cin>>role;
        transform(role.begin(), role.end() ,role.begin(), ::tolower);
    }while(role!= "admin" && role!="customer");
    int newId = getNextUserId(filename);

    //Save to file
    ofstream file(filename, ios::app);
    if(file.is_open()){
        file << newId << "," << username << "," << password<< "," << role<< "\n";
        file.close();
        cout << "User registered successfully!\n";
    } else {
        cout << "Failed to open users file.\n";
    }
}

bool loginUser(const string& filename){
    string username, password;
    cout << "\n====== User Login =====\n";
    cout <<"Username: ";
    cin>>username;
    cout<<"Password: ";
    cin>>password;

    ifstream file(filename);
    string line;
    while(getline(file,line)){
        stringstream ss(line);
        string idStr , uname, pwd, role;
        getline(ss, idStr , ',');
        getline(ss, uname, ',');
        getline(ss, pwd, ',');
        getline(ss, role , ',');
        if(username==uname && password == pwd){
            int id = stoi(idStr);

            if(role=="customer"){
                Customer customer(id,uname,pwd,"ohio", "1231231231");
                cout<<"\n Login successful as Customer!\n";
                customer.displayInfo();

                int choice;
                do{
                    cout <<"\n === Customer Menu ===\n";
                    cout<<"1. Browse Products\n";
                    cout<<"2. Add Product to Cart\n";
                    cout<<"3. View Cart\n";
                    cout<<"4. Checkout\n";
                    cout<<"0. Exit\n";
                    cout<<"Enter choice: ";
                    cin>>choice;
                    if(choice==1){
                        customer.browseProducts();
                    } else if (choice == 2){
                        int id;
                        cout<<"Enter product ID to add: ";
                        cin>>id;
                        InventoryManager inv;
                        inv.loadFromFile("data/products.csv");
                        Product * product = inv.findProductById(id);
                        if(product) {
                            customer.addToCart(*product);
                        }
                        else {
                            cout<<"Product not found.\n";
                        }
                    } else if (choice == 3){
                        customer.viewCart();
                    } else if (choice == 4){
                        customer.checkout();
                    }
                }while(choice!=0);

            }else if (role=="admin"){
                InventoryManager inventory;
                Admin admin(id, uname, pwd , inventory);
                cout << "\n Login successful as Admin!\n";
                admin.displayInfo();
                admin.manageInventory();
                return true;
            }
        }
    }
    cout << " Invalid username or password.\n";
    return false;
}

int main()
{

    const string userFile = "data/users.csv";
    int choice;

    do{
        cout<<"\n ============Welcome to E-Commerce System======\n";
        cout << "1.Register New User\n";
        cout<< "2. Login\n";
        cout<<"0. Exit\n";
        cout<<"Enter your choice: ";
        cin>>choice;
        switch(choice){
            case 1:
                registerUser(userFile);
                break;
            case 2:
                loginUser(userFile);
                break;
            case 0:
                cout<<" Exiting program.\n";
                break;
            default:
                cout << "Invalid choice. Try again.\n";

        }
    }while(choice!=0);
   return 0;
}
