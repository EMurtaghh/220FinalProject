//
// Created by bnkei on 12/3/2017.
//

#include "Bookstore.h"
#include "Book.h"
#include <string>
#include <exception>
#include <iostream>
#include <fstream>
#include <sstream>

Bookstore::Bookstore() {
    inventory = new Library();
}

Bookstore::~Bookstore() {
    delete[] inventory;
}

int checkIfInt(std::string value){
    try {
        int toReturn = std::stoi(value);
        if(toReturn<0){
            return -1;
        }
        return toReturn;
    }
    catch (const std::invalid_argument &e) {
        std::cout<<"Error: Please enter an integer"<<std::endl;
        return -1;
    }
}

double checkIfDouble(std::string value){
    try{
        double toReturn = std::stod(value);
        if(toReturn<0){
            return -1;
        }
        toReturn = toReturn*100;
        int dollars = (int)toReturn;
        toReturn = (double)dollars;
        toReturn = toReturn/100;
        return toReturn;
    }
    catch(const std::invalid_argument& e) {
        std::cout<<"Error: Please enter a real number"<<std::endl;
        return -1;
    }
}

void Bookstore::addBook() {
    std::string title;
    std::cout<<"Please enter book title:"<<std::endl;
    std::getline(std::cin,title);
    //std::cout<<title<<std::endl;
    std::string author;
    std::cout<<"Please enter author:"<<std::endl;
    std::getline(std::cin,author);
    //std::cout<<author<<std::endl;
    std::string price;
    double priced = -1;
    std::cout<<"Please enter book price:"<<std::endl;
    while(priced==-1) {
        std::getline(std::cin, price);
        ::checkIfDouble(price);
    }
    //std::cout<<price<<std::endl;
    std::string have;
    int haveint = -1;
    std::cout << "Please enter quantity have:" << std::endl;
    while(haveint==-1) {
        std::getline(std::cin, have);
        haveint = ::checkIfInt(have);
    }
    //std::cout<<have<<std::endl;
    std::string want;
    int wantint = -1;
    std::cout<<"Please enter quantity want:"<<std::endl;
    while(wantint==-1) {
        std::getline(std::cin, want);
        wantint = ::checkIfInt(want);
    }
    //std::cout<<want<<std::endl;
    Book* bookToAdd = new Book(title,author,priced,haveint,wantint);
    inventory->add(bookToAdd);

    //ToDo print out info of book added and offer for edits to be made
}

void Bookstore::printLibrary() {
    inventory->printList();
}

void Bookstore::printBookInfo(std::string title) {
    inventory->getInfo(title);
}


void Bookstore::sell(std::string title) {
    int whatHappened = inventory->sell(title);
    if(whatHappened==0){
        //ToDo prompt for customer info and add person to books waitlist - since allvalues are string dont need to check them except maybe preference
    }
    //ToDo maybe print info for book?
}

void Bookstore::quit() {
    inventory->save();
    std::cout<<"Goodbye!"<<std::endl;
}

void Bookstore::run() {
    //ToDo read in from file
    std::ifstream inFile("storeMemory.txt");
    if(inFile) {
        while (inFile) {
            std::string bookLine;
            getline(inFile, bookLine);
            std::stringstream line(bookLine);
            std::string title;
            std::getline(line, title, ",");

        }
    }

    }


    //ToDo have menu and loop running through to take input and run corresponding functions

    quit();
}