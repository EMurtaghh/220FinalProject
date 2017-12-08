//
// Book.h
//

#ifndef INC_220FINALPROJECT_BOOK_H
#define INC_220FINALPROJECT_BOOK_H

#include <string>

class Book{
private:
    std::string bookTitle;
    std::string bookAuthor;
    double bookPrice;
    int haveCount;
    int wantCount;

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
    void setPrice(double newPrice);
    //Other functions




};
#endif //INC_220FINALPROJECT_BOOK_H