#ifndef DYNAMIC_CLASS_ARRAY_DYNAMICARRAY_H
#define DYNAMIC_CLASS_ARRAY_DYNAMICARRAY_H

template<typename T>
class DynamicArray {
    int elementSize;
    int containerSize;
    T* container;
    void enlargeArray();
    void copyArray(const DynamicArray<T>& a);
public:
    DynamicArray();
    DynamicArray(const DynamicArray& a);
    ~DynamicArray();
    int size();
    T & operator[](int k);
    DynamicArray<T>& operator=(const DynamicArray<T>& a);
    void append(const T& a);
    void clear();
};


#endif //DYNAMIC_CLASS_ARRAY_DYNAMICARRAY_H
