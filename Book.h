//
// Book.h
//

#ifndef INC_220FINALPROJECT_BOOK_H
#define INC_220FINALPROJECT_BOOK_H

#include <string>
#include "Queue.h"

class Book{
private:
    std::string bookTitle;
    std::string bookAuthor;
    double bookPrice;
    int haveCount;
    int wantCount;
    Queue* waitList;

public:
    //Constructor, Copy Constructor
    Book(std::string bookTitle, std::string bookAuthor, double bookPrice, int haveCount, int wantCount);
    //Book(Book& bookToCopy); Will be done when needed
    //Getter functions
    std::string getAuthor();
    std::string getTitle();
    int getHaveCount();
    int getWantCount();
    double getPrice();
    //Setter functions
    void setAuthor(std::string author);
    void setTitle(std::string title);
    void setHaveCount(int newCount);
    void setWantCount(int newCount);
    void setPrice(double newPrice);
    //Other functions




};
#endif //INC_220FINALPROJECT_BOOK_H