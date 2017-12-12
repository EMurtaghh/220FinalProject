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
    list->insertAt(toAdd,index);
}


