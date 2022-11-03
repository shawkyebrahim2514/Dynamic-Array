#include "DynamicArray.h"
#include <iostream>
#include <string>

template<typename T>
DynamicArray<T>::DynamicArray()
{
    this->containerSize = 0;
    clear();
}

template<typename T>
DynamicArray<T>::DynamicArray(const DynamicArray &a)
{
    if(this != a) copyArray(a);
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
T DynamicArray<T>::append(const T& a)
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
    if(this != a){
        copyArray(a);
        delete a;
    }
}

template<typename T>
void DynamicArray<T>::pop_back() {
    if(!elementSize){
        exit(-1);
    }
    --elementSize;
}

template<typename T>
void DynamicArray<T>::sort(const int& begin, const int& end, const bool& isIncreasing) {
    if(begin > end || end >= elementSize){
        exit(-1);
    }
    mergeSort(begin, end, isIncreasing);
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
int DynamicArray<T>::lower_bound(const int &begin, const int &end, const T &value, const bool& isIncreasing) {
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

    if(!foundValue) return -1;
    else return targetIndex;
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