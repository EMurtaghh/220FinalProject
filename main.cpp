#include <iostream>
#include <limits>
#include "List.h"
#include "ArrayList.h"
#include "Bookstore.h"

int main() {
    int choice = 0;
    Bookstore* myStore = new Bookstore;
    while(choice!=2){
        std::cout<<"Enter 0 to add a book or 1 to print the Library or 2 to quit:"<<std::endl;
        std::cin>>choice;
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(),'\n');
        if(choice==0){
            myStore->addBook();
        }
        else if(choice==1){
            myStore->printLibrary();
        }
    }
    myStore->printLibrary();
    std::cout<<"Goodbye"<<std::endl;
    delete myStore;

}