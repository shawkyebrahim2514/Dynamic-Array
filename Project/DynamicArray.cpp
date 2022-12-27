#include "DynamicArray.h"
#include <string>

// ------------------------------ Dynamic Array implementation -----------------------------

template<typename T>
DynamicArray<T>::DynamicArray() {
    this->currentSize = 0;
    clear();
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray<T> &anotherArray) {
    this->currentSize = 0;
    if (this != &anotherArray)
        copyArray(anotherArray);
}

template<typename T>
DynamicArray<T>::DynamicArray(const int &size) {
    this->currentCapacity = size;
    this->currentSize = 0;
    this->container = new T[size];
}

template<typename T>
DynamicArray<T>::DynamicArray(const int &size, const T &initialValue) {
    this->currentCapacity = size;
    this->currentSize = size;
    this->container = new T[size];
    for (int i = 0; i < size; ++i) {
        this->container[i] = initialValue;
    }
}

template<typename T>
DynamicArray<T>::DynamicArray(DynamicArray &&anotherArray) noexcept {
    this->currentSize = 0;
    if (this != &anotherArray) {
        copyArray(anotherArray);
        delete anotherArray;
    }
}

template<typename T>
void DynamicArray<T>::copyArray(const DynamicArray<T> &anotherArray) {
    clear();
    this->currentCapacity = anotherArray.currentCapacity;
    this->currentSize = anotherArray.currentSize;
    delete[] container;
    container = new T[this->currentCapacity];
    for (int i = 0; i < this->currentSize; ++i)
        container[i] = anotherArray.container[i];
}

template<typename T>
DynamicArray<T>::~DynamicArray() {
    delete[] container;
}

template<typename T>
T &DynamicArray<T>::operator[](int index) {
    if (index >= currentSize) {
        std::exit(-1);
    }
    return container[index];
}

template<typename T>
void DynamicArray<T>::enlargeArray() {
    if (this->currentCapacity == 0) {
        this->currentCapacity = 1;
        return;
    }
    this->currentCapacity *= 2;
    T *containerTmp = new T[this->currentCapacity];
    for (int i = 0; i < this->currentSize; ++i)
        containerTmp[i] = this->container[i];
    delete[] this->container;
    this->container = containerTmp;
}

template<typename T>
T DynamicArray<T>::push_back(T value) {
    if (this->currentCapacity == this->currentSize)
        enlargeArray();
    return (this->container[this->currentSize++] = value);
}

template<typename T>
void DynamicArray<T>::clear() {
    if (this->currentSize != 0)
        delete[] this->container;
    this->currentCapacity = 1;
    this->currentSize = 0;
    this->container = new T[currentCapacity];
}

template<typename T>
int DynamicArray<T>::size() {
    return (this->currentSize);
}

template<typename T>
DynamicArray<T> &DynamicArray<T>::operator=(const DynamicArray<T> &anotherArray) {
    copyArray(anotherArray);
    return (*this);
}

template<typename T>
void DynamicArray<T>::pop_back() {
    if (currentSize == 0) {
        exit(-1);
    }
    --currentSize;
}

template<typename T>
void DynamicArray<T>::sort(const iterator &begin, const iterator &end, const bool &isIncreasing) {
    iterator tmpBegin = begin, tmpEnd = end;
    int from = tmpBegin - this->begin();
    int to = tmpEnd - this->begin() - 1;
    if (from > to || to >= currentSize) {
        exit(-1);
    }
    mergeSort(from, to, isIncreasing);
}

template<typename T>
void DynamicArray<T>::mergeSort(const int &begin, const int &end, const bool &isIncreasing) {
    if (begin >= end) return;
    auto mid = begin + (end - begin) / 2;

    // Split the array from begin to end to two subarray (equal with length)
    mergeSort(begin, mid, isIncreasing);
    mergeSort(mid + 1, end, isIncreasing);

    // Compare the two subarray (from begin to mid) and (from mid + 1 to end)
    mergeRecursion(begin, mid, end, isIncreasing);
}

