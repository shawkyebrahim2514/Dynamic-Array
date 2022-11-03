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
        friend bool operator== (const iterator& a, const iterator& b) {return a.m_ptr == b.m_ptr;};
        // Check if these two iterators not equal to each other
        friend bool operator!= (const iterator& a, const iterator& b) {return a.m_ptr != b.m_ptr;};

    private:
        T* m_ptr{};
    };
    iterator begin() { return iterator(static_cast<iterator>(&container[0])); }
    iterator end()   { return iterator(&container[elementSize]); }

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