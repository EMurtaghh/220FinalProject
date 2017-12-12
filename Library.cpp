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

void Library::add(Book *toAdd) {
    
}
