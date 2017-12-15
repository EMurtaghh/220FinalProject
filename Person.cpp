//
// Person.cpp
//
#include <iostream>
#include <string>
#include "Person.h"

//Constructor, Copy Constructor---------------------------------------------------------------------------------
Person::Person(std::string name, std::string num, std::string email, std::string pref) {
    clientName=name;
    phoneNumber=num;
    clientEmail=email;
    contactPref=pref;
}
//Copy Constructor
Person::Person(const Person& toCopy){
    clientName=toCopy.clientName;
    phoneNumber=toCopy.phoneNumber;
    clientEmail=toCopy.clientEmail;
    contactPref=toCopy.contactPref;
}

Person::Person() {
    clientName="";
    phoneNumber="";
    clientEmail="";
    contactPref="";
}
//No Destructor needed
//Getter functions----------------------------------------------------------------------------------------------
std::string Person::getName() {
    return clientName;
}

std::string Person::getNumber() {
    return phoneNumber;
}

std::string Person::getEmail() {
    return clientEmail;
}

std::string Person::getContactPreference() {
    return contactPref;
}
//Setter functions----------------------------------------------------------------------------------------------
void Person::setName(std::string newName) {
    clientName = newName;
}

void Person::setNumber(std::string num) {
    phoneNumber = num;
}

void Person::setEmail(std::string email) {
    clientEmail = email;
}

void Person::setPreference(std::string pref) {
    contactPref = pref;
}
//Other functions-----------------------------------------------------------------------------------------------

std::string Person::toString() {
    std::string myStr = clientName + " " + phoneNumber + " " + clientEmail + " " + contactPref;
    return myStr;
}

std::string Person::toSave() {
    std::string myStr = clientName + ", " + phoneNumber + ", " + clientEmail + " " + contactPref;
    return myStr;
}