template<typename T>
void DynamicArray<T>::mergeRecursion(const int &left, const int &mid, const int &right, const bool &isIncreasing) {
    // Size of the right and left sub-arrays
    auto const sizeOfLeftArray = mid - left + 1;
    auto const sizeOfRightArray = right - mid;

    // Create temp arrays to store the values that in original indices
    T *leftArray = new T[sizeOfLeftArray], *rightArray = new T[sizeOfRightArray];

    // Copy data to temp arrays leftArray[] and rightArray[]
    for (auto i = 0; i < sizeOfLeftArray; i++)
        leftArray[i] = container[left + i];
    for (auto j = 0; j < sizeOfRightArray; j++)
        rightArray[j] = container[mid + 1 + j];

    int currentIndexOfLeftArray = 0, // Initial index of first sub-array
    currentIndexOfRightArray = 0, // Initial index of second sub-array
    currentIndexOfMergedArray = left; // Initial index of merged array

    // Merge the temp arrays back into array[left..right]
    while (currentIndexOfLeftArray < sizeOfLeftArray && currentIndexOfRightArray < sizeOfRightArray) {
        if (leftArray[currentIndexOfLeftArray] <= rightArray[currentIndexOfRightArray]) {
            if (isIncreasing) {
                container[currentIndexOfMergedArray] = leftArray[currentIndexOfLeftArray];
                currentIndexOfLeftArray++;
            } else {
                container[currentIndexOfMergedArray] = rightArray[currentIndexOfRightArray];
                currentIndexOfRightArray++;
            }
        } else {
            if (isIncreasing) {
                container[currentIndexOfMergedArray] = rightArray[currentIndexOfRightArray];
                currentIndexOfRightArray++;
            } else {
                container[currentIndexOfMergedArray] = leftArray[currentIndexOfLeftArray];
                currentIndexOfLeftArray++;
            }
        }
        currentIndexOfMergedArray++;
    }

    // Copy the remaining elements of
    // left[], if there are any
    while (currentIndexOfLeftArray < sizeOfLeftArray) {
        container[currentIndexOfMergedArray] = leftArray[currentIndexOfLeftArray];
        currentIndexOfLeftArray++;
        currentIndexOfMergedArray++;
    }

    // Copy the remaining elements of
    // right[], if there are any
    while (currentIndexOfRightArray < sizeOfRightArray) {
        container[currentIndexOfMergedArray] = rightArray[currentIndexOfRightArray];
        currentIndexOfRightArray++;
        currentIndexOfMergedArray++;
    }

    delete[] leftArray;
    delete[] rightArray;
}

