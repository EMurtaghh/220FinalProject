//
// Book.h
//

#ifndef INC_220FINALPROJECT_BOOK_H
#define INC_220FINALPROJECT_BOOK_H

#include <string>
#include "Queue.h"
#include "Person.h"

class Book{
private:
    std::string bookTitle;
    std::string bookAuthor;
    double bookPrice;
    int haveCount;
    int wantCount;
    Queue<Person>* waitList;

public:
    //Constructor, Copy Constructor---------------------------------------------------------------------------------
    Book(std::string bookTitle, std::string bookAuthor, double bookPrice, int haveCount, int wantCount);
    ~Book();
    Book(const Book& bookToCopy);
    //Getter functions----------------------------------------------------------------------------------------------
    std::string getAuthor();
    std::string getTitle();
    int getHaveCount();
    int getWantCount();
    double getPrice();
    Queue<Person>* getWaitList();
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
    void addToWaitList(Person toAdd);

    //adds amountToAdd books to the have value and sells to the customers in the waitlist if there are any
    //@return the new haveCount for the book
    int stock(int amountToAdd);

    //returns a printable version of the book with all info that should be shown when the book is listed
    std::string toString();




};
#endif //INC_220FINALPROJECT_BOOK_H