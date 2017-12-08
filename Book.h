//
// Book.h
//

#ifndef INC_220FINALPROJECT_BOOK_H
#define INC_220FINALPROJECT_BOOK_H

#include <string>
#include <w32api/cdoex.h>
#include "Queue.h"
#include "Person.h"

class Book{
private:
    std::string bookTitle;
    std::string bookAuthor;
    double bookPrice;
    int haveCount;
    int wantCount;
    Queue* waitList;

public:
    //Constructor, Copy Constructor----------------------------------------------------------------------------------------------
    Book(std::string bookTitle, std::string bookAuthor, double bookPrice, int haveCount, int wantCount);
    //Book(Book& bookToCopy); Will be done when needed
    //Getter functions----------------------------------------------------------------------------------------------
    std::string getAuthor();
    std::string getTitle();
    int getHaveCount();
    int getWantCount();
    double getPrice();
    //Setter functions----------------------------------------------------------------------------------------------
    void setAuthor(std::string author);
    void setTitle(std::string title);
    void setHaveCount(int newCount);
    void setWantCount(int newCount);
    void setPrice(double newPrice);
    //Other functions----------------------------------------------------------------------------------------------

    //sells one(removes one from haveCount or prompts to add to waitlist-----will be another function called by main if sell returns 0)
    //returns 1 if sold and 0 if out of stock
    int sell();

    //adds new person to the waitList-- just needs to call the function from Queue
    void addToWaitList(Person* toAdd);//person is red because the class is not defined yet i think

    //adds amountToAdd books to the have value and sells to the customers in the waitlist if there are any
    //@return the new haveCount for the book
    int stock(int amountToAdd);

    //returns a printable version of the book with all info that should be shown when the book is listed
    std::string toString();

    //returns a printable version of the book in the format of how the book should be saved to the text file
    std::string toSave();



};
#endif //INC_220FINALPROJECT_BOOK_H