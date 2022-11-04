#ifndef DYNAMIC_CLASS_ARRAY_DYNAMICARRAY_H
#define DYNAMIC_CLASS_ARRAY_DYNAMICARRAY_H
#include <iostream>

template<typename T>
class DynamicArray {
    int elementSize;
    int containerSize;
    T* container;
    void enlargeArray();
    void eliminate(); // unused
    void copyArray(const DynamicArray<T>& a);
    void mergeSort(const int& begin, const int& end, const bool& isIncreasing);
    void mergeRecursion(const int& left, const int& mid, const int& right, const bool& isIncreasing);

public:
    // ------------------------- iterator definition --------------------------
    class iterator
    {
    public:
        iterator(){};
        explicit iterator(T *pInt);

        T& operator*() const;
        T* operator->();

        // Prefix increment
        iterator& operator++();

        // Postfix increment
        iterator operator++(int);

        // Subtract two iterators
        int operator-(iterator another);

        // Shift the iterator by value times
        iterator operator+(const int& value);

        // Check if these two iterators equal to each other
        friend bool operator== (const iterator& a, const iterator& b) {return a.iterator_ptr == b.iterator_ptr;};
        // Check if these two iterators not equal to each other
        friend bool operator!= (const iterator& a, const iterator& b) {return a.iterator_ptr != b.iterator_ptr;};

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
        explicit reverse_iterator(T *pInt);

        T& operator*() const;
        T* operator->();

        // Prefix increment
        reverse_iterator& operator++();

        // Postfix increment
        reverse_iterator operator++(int);

        // Subtract two iterators
        int operator-(reverse_iterator another);

        // Shift the iterator by value times
        reverse_iterator operator+(const int& value);

        // Check if these two iterators equal to each other
        friend bool operator== (const reverse_iterator& a, const reverse_iterator& b) {return a.reverse_iterator_ptr == b.reverse_iterator_ptr;};
        // Check if these two iterators not equal to each other
        friend bool operator!= (const reverse_iterator& a, const reverse_iterator& b) {return a.reverse_iterator_ptr != b.reverse_iterator_ptr;};

    private:
        T* reverse_iterator_ptr{};
    };

    reverse_iterator rbegin() { return reverse_iterator(static_cast<reverse_iterator>(&container[elementSize - 1])); }
    reverse_iterator rend()   { return reverse_iterator(container - 1); }

    // -------------------- Dynamic array definition ----------------------------
    DynamicArray();
    DynamicArray(DynamicArray& a);
    DynamicArray(DynamicArray&& a) noexcept;
    explicit DynamicArray(const int& size);
    DynamicArray(const int& size, const T& initialValue);
    ~DynamicArray();
    T & operator[](int k);
    DynamicArray<T>& operator=(const DynamicArray<T>& a);
    bool operator!=(const DynamicArray<T>& a);
    DynamicArray<T>& operator=(DynamicArray<T>&& a) noexcept;
    T append(T a);
    void append(DynamicArray& a);
    void append(DynamicArray&& a);
    void pop_back();
    int size();
    void clear();
    void sort(iterator& begin, iterator& end, const bool& isIncreasing = true);
    void sort(iterator&& begin, iterator&& end, const bool& isIncreasing = true);
    iterator lower_bound(const int& begin, const int& end, const T& value, const bool& isIncreasing = true);
    int upper_bound(const int& begin, const int& end, const T& value, const bool& isIncreasing = true);
    template<typename T1>
    friend void swap(DynamicArray<T1>& a, DynamicArray<T1>& b);
    bool isEmpty();
    void erase(iterator& itr);
};

#endif