//
// Created by Bradley Keith on 10/10/2017.
//
#include <iostream>
#include "ArrayList.h"

template <class T>
ArrayList<T>::ArrayList(int initialCapacity){
    array = new T[initialCapacity];
    currItemCount = 0;
    currCapacity = initialCapacity;
}

//Copy Constructor
template <class T>
ArrayList<T>::ArrayList(const ArrayList& arrayListToCopy){
    currItemCount=arrayListToCopy.currItemCount;
    currCapacity = arrayListToCopy.currCapacity;
    array = new T[currCapacity];
    for (int i = 0; i < currItemCount; ++i) {
        array[i] = arrayListToCopy.array[i];
    }
}

//Overloaded Assignment Operator
template <class T>
ArrayList<T>& ArrayList<T>::operator=(const ArrayList<T>& arrayListToCopy){
    if(array!=arrayListToCopy.array||currItemCount!=arrayListToCopy.currItemCount||currCapacity!=arrayListToCopy.currCapacity){
        delete[] array;
        currItemCount = arrayListToCopy.currItemCount;
        currCapacity = arrayListToCopy.currCapacity;
        array = new T[currCapacity];
        for (int i = 0; i < currItemCount; ++i) {
            array[i] = arrayListToCopy.array[i];
        }
    }
    return *this;
}

//Destructor
template <class T>
ArrayList<T>::~ArrayList(){
    delete[] array;
    array=nullptr;
}

template <class T>
void ArrayList<T>::doubleCapacity() {
    T tempArray[currItemCount];
    for(int ndx = 0; ndx<currItemCount;ndx++){
        tempArray[ndx] = array[ndx];
    }
    delete[] array;
    array = new T[2*currCapacity];
    currCapacity = currCapacity*2;
    for(int ndx = 0; ndx<currItemCount; ndx++){
        array[ndx] = tempArray[ndx];
    }
}

template <class T>
void ArrayList<T>::insertAtEnd(T itemToAdd) {
    if(currItemCount+1>=currCapacity){
        this->doubleCapacity();
    }
    array[currItemCount] = itemToAdd;
    currItemCount++;
}

template <class T>
void ArrayList<T>::insertAtFront(T itemToAdd) {
    if(currItemCount+1>=currCapacity){
        this->doubleCapacity();
    }
    currItemCount++;
    for(int ndx = currItemCount-1;ndx >0;ndx--){
        array[ndx] = array[ndx-1];
    }
    array[0] = itemToAdd;
}

template <class T>
void ArrayList<T>::insertAt(T itemToAdd, int index) {
    if(index<0||index>currItemCount){
        throw std::out_of_range("<Error: index out of range>");
    }
    if(currItemCount+1>=currCapacity){
        this->doubleCapacity();
    }
    currItemCount++;
    for(int ndx = currItemCount-1; ndx>index; ndx--){
        array[ndx] = array[ndx-1];
    }
    array[index] = itemToAdd;
}

template <class T>
T ArrayList<T>::getValueAt(int index) {
    if(index<0||index>=currItemCount){
        throw std::out_of_range("<Error: index out of range>");
    }
    return array[index];
}

template <class T>
T ArrayList<T>::removeValueAt(int index) {
    if(index<0||index>=currItemCount){
        throw std::out_of_range("<Error: index out of range>");
    }
    T val = array[index];
    for (int i = index+1; i <currItemCount ; ++i) {
        array[i-1] = array[i];
    }
    currItemCount--;
    return val;
}

template <class T>
bool ArrayList<T>::isEmpty() {
    if(currItemCount<1){
        return true;
    } else{
        return false;
    }
}

template <class T>
int ArrayList<T>::itemCount() {
    return currItemCount;
}

template <class T>
void ArrayList<T>::clearList() {
    delete[] array;
    array = new T[currCapacity];
    currItemCount=0;
}
/*
//may want to change the format of this to be more readable such as a list
//with each new item on a new line
template <class T>
std::string ArrayList<T>::toString() {
    std::string myString;
    myString.append("{");
    if(currItemCount>0) {
        for (int ndx = 0; ndx < currItemCount - 1; ndx++) {
            myString.append(std::to_string(array[ndx]));
            myString.append(", ");
        }
        myString.append(std::to_string(array[currItemCount - 1]));
    }
    myString.append("}");
    return myString;
}
 */

template <class T>
int ArrayList<T>::find(T toFind) {
    for(int ndx = 0; ndx<currItemCount;ndx++){
        if(array[ndx]==toFind){
            return ndx;
        }
    }

    return -1;
}

template <class T>
int ArrayList<T>::findLast(T toFind) {
    int last=-1;
    for(int ndx = 0; ndx<currItemCount;ndx++){
        if(array[ndx]==toFind){
            last = ndx;
        }
    }
    return last;
}