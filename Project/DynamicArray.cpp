#include "DynamicArray.h"
#include <iostream>
#include <string>
template<typename T>
DynamicArray<T>::DynamicArray()
{
    clear();
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &a)
{
    copyArray(a);
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete [] container;
}

template<typename T>
int DynamicArray<T>::size()
{
    return this->containerSize;
}

template<typename T>
T &DynamicArray<T>::operator[](int k)
        {
    if(k >= elementSize)
    {
        std::cout << "Error, undefined access!\n";
        std::exit(0);
    }
    return container[k];
}

template<typename T>
void DynamicArray<T>::append(const T& a)
{
    if(this->containerSize == this->elementSize) enlargeArray();
    this->container[this->elementSize++] = a;
}

template<typename T>
void DynamicArray<T>::enlargeArray()
{
    if(!this->containerSize)
    {
        this->containerSize = 1;
        return;
    }
    this->containerSize *= 2;
    T* containerTmp = new T[this->containerSize];
    for (int i = 0; i < this->elementSize; ++i)
        containerTmp[i] = this->container[i];
    delete [] this->container;
    this->container = containerTmp;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& a)
{
    copyArray(a);
    return *this;
}

template<typename T>
void DynamicArray<T>::copyArray(const DynamicArray<T> &a) {
    this->containerSize = a.containerSize;
    this->elementSize = a.elementSize;
    delete [] container;
    container = new T[this->containerSize];
    for (int i = 0; i < this->elementSize; ++i)
        container[i] = a.container[i];
}

template<typename T>
void DynamicArray<T>::clear() {
    delete [] this->container;
    this->containerSize = 1;
    this->elementSize = 0;
    this->container = new T[containerSize];
}
