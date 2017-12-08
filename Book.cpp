//
// Book.cpp
//
#include "Book.h"
#include "Queue.h"
#include "LinkedQueue.h"
#include <iostream>
Book::Book(std::string bookTitle, std::string bookAuthor, double bookPrice, int haveCount, int wantCount){
    this->bookTitle=bookTitle;
    this->bookAuthor=bookAuthor;
    this->bookPrice=bookPrice;
    this->haveCount=haveCount;
    this->wantCount=wantCount;
    this->waitList = new LinkedQueue();
}
//Book::Book(Book& bookToCopy){}; Will be done when needed
//getters
std::string Book::getAuthor() {
    return bookAuthor;
}

double Book::getPrice() {
    return bookPrice;
}

std::string Book::getTitle() {
    return bookTitle;
}
int Book::getHaveCount() {
    return haveCount;
}
int Book::getWantCount() {
    return wantCount;
}
//setters
void Book::setPrice(double newPrice) {
    bookPrice=newPrice;
}

void Book::setAuthor(std::string author){
    this->bookAuthor = author;
}

void Book::setTitle(std::string title) {
    this->bookTitle = title;
}

void Book::setHaveCount(int newCount) {
    this->haveCount = newCount;
}

void Book::setWantCount(int newCount) {
    this->wantCount = newCount;
}

//others


