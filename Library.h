//
// Created by bnkei on 12/11/2017.
//

#ifndef INC_220FINALPROJECT_LIBRARY_H
#define INC_220FINALPROJECT_LIBRARY_H

#include "List.h"
#include "Book.h"
#include "Person.h"


class Library {
private:

    List<Book*>* list;

public:
    Library();
    ~Library();
    Book* accessBook(std::string title);
    void add(Book* toAdd); //if book not already in Library add it in sorted way or if it already exists just add stock to existing book?
    int stock(std::string title, int numBooks);
    void getInfo(std::string title);
    int sell(std::string title);//find book and sell it or prompt to enter info and add to waitList
    void printList();
    void save();
    int find(std::string title);//return index or -1 if not in library


};


#endif //INC_220FINALPROJECT_LIBRARY_H
