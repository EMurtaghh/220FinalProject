//
// Person.h
//

#ifndef INC_220FINALPROJECT_PERSON_H
#define INC_220FINALPROJECT_PERSON_H

#include <string>

class Person{
private:
    std::string Name;
    int phoneNumber;
    std::string email;
    string:: contactPref;

public:
    //Constructor, Copy Constructor---------------------------------------------------------------------------------
    Person(std::string name, int num, std::string email, std::string pref);
    //Person(Person& personToCopy); Will be done when needed
    //Getter functions----------------------------------------------------------------------------------------------
    std::string getName();
    int getNumber();
    std::string getEmail();
    std::string getContactPreference();
    //Setter functions----------------------------------------------------------------------------------------------
    void setName();
    void setNumber();
    void setEmail();
    void setPreference();
    //Other functions----------------------------------------------------------------------------------------------

    //return printable version of person to display
    std::string toString();

    //return version of person in format to be saved in the text file
    std::string toSave();

};

#endif //INC_220FINALPROJECT_PERSON_H
