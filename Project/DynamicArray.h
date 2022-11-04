#ifndef DYNAMIC_CLASS_ARRAY_DYNAMICARRAY_H
#define DYNAMIC_CLASS_ARRAY_DYNAMICARRAY_H
#include <iostream>

template<typename T>
class DynamicArray {
    int elementSize;
    int containerSize;
    T* container;
    void enlargeArray();
    void copyArray(const DynamicArray<T>& anotherArray);
    void mergeSort(const int& begin, const int& end, const bool& isIncreasing);
    void mergeRecursion(const int& left, const int& mid, const int& right, const bool& isIncreasing);

public:
    // ------------------------- iterator definition --------------------------
    class iterator
    {
    public:
        iterator(){};
        explicit iterator(T *pointer);

        T& operator*() const;
        T* operator->();

        // Prefix increment
        iterator& operator++();

        // Postfix increment
        iterator operator++(int);

        // Subtract two iterators
        int operator-(iterator anotherIterator);

        // Shift the iterator by value times
        iterator operator+(const int& value);

        // Check if these two iterators equal to each other
        friend bool operator== (const iterator& firstIterator, const iterator& secondIterator)
            {return firstIterator.iterator_ptr == secondIterator.iterator_ptr;};
        // Check if these two iterators not equal to each other
        friend bool operator!= (const iterator& firstIterator, const iterator& secondIterator)
            {return firstIterator.iterator_ptr != secondIterator.iterator_ptr;};

    private:
        T* iterator_ptr{};
    };
    iterator begin() { return iterator(static_cast<iterator>(&container[0])); }
    iterator end()   { return iterator(&container[elementSize]); }

    // -------------------- reversed iterator definition ------------------------
    class reverse_iterator
    {
    public:
        reverse_iterator(){};
        explicit reverse_iterator(T *pointer);

        T& operator*() const;
        T* operator->();

        // Prefix increment
        reverse_iterator& operator++();

        // Postfix increment
        reverse_iterator operator++(int);

        // Subtract two iterators
        int operator-(reverse_iterator anotherReversedIterator);

        // Shift the iterator by value times
        reverse_iterator operator+(const int& value);

        // Check if these two iterators equal to each other
        friend bool operator== (const reverse_iterator& firstReversedIterator, const reverse_iterator& secondReversedIterator)
            {return firstReversedIterator.reverse_iterator_ptr == secondReversedIterator.reverse_iterator_ptr;};
        // Check if these two iterators not equal to each other
        friend bool operator!= (const reverse_iterator& firstReversedIterator, const reverse_iterator& secondReversedIterator)
            {return firstReversedIterator.reverse_iterator_ptr != secondReversedIterator.reverse_iterator_ptr;};

    private:
        T* reverse_iterator_ptr{};
    };

    reverse_iterator rbegin() { return reverse_iterator(static_cast<reverse_iterator>(&container[elementSize - 1])); }
    reverse_iterator rend()   { return reverse_iterator(container - 1); }

    // -------------------- Dynamic array definition ----------------------------
    DynamicArray();
    DynamicArray(DynamicArray& anotherArray);
    DynamicArray(DynamicArray&& anotherArray) noexcept;
    explicit DynamicArray(const int& size);
    DynamicArray(const int& size, const T& initialValue);
    ~DynamicArray();
    int size();
    void clear();
    bool isEmpty();
    void erase(iterator& itr);
    T append(T value);
    void append(DynamicArray& anotherArray);
    void append(DynamicArray&& anotherArray);
    void pop_back();
    void sort(iterator& begin, iterator& end, const bool& isIncreasing = true);
    void sort(iterator&& begin, iterator&& end, const bool& isIncreasing = true);
    iterator lower_bound(const int& begin, const int& end, const T& value, const bool& isIncreasing = true);
    int upper_bound(const int& begin, const int& end, const T& value, const bool& isIncreasing = true);
    template<typename T1>
    friend void swap(DynamicArray<T1>& firstArray, DynamicArray<T1>& secondArray);
    T & operator[](int index);
    DynamicArray<T>& operator=(const DynamicArray<T>& anotherArray);
    DynamicArray<T>& operator=(DynamicArray<T>&& anotherArray) noexcept;
    bool operator==(const DynamicArray<T>& anotherArray);
    bool operator!=(const DynamicArray<T>& anotherArray);
};

#endif