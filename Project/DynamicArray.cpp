#include "DynamicArray.h"
#include <iostream>
#include <string>

// ------------------------------ Dynamic Array implementation -----------------------------

template<typename T>
DynamicArray<T>::DynamicArray()
{
    this->containerSize = 0;
    clear();
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T> &a)
{
    if(*this != a) copyArray(a);
}

template<typename T>
DynamicArray<T>::DynamicArray(const int &size) {
    this->containerSize = size;
    this->elementSize = 0;
    this->container = new T[size];
}

template<typename T>
DynamicArray<T>::DynamicArray(const int &size, const T &initialValue) {
    this->containerSize = size;
    this->elementSize = size;
    this->container = new T[size];
    for (int i = 0; i < size; ++i) {
        this->container[i] = initialValue;
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray &&a) noexcept {
    if(this != a){
        copyArray(a);
        delete a;
    }
}

template<typename T>
DynamicArray<T>::~DynamicArray()
{
    delete [] container;
}

template<typename T>
void DynamicArray<T>::copyArray(const DynamicArray<T> &a) {
    clear();
    this->containerSize = a.containerSize;
    this->elementSize = a.elementSize;
    delete [] container;
    container = new T[this->containerSize];
    for (int i = 0; i < this->elementSize; ++i)
        container[i] = a.container[i];
}

template<typename T>
T &DynamicArray<T>::operator[](int k)
        {
    if(k >= elementSize)
    {
        std::exit(-1);
    }
    return container[k];
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
T DynamicArray<T>::append(T a)
{
    if(this->containerSize == this->elementSize) enlargeArray();
    return this->container[this->elementSize++] = a;
}

template<typename T>
void DynamicArray<T>::clear() {
    if(this->containerSize) delete [] this->container;
    this->containerSize = 1;
    this->elementSize = 0;
    this->container = new T[containerSize];
}

template<typename T>
int DynamicArray<T>::size()
{
    return this->containerSize;
}

template<typename T>
DynamicArray<T>& DynamicArray<T>::operator=(const DynamicArray<T>& a)
{
    copyArray(a);
    return *this;
}

template<typename T>
DynamicArray<T> &DynamicArray<T>::operator=(DynamicArray<T> &&a) noexcept {
    if(*this != a){
        copyArray(a);
    }
    return *this;
}

template<typename T>
void DynamicArray<T>::pop_back() {
    if(!elementSize){
        exit(-1);
    }
    --elementSize;
}

template<typename T>
void DynamicArray<T>::sort(iterator& begin, iterator& end, const bool& isIncreasing) {
    int from = begin - this->begin();
    int to = end - this->begin() - 1;
    if(from > to || to >= elementSize){
        exit(-1);
    }
    mergeSort(from, to, isIncreasing);
}

template<typename T>
void DynamicArray<T>::sort(iterator&& begin, iterator&& end, const bool& isIncreasing) {
    int from = begin - this->begin();
    int to = end - this->begin() - 1;
    if(from > to || to >= elementSize){
        exit(-1);
    }
    mergeSort(from, to, isIncreasing);
}

template<typename T>
void DynamicArray<T>::mergeRecursion(const int& left, const int& mid, const int& right, const bool& isIncreasing)
{
    // Size of the right and left sub-arrays
    auto const subArrayOne = mid - left + 1;
    auto const subArrayTwo = right - mid;

    // Create temp arrays to store the values that in original indices
    auto *leftArray = new int[subArrayOne], *rightArray = new int[subArrayTwo];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < subArrayOne; i++)
        leftArray[i] = container[left + i];
    for (auto j = 0; j < subArrayTwo; j++)
        rightArray[j] = container[mid + 1 + j];

    int indexOfSubArrayOne = 0, // Initial index of first sub-array
    indexOfSubArrayTwo = 0, // Initial index of second sub-array
    indexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (indexOfSubArrayOne < subArrayOne && indexOfSubArrayTwo < subArrayTwo) {
        if (leftArray[indexOfSubArrayOne] <= rightArray[indexOfSubArrayTwo]) {
            if(isIncreasing){
                container[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }else{
                container[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }
        }
        else {
            if(isIncreasing){
                container[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
                indexOfSubArrayTwo++;
            }else{
                container[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
                indexOfSubArrayOne++;
            }
        }
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (indexOfSubArrayOne < subArrayOne) {
        container[indexOfMergedArray] = leftArray[indexOfSubArrayOne];
        indexOfSubArrayOne++;
        indexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (indexOfSubArrayTwo < subArrayTwo) {
        container[indexOfMergedArray] = rightArray[indexOfSubArrayTwo];
        indexOfSubArrayTwo++;
        indexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template<typename T>
void DynamicArray<T>::mergeSort(const int& begin, const int& end, const bool& isIncreasing)
{
    if (begin >= end) return;

    auto mid = begin + (end - begin) / 2;
    // Split the array from begin to end to two subarray (equal with length)
    mergeSort(begin, mid, isIncreasing);
    mergeSort(mid + 1, end, isIncreasing);

    // Compare the two subarray (from begin to mid) and (from mid + 1 to end)
    mergeRecursion(begin, mid, end, isIncreasing);
}

template<typename T>
typename DynamicArray<T>::iterator
DynamicArray<T>::lower_bound(const int &begin, const int &end, const T &value, const bool& isIncreasing) {
    /*
     * if the array is increasing,
     *      return the first index that its value is greater than or equal to the given value in the parameter
     * if the array is decreasing,
     *      return the first index that its value is smaller than or equal to the given value in the parameter
     */
    int l = begin, r = end;
    int targetIndex;
    bool foundValue = false;

    while (l <= r){
        int mid = l + (r - l)/2;
        if(isIncreasing){
            if(container[mid] >= value){
                foundValue = true;
                targetIndex = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }else{
            if(container[mid] <= value){
                foundValue = true;
                targetIndex = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
    }

    if(!foundValue) return DynamicArray::iterator(&container[elementSize]);
    else return DynamicArray::iterator(&container[targetIndex]);
}

template<typename T>
int DynamicArray<T>::upper_bound(const int &begin, const int &end, const T &value, const bool& isIncreasing) {
    /*
     * if the array is increasing,
     *      return the first index that its value is greater than the given value in the parameter
     * if the array is decreasing,
     *      return the first index that its value is smaller than the given value in the parameter
     */
    int l = begin, r = end;
    int targetIndex;
    bool foundValue = false;

    while (l <= r){
        int mid = l + (r - l)/2;
        if(isIncreasing){
            if(container[mid] > value){
                foundValue = true;
                targetIndex = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }else{
            if(container[mid] < value){
                foundValue = true;
                targetIndex = mid;
                r = mid - 1;
            }else{
                l = mid + 1;
            }
        }
    }

    if(!foundValue) return -1;
    else return targetIndex;
}

template<typename T>
void DynamicArray<T>::append(DynamicArray &a) {
    while(this->elementSize + a.elementSize > this->containerSize){
        this->enlargeArray();
    }
    for(auto& val : a){
        this->append(val);
    }
}

template<typename T>
void DynamicArray<T>::append(DynamicArray &&a) {
    while(this->elementSize + a.elementSize > this->containerSize){
        this->enlargeArray();
    }
    for(auto val : a){
        this->append(val);
    }
}

template<typename T>
void DynamicArray<T>::eliminate() {
    delete [] container;
}

template<typename T>
void swap(DynamicArray<T>& a, DynamicArray<T>& b) {
    DynamicArray<T> tmp;
    tmp = std::move(a);
    a = std::move(b);
    b = std::move(tmp);
}

template<typename T>
bool DynamicArray<T>::operator!=(const DynamicArray<T> &a) {
    return this->container == a.container;
}

template<typename T>
bool DynamicArray<T>::isEmpty() {
    return !this->elementSize;
}

template<typename T>
void DynamicArray<T>::erase(DynamicArray::iterator &itr) {
    T* containerTmp = new T[this->containerSize];
    int index = itr - this->begin();
    int tmpPosition = 0;

    for (int i = 0; i < index; ++i) {
        containerTmp[tmpPosition ++] = this->container[i];
    }
    for (int i = index + 1; i < this->elementSize; ++i) {
        containerTmp[tmpPosition ++] = this->container[i];
    }

    delete [] this->container;
    this->elementSize --;
    this->container = containerTmp;
}

// --------------------------------- Iterator implementation ---------------------------------------

template<typename T>
DynamicArray<T>::iterator::iterator(T *pInt) {
    // Make the pointer that the iterator refers to equal to the given pointer
    iterator_ptr = pInt;
}

template<typename T>
T &DynamicArray<T>::iterator::operator*() const {
    // Return the value that the iterator refers to
    return *iterator_ptr;
}

template<typename T>
T *DynamicArray<T>::iterator::operator->() {
    // return the pointer that equal to the iterator
    return iterator_ptr;
}

template<typename T>
typename DynamicArray<T>::iterator &DynamicArray<T>::iterator::operator++() {
    // Make the iterator refers to the next position in the memory
    iterator_ptr++;
    return *this;
}

template<typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::iterator::operator++(int) {
    // Postfix increasing iterator will refer to the next position in the memory and will return this new iterator
    iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
int DynamicArray<T>::iterator::operator-(DynamicArray::iterator another) {
    // Subtract two iterators from each other
    return this->iterator_ptr - another.iterator_ptr;
}

template<typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::iterator::operator+(const int &value) {
    // Make the iterator jumps to the position ( pointer + value )
    iterator_ptr += value;
    return *this;
}

// --------------------------------- Reversed iterator implementation ---------------------------------------


template<typename T>
DynamicArray<T>::reverse_iterator::reverse_iterator(T *pInt) {
    // Make the pointer that the reversed iterator refers to equal to the given pointer
    reverse_iterator_ptr = pInt;
}

template<typename T>
T &DynamicArray<T>::reverse_iterator::operator*() const {
    // Return the value that the reversed iterator refers to
    return *reverse_iterator_ptr;
}

template<typename T>
T *DynamicArray<T>::reverse_iterator::operator->() {
    // return the pointer that equal to the reversed iterator
    return reverse_iterator_ptr;
}

template<typename T>
typename DynamicArray<T>::reverse_iterator &DynamicArray<T>::reverse_iterator::operator++() {
    // Make the reversed iterator refers to the previous position in the memory
    reverse_iterator_ptr --;
    return *this;
}

template<typename T>
typename DynamicArray<T>::reverse_iterator DynamicArray<T>::reverse_iterator::operator++(int) {
    // Postfix decreasing reversed iterator will refer to the previous position in the memory
    // and will return this new reversed iterator
    reverse_iterator tmp = *this;
    // ++ operator will make the pointer refers to the previous position in th memory
    ++ (*this);
    return tmp;
}

template<typename T>
int DynamicArray<T>::reverse_iterator::operator-(DynamicArray::reverse_iterator another) {
    // Subtract two iterators from each other
    return this->reverse_iterator_ptr - another.reverse_iterator_ptr;
}

template<typename T>
typename DynamicArray<T>::reverse_iterator DynamicArray<T>::reverse_iterator::operator+(const int &value) {
    // Make the reversed iterator jumps to the position ( pointer + value )
    reverse_iterator_ptr += value;
    return *this;
}