template<typename T>
typename DynamicArray<T>::iterator
DynamicArray<T>::lower_bound(const iterator &begin, const iterator &end, const T &value, const bool &isIncreasing) {
    /*
     * if the array is increasing,
     *      return the first index that its value is greater than or equal to the given value in the parameter
     * if the array is decreasing,
     *      return the first index that its value is smaller than or equal to the given value in the parameter
     */
    iterator tmpBegin = begin;
    iterator tmpEnd = end;
    int l = tmpBegin - this->begin(), r = tmpEnd - this->begin() - 1;
    int targetIndex;
    bool foundValue = false;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (isIncreasing) {
            if (container[mid] >= value) {
                foundValue = true;
                targetIndex = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (container[mid] <= value) {
                foundValue = true;
                targetIndex = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    if (!foundValue)
        return this->end();
    else
        return iterator(&container[targetIndex]);
}

template<typename T>
typename DynamicArray<T>::iterator
DynamicArray<T>::upper_bound(const iterator &begin, const iterator &end, const T &value, const bool &isIncreasing) {
    /*
     * if the array is increasing,
     *      return the first index that its value is greater than the given value in the parameter
     * if the array is decreasing,
     *      return the first index that its value is smaller than the given value in the parameter
     */
    iterator tmpBegin = begin;
    iterator tmpEnd = end;
    int l = tmpBegin - this->begin(), r = tmpEnd - this->begin() - 1;
    int targetIndex;
    bool foundValue = false;

    while (l <= r) {
        int mid = l + (r - l) / 2;
        if (isIncreasing) {
            if (container[mid] > value) {
                foundValue = true;
                targetIndex = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        } else {
            if (container[mid] < value) {
                foundValue = true;
                targetIndex = mid;
                r = mid - 1;
            } else {
                l = mid + 1;
            }
        }
    }

    if (!foundValue)
        return this->enlargeArray();
    else
        return iterator(&container[targetIndex]);
}

template<typename T>
void DynamicArray<T>::push_back(DynamicArray &anotherArray) {
    while (this->currentSize + anotherArray.currentSize > this->currentCapacity) {
        this->enlargeArray();
    }
    for (auto &element: anotherArray) {
        this->push_back(element);
    }
}

template<typename T>
void DynamicArray<T>::push_back(DynamicArray &&anotherArray) {
    while (this->currentSize + anotherArray.currentSize > this->currentCapacity) {
        this->enlargeArray();
    }
    for (auto &element: anotherArray) {
        this->push_back(element);
    }
}

template<typename T>
void swap(DynamicArray<T> &firstArray, DynamicArray<T> &secondArray) {
    DynamicArray<T> tmp;
    tmp = std::move(firstArray);
    firstArray = std::move(secondArray);
    secondArray = std::move(tmp);
}

template<typename T>
bool DynamicArray<T>::operator==(const DynamicArray<T> &anotherArray) {
    for (int i = 0; i < std::min(this->currentSize, anotherArray.currentSize); ++i) {
        if (this->container[i] != anotherArray.container[i]) {
            return false;
        }
    }
    return (this->currentSize == anotherArray.currentSize);
}

template<typename T>
bool DynamicArray<T>::operator!=(const DynamicArray<T> &anotherArray) {
    return (this->container == anotherArray.container) == false;
}

template<typename T>
bool DynamicArray<T>::isEmpty() {
    return (this->currentSize == 0);
}

template<typename T>
void DynamicArray<T>::erase(DynamicArray::iterator position) {
//    if(itr >= this->end()) return;
//
//    T* containerTmp = new T[this->currentCapacity];
//    int index = itr - this->begin();
//    int tmpPosition = 0;
//
//    for (int i = 0; i < index; ++i) {
//        containerTmp[tmpPosition ++] = this->container[i];
//    }
//    for (int i = index + 1; i < this->currentSize; ++i) {
//        containerTmp[tmpPosition ++] = this->container[i];
//    }
//
//    delete [] this->container;
//    this->currentSize --;
//    this->container = containerTmp;
    if (position < this->begin() || position > this->end() - 1)
        exit(-1);
    T *tmpContainer = new T[this->currentCapacity];
    for (auto i = this->begin(); i < position; ++i) {
        if (i == this->end()) break;
        tmpContainer[i - this->begin()] = *i;
    }
    for (auto i = position + 1; i < this->end(); ++i) {
        tmpContainer[i - this->begin() - 1] = *i;
    }
    delete[] this->container;
    this->currentCapacity--;
    this->container = tmpContainer;
}

template<typename T>
void DynamicArray<T>::erase(const T &value) {
    int index = -1;
    for (int i = 0; i < this->currentSize; ++i) {
        if (container[i] == value) {
            index = i;
            break;
        }
    }
    if (index == -1) return;

    T *containerTmp = new T[this->currentCapacity];
    int tmpPosition = 0;

    for (int i = 0; i < index; ++i) {
        containerTmp[tmpPosition++] = this->container[i];
    }
    for (int i = index + 1; i < this->currentSize; ++i) {
        containerTmp[tmpPosition++] = this->container[i];
    }

    delete[] this->container;
    this->currentSize--;
    this->container = containerTmp;
}

template<typename T>
void DynamicArray<T>::erase(DynamicArray::iterator startPosition, DynamicArray::iterator endPosition) {
    if (startPosition < this->begin() || startPosition > this->end() - 1
        || endPosition < this->begin() || endPosition > this->end() - 1) {
        exit(-1);
    }
    T *tmpContainer = new T[this->currentCapacity];
    int difference = endPosition - startPosition;
    for (auto i = this->begin(); i < startPosition; ++i) {
        tmpContainer[i - this->begin()] = *i;
    }
    for (auto i = endPosition; i < this->end(); ++i) {
        tmpContainer[i - this->begin() - difference] = *i;
    }
    delete[] this->container;
    this->container = tmpContainer;
    this->currentSize -= difference;
}

template<typename T>
void DynamicArray<T>::resize(int newSize) {
    T *tmpContainer = new T[newSize];
    for (int i = 0; i < std::min(newSize, this->currentSize); ++i) {
        tmpContainer[i] = this->container[i];
    }
    this->currentSize = newSize;
    this->currentCapacity = newSize * 2;
    this->container = tmpContainer;
}

template<typename T>
void DynamicArray<T>::insert(DynamicArray::iterator position, T value) {
    if (position < this->begin() || position > this->end())
        exit(-1);
    T *tmpContainer = new T[this->currentCapacity *= 2];
    for (auto i = this->begin(); i < position; ++i) {
        tmpContainer[i - this->begin()] = *i;
    }
    tmpContainer[position - this->begin()] = value;
    for (auto i = position; i < this->end(); ++i) {
        tmpContainer[i - this->begin() + 1] = *i;
    }
    delete[] this->container;
    this->currentSize++;
    this->container = tmpContainer;
}

template<typename T>
bool DynamicArray<T>::operator<(const DynamicArray<T> &anotherVector) {
    for (int i = 0; i < std::min(this->currentSize, anotherVector.currentSize); ++i) {
        if (this->container[i] == anotherVector.container[i]) continue;
        if (this->container[i] > anotherVector.container[i]) return false;
        else return true;
    }
    return (this->currentSize < anotherVector.currentSize);
}

template<typename T>
bool DynamicArray<T>::operator>(const DynamicArray<T> &anotherVector) {
    for (int i = 0; i < std::min(this->currentSize, anotherVector.currentSize); ++i) {
        if (this->container[i] == anotherVector.container[i]) continue;
        if (this->container[i] < anotherVector.container[i]) return false;
        else return true;
    }
    return (this->currentSize > anotherVector.currentSize);
}

template<typename T>
DynamicArray<T>::DynamicArray(std::initializer_list<T> list) {
    this->currentSize = list.size();
    this->currentCapacity = list.size() * 2;
    this->container = new T[this->currentCapacity];
    auto itr = list.begin();
    for (int i = 0; i < list.size(); ++i, ++itr) {
        this->container[i] = *itr;
    }
}

// --------------------------------- Iterator implementation ---------------------------------------

template<typename T>
DynamicArray<T>::iterator::iterator() {
    this->pointer = nullptr;
}

template<typename T>
DynamicArray<T>::iterator::iterator(T *pointer) {
    // Make the pointer that the iterator refers to equal to the given pointer
    this->pointer = pointer;
}

template<typename T>
T &DynamicArray<T>::iterator::operator*() const {
    // Return the value that the iterator refers to
    return *pointer;
}

template<typename T>
T *DynamicArray<T>::iterator::operator->() {
    // return the pointer that equal to the iterator
    return pointer;
}

template<typename T>
typename DynamicArray<T>::iterator &DynamicArray<T>::iterator::operator++() {
    // Make the iterator refers to the next position in the memory
    pointer++;
    return *this;
}

template<typename T>
const typename DynamicArray<T>::iterator DynamicArray<T>::iterator::operator++(int) {
    // Postfix increasing iterator will refer to the next position in the memory and will return this new iterator
    iterator tmp = *this;
    ++(*this);
    return tmp;
}

template<typename T>
int DynamicArray<T>::iterator::operator-(DynamicArray::iterator anotherIterator) {
    // Subtract two iterators from each other
    return this->pointer - anotherIterator.pointer;
}

template<typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::iterator::operator+(const int &value) {
    // Make the iterator jumps to the position ( pointer + value )
    pointer += value;
    return *this;
}

template<typename T>
typename DynamicArray<T>::iterator DynamicArray<T>::iterator::operator-(const int &value) {
    this->pointer -= value;
    return *this;
}

// --------------------------------- Reversed iterator implementation ---------------------------------------

template<typename T>
DynamicArray<T>::reverse_iterator::reverse_iterator() {
    this->pointer = nullptr;
}

template<typename T>
DynamicArray<T>::reverse_iterator::reverse_iterator(T *pointer) {
    // Make the pointer that the reversed iterator refers to equal to the given pointer
    this->pointer = pointer;
}

template<typename T>
T &DynamicArray<T>::reverse_iterator::operator*() const {
    // Return the value that the reversed iterator refers to
    return *pointer;
}

template<typename T>
T *DynamicArray<T>::reverse_iterator::operator->() {
    // return the pointer that equal to the reversed iterator
    return pointer;
}

template<typename T>
typename DynamicArray<T>::reverse_iterator &DynamicArray<T>::reverse_iterator::operator++() {
    // Make the reversed iterator refers to the previous position in the memory
    pointer--;
    return *this;
}

template<typename T>
const typename DynamicArray<T>::reverse_iterator DynamicArray<T>::reverse_iterator::operator++(int) {
    // Postfix decreasing reversed iterator will refer to the previous position in the memory
    // and will return this new reversed iterator
    reverse_iterator tmp = *this;
    // ++ operator will make the pointer refers to the previous position in th memory
    ++(*this);
    return tmp;
}

template<typename T>
int DynamicArray<T>::reverse_iterator::operator-(DynamicArray::reverse_iterator anotherReversedIterator) {
    // Subtract two iterators from each other
    return this->pointer - anotherReversedIterator.pointer;
}

template<typename T>
typename DynamicArray<T>::reverse_iterator DynamicArray<T>::reverse_iterator::operator+(const int &value) {
    // Make the reversed iterator jumps to the position ( pointer + value )
    pointer += value;
    return *this;
}