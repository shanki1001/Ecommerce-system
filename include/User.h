#ifndef USER_H_INCLUDED
#define USER_H_INCLUDED
#include<string>

class User{
protected:
    int id;
    std::string username;
    std::string password;
public:
    User(int id , const std::string& username , const std::string& password);

    virtual ~User();
    int getId() const;
    std::string getUsername() const;

    void setUsername(const std::string& uname);
    void setPassword(const std::string& pwd);

    bool authenticate(const std::string& pwd)const;

    virtual void displayInfo() const;
};

#endif // USER_H_INCLUDED
