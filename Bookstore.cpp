//
// Created by bnkei on 12/3/2017.
//

#include "Bookstore.h"
#include "Book.h"
#include <string>
#include <exception>

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
    std::cout<<"Please enter book price:"<<std::endl;
    std::getline(std::cin,price);
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
    Book* bookToAdd = new Book(title,author,price,haveint,wantint);
    inventory->add(bookToAdd);
}

void Bookstore::printLibrary() {
    if(library->itemCount()==0){
std::cout<<"Library empty!"<<std::endl;
    }
    else {
        for (int i = 0; i < library->itemCount(); ++i) {
            std::cout << " " << std::endl;
            Book* current = library->getValueAt(i);
            std::cout << current->getTitle();
            std::cout << " by ";
            std::cout << current->getAuthor();
            std::cout << " $";
            std::cout << current->getPrice();
            std::cout << " have ";
            std::cout << current->getHaveCount();
            std::cout << " copies" << std::endl;
        }
    }
}
