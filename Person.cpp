//
// Person.cpp
//
#include <iostream>
#include "Person.h"

//Constructor, Copy Constructor---------------------------------------------------------------------------------
Person::Person(std::string name, std::string num, std::string email, std::string pref) {
    this->Name=name;
    this->phoneNumber=num;
    this->email=email;
    this->contactPref=pref;
}
//Getter functions----------------------------------------------------------------------------------------------
std::string Person::getName() {
    return this->Name;
}

std::string Person::getNumber() {
    return this->phoneNumber;
}

std::string Person::getEmail() {
    return this->email;
}

std::string Person::getContactPreference() {
    return this->contactPref;
}
//Setter functions----------------------------------------------------------------------------------------------
void Person::setName(std::string newName) {
    this->Name = newName;
}

void Person::setNumber(std::string num) {
    this->phoneNumber = num;
}

void Person::setEmail(std::string email) {
    this->email = email;
}

void Person::setPreference(std::string pref) {
    this->contactPref = pref;
}
//Other functions-----------------------------------------------------------------------------------------------
