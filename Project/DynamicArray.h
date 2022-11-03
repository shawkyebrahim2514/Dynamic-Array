#ifndef DYNAMIC_CLASS_ARRAY_DYNAMICARRAY_H
#define DYNAMIC_CLASS_ARRAY_DYNAMICARRAY_H

template<typename T>
class DynamicArray {
    int elementSize;
    int containerSize;
    T* container;
    void enlargeArray();
    void copyArray(const DynamicArray<T>& a);
    void mergeSort(const int& begin, const int& end, const bool& isIncreasing);
    void mergeRecursion(const int& left, const int& mid, const int& right, const bool& isIncreasing);

public:
    DynamicArray();
    DynamicArray(const DynamicArray& a);
    DynamicArray(DynamicArray&& a) noexcept;
    ~DynamicArray();
    int size();
    T & operator[](int k);
    DynamicArray<T>& operator=(const DynamicArray<T>& a);
    DynamicArray<T>& operator=(DynamicArray<T>&& a) noexcept;
    T append(const T& a);
    void pop_back();
    void clear();
    void sort(const int& begin, const int& end, const bool& isIncreasing = true);
    int lower_bound(const int& begin, const int& end, const T& value, const bool& isIncreasing = true);
    int upper_bound(const int& begin, const int& end, const T& value, const bool& isIncreasing = true);

};


#endif
