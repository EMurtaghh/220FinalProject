//
// Created by bnkei on 12/11/2017.
//

#include "Library.h"
#include "List.h"
#include "ArrayList.h"

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

void Library::getInfo(std::string title) {
    int index=find(title);
    std::cout<<list->getValueAt(index)->getTitle()<<std::endl;
    std::cout<<"by "<<list->getValueAt(index)->getAuthor()<<std::endl;
    std::cout<<"$"<<list->getValueAt(index)->getPrice()<<std::endl;
    std::cout<<list->getValueAt(index)->getHaveCount()<<" copies in stock"<<std::endl;
    std::cout<<list->getValueAt(index)->getWantCount()<<" copies should be in stock"<<std::endl;
}

int Library::sell(std::string title) {
    int index = find(title);
    return list->getValueAt(index)->sell();
}

void  Library::printList() {
    for(int i = 0;1<list->itemCount();i++){
        std::cout<<list->getValueAt(i)->getTitle()<<std::endl;
        std::cout<<"by "<<list->getValueAt(i)->getAuthor()<<std::endl;
        std::cout<<"$"<<list->getValueAt(i)->getPrice()<<std::endl;
        std::cout<<list->getValueAt(i)->getHaveCount()<<" copies in stock"<<std::endl;
        std::cout<<list->getValueAt(i)->getWantCount()<<" copies should be in stock"<<std::endl;
        std::cout<<"Customers waiting for book:"<<std::endl;
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


