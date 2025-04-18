#ifndef PRODUCT_H_INCLUDED
#define PRODUCT_H_INCLUDED

#include<string>

class Product{

private:
    int id;
    std:: string name;
    std::string category;
    double price;
    int quantity;
public:
    Product(int id = 0 , std::string name = "",std::string category="", double price = 0.0, int quantity = 0);

    int getId() const;
    std::string getName() const;
    std::string getCategory() const;
    double getPrice() const;
    int getQuantity() const;

    void setName(const std::string& newName);
    void setCategory(const std::string& newCategory);
    void setPrice(double newPrice);
    void setQuantity(int newQuantity);

    void display() const;

};



#endif
