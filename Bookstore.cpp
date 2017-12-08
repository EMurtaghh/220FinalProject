//
// Created by bnkei on 12/3/2017.
//

#include "Bookstore.h"
#include "Book.h"

Bookstore::Bookstore() {
    library = new ArrayList<Book*>();
}

Bookstore::~Bookstore() {
    delete[] library;
}

void Bookstore::addBook() {
    std::string title;
    std::cout<<"Please enter book title:"<<std::endl;
    std::getline(std::cin,title);
    std::cout<<title<<std::endl;
    std::string author;
    std::cout<<"Please enter author:"<<std::endl;
    std::getline(std::cin,author);
    std::cout<<author<<std::endl;
    double price;
    std::cout<<"Please enter book price:"<<std::endl;
    std::cin>>price;
    std::cout<<price<<std::endl;
    int have;
    std::cout<<"Please enter quantity have:"<<std::endl;
    std::cin>>have;
    std::cout<<have<<std::endl;
    int want;
    std::cout<<"Please enter quantity want:"<<std::endl;
    std::cin>>want;
    std::cout<<want<<std::endl;
    Book* bookToAdd = new Book(title,author,price,have,want);
    library->insertAtEnd(bookToAdd);
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
