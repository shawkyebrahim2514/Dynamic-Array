# Dynamic Array
 Dynamic array with cpp

## Featurs
* Takes a type parameter to decide the type it will contain.
* Keeps track of its current size.
*	A copy constructor that initialize the array with another array (Lvalue or Rvalue)
*	Initialize the array with a size or with a size and values
* Can use random access brackets [] to access an existing element in the array
* It has a destructor that frees any heap storage allocated by the smart array
*	Can copy an arrays to another array by using the assignment operator (=) (Lvalue or Rvalue)
* Overload the comparison operators (==) and (!=)
* It has a method size() that returns the number of elements in the array.
* It has a method append() that append element to the back of an array
* It has a method append() that append another array to the back of an array
* It has a method pop_back() that pop back an element from an array
* It has a method clear() that clear all elements in the array
* It has a method isEmpty() that checks if the array is empty or not
* It has a method sort() that sort the array decreasing or increasing using `merge sort algorithm`
* It has a method lower_bound() and upper_bound()
* It has a method swap() that swaps between two array
* It has a method erase() that erases an iterator or a value (first value from left) in the array

## Details
> Takes a type parameter to decide the type it will contain.

```cpp
  DynamicArray<int> array;
  DynamicArray<float> array;
  DynamicArray<char> array;
  DynamicArray<char> array;
```

> A copy constructor that initialize the array with another array

```cpp
  DynamicArray<int> array1 (array2); // with rvalue
  DynamicArray<int> array3 (DynamicArray<int>(5,20)); // with lvalue
```

> Initialize the array with a size or with a size and values

```cpp
  // take two parameters, the first is the size of the array, the second is the initial value of the array elements 
  DynamicArray<int> array1(5); // with size of 5
  DynamicArray<int> array2(5, 20); // with size of 5 and all these 5 elements with value = 20
```

> Can use random access brackets [] to access an existing element in the array

```cpp
  DynamicArray<int> array1(5);
  std::cout << array1[4];
  std::cout << array1[0];
  array1[2] = 200;
```

> Can copy an arrays to another array by using the assignment operator (=)

```cpp
  DynamicArray<int> array1(5,20);
  DynamicArray<int> array2(2,1000);
  array1 = array2; // with lvalue
  array1 = DynamicArray<int>(80,40); // with rvalue
```

> Overload the comparison operators (==) and (!=)
```
  Two arrays are equal if they refer to the same memory locations
  Two array aren’t equal if they don’t refer to the same memory locations
```

> It has a method size() that returns the number of elements in the array.

```cpp
  DynamicArray<int> array1(5,20);
  std::cout << array1.size();
```

> It has a method append() that append element or another array to the back of an array

```cpp
  DynamicArray<int> array1(5,20);
  DynamicArray<int> array2(15,3);
  array1.append(500); // append a value
  array1.append(array2); // append another array
```
> It has a method pop_back() that pop back an element from an array
```cpp
  DynamicArray<int> array1(5,20);
  array1.append(500);
  array1.pop_back();
```

> It has a method clear() that clear all elements in the array

```cpp
  DynamicArray<int> array1(5,20);
  array1.clear(); // clear all elements in the array, after that its size will be 0
```

> It has a method isEmpty() that clear all elements in the array

```cpp
  DynamicArray<int> array1(5,20);
  std::cout << array1.isEmpty(); // return 1 if the array is empty, and 0 if the array has at least one element
```

> It has a method sort() that sort the array decreasing or increasing using `merge sort algorithm`
 * Takes three parameters (begin iterator, end iterator, isincreasing boolean) isIncreasing boolean has default value = true
 * It takes two iterator, the first is the beginning of the sort, and the second is the end of the sort
 * the third parameter has default value = true (sort by increasing order)
    * can be = false (sort by decreasing order)

```cpp
  DynamicArray<int> array1;
  array1.append(5);
  array1.append(2);
  array1.append(3);
  array1.append(8);
  array1.append(4);
  array1.sort(array1.begin(), array1.end()); // sort the array in increasing order
  array1.sort(array1.begin(), array1.end(), true); // as the above code, third parameter its default value = true
  array1.sort(array1.begin(), array1.end(), false); // sort the array in decreasing order
```

> It has a method lower_bound() and upper_bound()
 * Takes four parameters (begin iterator, end iterator, value, isincreasing boolean) isIncreasing boolean has default value = true
 * It takes two iterator, the first is the beginning of the sort, and the second is the end of the sort
 * The third parameter is the value that tou want to use lower_bound() or upper_bound() on
 * the fourth parameter has default value = true (the array is in increasing order)
 * It returns an iterator that refers to the given value
 * It return an iterator that refers to the end of the array if the lower_bound() or upper_bound() methods doesn't find any element that satisfay its role
 * in lower_bound() method:
    * if the array is in increasing order, it returns iterator that refers to the first index that its value is greater than or equal to the given value in the parameter
    * if the array is in decreasing order, it returns iterator that refers to the first index that its value is smaller than or equal to the given value in the parameter
 * in upper_bound() method:
    * if the array is in increasing order, it returns iterator that refers to the first index that its value is greater than the given value in the parameter
    * if the array is in decreasing order, it returns iterator that refers to the first index that its value is smaller than the given value in the parameter
    
```cpp
  DynamicArray<int> array1;
  array1.append(5);
  array1.append(2);
  array1.append(3);
  array1.append(8);
  array1.append(4);
  array1.sort(array1.begin(), array1.end());
  std::cout << *array1.lower_bound(array1.begin(), array1.end(), 7); // use lower_bound() method with value = 7, and by default the fourth parameter = true
```

> It has a method erase() that erases an iterator or a value (first value from left) in the array
 * Can erase an iterator direct
 * Or erase an element (first element equal to the fiven value from left)

```cpp
  DynamicArray<int> array1;
  array1.append(5);
  array1.append(2);
  array1.append(3);
  array1.append(8);
  array1.append(4);
  array1.erase(3); // erase value 3
  array1.erase(array1.begin()); // erase the iterator
```





## Program to test this Dynamic array
> I created a program to test this dynamic array with differnet datatype

![image](https://user-images.githubusercontent.com/101745968/194588324-3b1b450a-fafd-4d1b-9da3-1c2644619287.png)

![image](https://user-images.githubusercontent.com/101745968/194588696-8e021bdc-383b-4a3d-9859-9a6e02684b69.png)
