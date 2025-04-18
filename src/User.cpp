#include "User.h"
#include<iostream>
using namespace std;

User::User(int id, const string& username , const string& password )
    : id(id) , username(username) , password(password){}

User::~User(){

}
int User::getId()const{
    return id;
}
string User::getUsername() const {
    return username;
}
void User::setUsername(const string& uname){
    username = uname;
}
void User::setPassword( const string& pwd){
    password = pwd;
}
bool User::authenticate(const string& pwd) const{
    return password == pwd;
}
void User::displayInfo() const{
    cout<< "User ID:" << id<<endl;
    cout<<"Username:"<<username<<endl;
}
