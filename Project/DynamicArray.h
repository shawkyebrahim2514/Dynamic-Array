#ifndef DYNAMIC_CLASS_ARRAY_DYNAMICARRAY_H
#define DYNAMIC_CLASS_ARRAY_DYNAMICARRAY_H

#include <iostream>

template<typename T>
class DynamicArray {
    int currentSize;
    int currentCapacity;
    T *container;

    void enlargeArray();

    void copyArray(const DynamicArray<T> &anotherArray);

    void mergeSort(const int &begin, const int &end, const bool &isIncreasing);

    void mergeRecursion(const int &left, const int &mid, const int &right, const bool &isIncreasing);

public:

    // ------------------------- iterator class --------------------------

    class iterator {
    public:
        iterator();

        explicit iterator(T *pointer);

        T &operator*() const;

        T *operator->();

        iterator &operator++();

        const iterator operator++(int);

        iterator operator+(const int &value);

        int operator-(iterator anotherIterator);

        iterator operator-(const int &value);

        friend bool operator==(const iterator &firstIterator, const iterator &secondIterator) {
            return firstIterator.pointer == secondIterator.pointer;
        };

        friend bool operator!=(const iterator &firstIterator, const iterator &secondIterator) {
            return firstIterator.pointer != secondIterator.pointer;
        };

        friend bool operator<(const iterator &firstIterator, const iterator &secondIterator) {
            return firstIterator.pointer < secondIterator.pointer;
        };

        friend bool operator>(const iterator &firstIterator, const iterator &secondIterator) {
            return firstIterator.pointer > secondIterator.pointer;
        };

        friend bool operator<=(const iterator &firstIterator, const iterator &secondIterator) {
            return firstIterator.pointer < secondIterator.pointer || firstIterator.pointer == secondIterator.pointer;
        };

        friend bool operator>=(const iterator &firstIterator, const iterator &secondIterator) {
            return firstIterator.pointer > secondIterator.pointer || firstIterator.ptr == secondIterator.pointer;
        };
    private:
        T *pointer{};
    };

    iterator begin() { return iterator(container); }

    iterator end() { return iterator(&container[currentSize]); }

    // ------------------------- reverse iterator class --------------------------

    class reverse_iterator {
    public:
        reverse_iterator();

        explicit reverse_iterator(T *pointer);

        T &operator*() const;

        T *operator->();

        reverse_iterator &operator++();

        const reverse_iterator operator++(int);

        int operator-(reverse_iterator anotherReversedIterator);

        reverse_iterator operator+(const int &value);

        friend bool operator==(const reverse_iterator &firstIterator, const reverse_iterator &secondIterator) {
            return firstIterator.pointer == secondIterator.pointer;
        };

        friend bool operator!=(const reverse_iterator &firstIterator, const reverse_iterator &secondIterator) {
            return firstIterator.pointer != secondIterator.pointer;
        };

        friend bool operator<(const reverse_iterator &firstIterator, const reverse_iterator &secondIterator) {
            return firstIterator.pointer < secondIterator.pointer;
        };

        friend bool operator>(const reverse_iterator &firstIterator, const reverse_iterator &secondIterator) {
            return firstIterator.pointer > secondIterator.pointer;
        };

        friend bool operator<=(const reverse_iterator &firstIterator, const reverse_iterator &secondIterator) {
            return firstIterator.pointer < secondIterator.pointer || firstIterator.pointer == secondIterator.pointer;
        };

        friend bool operator>=(const reverse_iterator &firstIterator, const reverse_iterator &secondIterator) {
            return firstIterator.pointer > secondIterator.pointer || firstIterator.pointer == secondIterator.pointer;
        };
    private:
        T *pointer{};
    };

    reverse_iterator rbegin() { return reverse_iterator(&container[currentSize - 1]); }

    reverse_iterator rend() { return reverse_iterator(container - 1); }

    // -------------------- Dynamic array definition ----------------------------

    DynamicArray();

    DynamicArray(DynamicArray &anotherArray);

    DynamicArray(DynamicArray &&anotherArray) noexcept;

    DynamicArray(std::initializer_list<T> list);

    explicit DynamicArray(const int &size);

    DynamicArray(const int &size, const T &initialValue);

    ~DynamicArray();

    int size();

    void clear();

    bool isEmpty();

    void erase(iterator position);

    void erase(const T &position);

    void erase(iterator startPosition, iterator endPosition);

    void resize(int newSize);

    void insert(iterator position, T value);

    T push_back(T value);

    void push_back(DynamicArray &anotherArray);

    void push_back(DynamicArray &&anotherArray);

    void pop_back();

    void sort(const iterator &begin, const iterator &end, const bool &isIncreasing = true);

    iterator lower_bound(const iterator &begin, const iterator &end, const T &value, const bool &isIncreasing = true);

    iterator upper_bound(const iterator &begin, const iterator &end, const T &value, const bool &isIncreasing = true);

    template<typename T1>
    friend void swap(DynamicArray<T1> &firstArray, DynamicArray<T1> &secondArray);

    T &operator[](int index);

    DynamicArray<T> &operator=(const DynamicArray<T> &anotherArray);

    bool operator==(const DynamicArray<T> &anotherArray);

    bool operator!=(const DynamicArray<T> &anotherArray);

    bool operator<(const DynamicArray<T> &anotherVector);

    bool operator>(const DynamicArray<T> &anotherVector);
};

#endif