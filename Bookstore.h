//
// Created by bnkei on 12/3/2017.
//

#ifndef WORKFORFINAL_BOOKSTORE_H
#define WORKFORFINAL_BOOKSTORE_H


#include "ArrayList.h"
#include "Book.h"
#include "Library.h"

class Bookstore {
private:
    Library* inventory;

public:
    Bookstore();
    ~Bookstore();
    void run();
    void printBookInfo(std::string title);
    void modify(std::string title);
    void addBook();
    void printLibrary();
    void sell(std::string title);
    void order(std::string fileName);
    void delivery(std::string fileName);
    void returnBooks(std::string fileName);
    void quit();
};


#endif //WORKFORFINAL_BOOKSTORE_H
