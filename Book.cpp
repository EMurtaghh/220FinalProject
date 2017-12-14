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
    this->waitList = new LinkedQueue<Person>();
}
Book::Book(const Book& bookToCopy){
    this->bookTitle=bookToCopy.bookTitle;
    this->bookAuthor=bookToCopy.bookAuthor;
    this->bookPrice=bookToCopy.bookPrice;
    this->haveCount=bookToCopy.haveCount;
    this->wantCount=bookToCopy.wantCount;
    this->waitList =bookToCopy.waitList; //maybe?
}
Book::~Book() {
    delete waitList;
}
//getters----------------------------------------------------------------------------------------------
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
Queue<Person>* Book::getWaitList(){ //should be const
    return waitList;
}
//setters----------------------------------------------------------------------------------------------
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

//others----------------------------------------------------------------------------------------------
int Book::sell(){
    if(this->haveCount==0){
        std::cout<<"Book count is out of stock."<<std::endl;
        return 0;
    }else if(this->haveCount>0){
        this->haveCount--;
        return 1;
    }
}
void Book::addToWaitList(Person toAdd) {
    this->waitList->enqueue(toAdd);
}
int Book::stock(int amountToAdd){
    if((!waitList->isEmpty())&&(this->haveCount+amountToAdd)>0){
        this->waitList->dequeue();
        amountToAdd--;
    }
    if(amountToAdd>0){
        return this->haveCount+amountToAdd;
    }else{
        return this->haveCount;
    }
}
std::string Book::toString() {
    return this->bookTitle+" by "+this->bookAuthor+" is $"+std::to_string(this->bookPrice);
}


