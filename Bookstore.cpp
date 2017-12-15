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

void Bookstore::help() {
    std::cout<<"Command options(case does not matter but be sure to not enter any spaces):"<<std::endl;
    std::cout<<"    H - help"<<std::endl;
    std::cout<<"    I - inquire about a specific book"<<std::endl;
    std::cout<<"    L - list the information for all books being sold"<<std::endl;
    std::cout<<"    A - add a new book to be sold"<<std::endl;
    std::cout<<"    M - modify the information for a specific title"<<std::endl;
    std::cout<<"    O - place an order for books"<<std::endl;
    std::cout<<"    D - add books from a delivery to inventory"<<std::endl;
    std::cout<<"    R - return excess copies"<<std::endl;
    std::cout<<"    Q - save and quit program"<<std::endl;
    std::cout<<" "<<std::endl;

}

int checkValidCommand(std::string c){
    if(c=="I"||c=="i"||c=="L"||c=="l"||c=="A"||c=="a"||c=="M"||c=="m"||c=="O"||c=="o"||c=="D"||c=="d"||c=="R"||c=="r"||c=="Q"||c=="q"||c=="H"||c=="h"){
        return 1;
    }
    else{
        return 0;
    }
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
        std::cout<<"We are currently out of stock Please enter your info to be placed on the wait list"<<std::endl;

    }
    else if(whatHappened==-1){
        std::cout<<"We do not currently sell this book"<<std::endl;
        std::cout<<" "<<std::endl;
    }
    else{
        std::cout<<"Enjoy "<<title<<"!"<<std::endl;
        std::cout<<" "<<std::endl;
    }
    //ToDo maybe print info for book?
}

void Bookstore::quit() {
    inventory->save();
    std::cout<<"Goodbye!"<<std::endl;
}

void Bookstore::run() {
    //Read in from memory file
    std::ifstream inFile("storeMemory.txt");
    if(inFile) {
        while (inFile) {
            char delimiter = (char)",";
            std::string bookLine;
            getline(inFile, bookLine);
            std::stringstream ssline(bookLine);
            std::string title;
            getline(ssline, title, delimiter);
            std::string author;
            getline(ssline,author, delimiter);
            std::string price;
            getline(ssline,price,delimiter);
            double priceDouble = std::stod(price);
            std::string have;
            getline(ssline,have,delimiter);
            int haveInt = std::stoi(have);
            std::string want;
            getline(ssline,want,delimiter);
            int wantInt = std::stoi(want);
            Book* current = new Book(title,author,priceDouble,haveInt,wantInt);
            while(ssline){
                std::string name;
                getline(ssline,name,delimiter);
                std::string number;
                getline(ssline,number,delimiter);
                std::string email;
                getline(ssline,email,delimiter);
                std::string pref;
                getline(ssline,pref,delimiter);
                current->addToWaitList(Person(name,number,email,pref));
            }
            inventory->add(current);
        }
    }
    std::cout<<"Welcome to 220 Books!"<<std::endl;
    std::cout<<" "<<std::endl;
    //menu
    help();
    std::string command = "h";
    while(command!="q"&&command!="Q") {
        std::cout << "Please enter a command: ";
        getline(std::cin, command);
        int ok = ::checkValidCommand(command);
        if (ok == 0) {
            std::cout<<"Invalid command! Please make sure to not enter spaces in your input!"<<std::endl;
            std::cout<<"Enter 'H' to see available commands"<<std::endl;
            std::cout<<" "<<std::endl;
        }
        else{
            if(command=="H"||command=="h"){
                help();
            }
            else if(command=="I"||command=="i"){
                std::cout<<"Please enter title: ";
                std::string title;
                getline(std::cin,title);
                std::cout<<" "<<std::endl;
                inventory->getInfo(title);
            }
            else if()
        }
    }

    //ToDo have menu and loop running through to take input and run corresponding functions

    quit();
}