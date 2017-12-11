//
// Person.h
//

#ifndef INC_220FINALPROJECT_PERSON_H
#define INC_220FINALPROJECT_PERSON_H

#include <string>

class Person{
private:
    std::string clientName;
    std::string phoneNumber;
    std::string clientEmail;
    std::string contactPref;

public:
    //Constructor, Copy Constructor---------------------------------------------------------------------------------
    Person(std::string name, std::string num, std::string email, std::string pref);
    Person();
    //Getter functions----------------------------------------------------------------------------------------------
    std::string getName();
    std::string getNumber();
    std::string getEmail();
    std::string getContactPreference();
    //Setter functions----------------------------------------------------------------------------------------------
    void setName(std::string newName);
    void setNumber(std::string num);
    void setEmail(std::string email);
    void setPreference(std::string pref);
    //Other functions-----------------------------------------------------------------------------------------------

    //return printable version of person to display
    std::string toString();

    //return version of person in format to be saved in the text file
    std::string toSave();

    //allows user to view info and change if needed
    void edit();

};

#endif //INC_220FINALPROJECT_PERSON_H
