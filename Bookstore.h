//
// Created by bnkei on 12/3/2017.
//

#ifndef WORKFORFINAL_BOOKSTORE_H
#define WORKFORFINAL_BOOKSTORE_H


#include "ArrayList.h"
#include "Book.h"

class Bookstore {
private:
    List<Book*>* library;

public:
    Bookstore();
    ~Bookstore();
    void addBook();
    void printLibrary();

};


#endif //WORKFORFINAL_BOOKSTORE_H
