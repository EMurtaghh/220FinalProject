//
// Created by bnkei on 12/11/2017.
//

#include "Library.h"
#include "List.h"
#include <string>
#include "ArrayList.h"
#include <fstream>

Library::Library() {
    this->list = new ArrayList<Book*>();
}

Library::~Library(){
    delete list;
}

//may want to change later to make recursive for efficiency
void Library::add(Book *toAdd) {
    int index = 0;
    while((toAdd->getTitle()>list->getValueAt(index)->getTitle())&&(index<list->itemCount())){
        index++;
    }
    if(toAdd->getTitle()==list->getValueAt(index)->getTitle()){
        list->getValueAt(index)->stock(toAdd->getHaveCount());
        delete toAdd;
    }
    else {
        list->insertAt(toAdd, index);
    }
}

int Library::stock(std::string title, int numBooks) {
    int index = find(title);
    return list->getValueAt(index)->stock(numBooks);
}

void Library::getInfo(std::string title) {
    int index=find(title);
    std::cout<<list->getValueAt(index)->getTitle()<<std::endl;
    std::cout<<"by "<<list->getValueAt(index)->getAuthor()<<std::endl;
    std::cout<<"$"<<list->getValueAt(index)->getPrice()<<std::endl;
    std::cout<<list->getValueAt(index)->getHaveCount()<<" copies in stock"<<std::endl;
    std::cout<<list->getValueAt(index)->getWantCount()<<" copies should be in stock"<<std::endl;
    std::cout<<"Customers waiting for book: "<<list->getValueAt(index)->getWaitList()->getItemCount()<<std::endl;
}

int Library::sell(std::string title) {
    int index = find(title);
    return list->getValueAt(index)->sell();
}

void  Library::printList() {
    std::cout<<"Inventory:"<<std::endl;
    if(list->isEmpty()){
        std::cout<<"    Inventory is empty"<<std::endl;
        std::cout<<" "<<std::endl;
    }
    for(int i = 0;1<list->itemCount();i++){
        std::cout<<"    "<<list->getValueAt(i)->getTitle()<<std::endl;
        std::cout<<"    "<<"by "<<list->getValueAt(i)->getAuthor()<<std::endl;
        std::cout<<"    "<<"$"<<list->getValueAt(i)->getPrice()<<std::endl;
        std::cout<<"    "<<list->getValueAt(i)->getHaveCount()<<" copies in stock"<<std::endl;
        std::cout<<"    "<<list->getValueAt(i)->getWantCount()<<" copies should be in stock"<<std::endl;
        std::cout<<"    "<<"Customers waiting for book: "<<list->getValueAt(i)->getWaitList()->getItemCount()<<std::endl;
        std::cout<<" "<<std::endl;
    }
}

void Library::save() {
    std::ofstream outf("storeMemory.txt");
    if(outf){
        for(int i=0;i<list->itemCount();i++){
            Book* current = list->getValueAt(i);
            outf<<current->getTitle()<<", ";
            outf<<current->getAuthor()<<", ";
            outf<<std::to_string(current->getPrice())<<", ";
            outf<<std::to_string(current->getHaveCount())<<", ";
            outf<<std::to_string(current->getWantCount())<<", ";
            while(!current->getWaitList()->isEmpty()){
                outf<<current->getWaitList()->dequeue().toSave()<<", ";
            }
        }
        outf.close();
    }
    else{
        std::cout << "Error in opening storeMemory.txt";
    }
}

int Library::find(std::string title) {//probably want to implement binfind later
    int index = 0;
    while((title>=list->getValueAt(index)->getTitle())&&(index<list->itemCount())){
        if(title==list->getValueAt(index)->getTitle()){
            return index;
        }
        index++;
    }
    return -1;
}


