# Dynamic Array
 Dynamic array with cpp

## Features
* Takes a type parameter to decide the type it will contain.
* Keeps track of its current size.
*	Initialization with different ways:
    * Can be empty
    * Can have a fixed size (without a given value, elements in this case will have a garbage values)
    * Can have a fixed size with a certain value
    * Can copy another DynamicArray elements (lvalue or rvalue)
    * Can be initialized with a given list
* Can use random access brackets []
* It has a destructor that frees any heap storage allocated by the smart array
*	Can copy an arrays to another array by using the assignment operator (=)
* Overload the comparison operators (==, !=, <, >, <=, >=)
* It has a method size() that returns the number of elements in the array.
* It has a method clear() that clear all elements in the array
* It has a method isEmpty() that checks if the array is empty or not
* It has a method push_back(value:T) that pushes element to the back of an array
* It has a method push_back(anotherArray:DynamicArray) that pushes another dynamic array elements to the back of our dynamic array
* It has a method pop_back() that popps the last element from this dynamic array
* It has a method sort(begin:iterator, end:iterator, isIncreasing:boolean) that sorts the array from begin iterator to the end iterator
* It has a method lower_bound(begin:iterator, end:iterator, value:T, isIncreasing:boolean)
* It has a method upper_bound(begin:iterator, end:iterator, value:T, isIncreasing:boolean)
* It has a method swap(firstArray:DynamicArray, secondArray:DynamicArray)
* It has a method erase(value:T) that erases the first element that has a given value
* It has a method erase(position:iterator) that erases a given position iterator
* It has a method erase(startPosition:iterator, endPosition:iterator) that erases a range of elements

## Details

### Can store any type of data
> Takes a type parameter to decide the type it will contain.

```cpp
  DynamicArray<int> array;
  DynamicArray<float> array;
  DynamicArray<char> array;
  DynamicArray<char> array;
```

### Different ways of Initialization

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

> Initialize the array with a given list

```cpp 
  DynamicArray<int> array1 {1,2,3,4,5};
```

### General method in this DynamicArray

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

> Overload the comparison operators (==, !=, <, >, <=, >=)

```
  Two array are equal if they have the same size and the same elements in each position
  The first array is greater than the second array if the first unequal element are greater in the first array or if all elements are equal, then the bigger array in size is the biggest one
```

> It has a method size() that returns the number of elements in the array.

```cpp
  DynamicArray<int> array1(5,20);
  std::cout << array1.size();
```

> method push_back() methods

* push_back(value:T) that pushes element to the back of an array
* push_back(anotherArray:DynamicArray) that pushes another dynamic array elements to the back of our dynamic array

```cpp
  DynamicArray<int> array1(5,20);
  DynamicArray<int> array2(15,3);
  array1.push_back(500); // append a value
  array1.push_back(array2); // append another array
```

> It has a method pop_back() that pop back an element from an array

```cpp
  DynamicArray<int> array1(5,20);
  array1.push_back(500);
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

> It has a method sort() that sort the array decreasing or increasing using `merge sort algorithm

 * Takes three parameters (begin:iterator, end:iterator, isincreasing:boolean) isIncreasing boolean has default value = true
 * It takes two iterator, the first is the beginning of the sort, and the second is the end of the sort
 * the third parameter has default value = true (sort by increasing order)
    * can be = false (sort by decreasing order)

```cpp
  DynamicArray<int> array1;
  array1.push_back(5);
  array1.push_back(2);
  array1.push_back(3);
  array1.push_back(8);
  array1.push_back(4);
  array1.sort(array1.begin(), array1.end()); // sort the array in increasing order
  array1.sort(array1.begin(), array1.end(), true); // as the above code, third parameter its default value = true
  array1.sort(array1.begin(), array1.end(), false); // sort the array in decreasing order
```

> It has a method lower_bound() and upper_bound()

 * Takes four parameters (begin:iterator, end:iterator, value:T, isincreasing:boolean) isIncreasing boolean has default value = true
 * It takes two iterator, the first is the beginning of the sort, and the second is the end of the sort
 * The third parameter is the value that you want to use lower_bound() or upper_bound() on
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
  array1.push_back(5);
  array1.push_back(2);
  array1.push_back(3);
  array1.push_back(8);
  array1.push_back(4);
  array1.sort(array1.begin(), array1.end());
  std::cout << *array1.lower_bound(array1.begin(), array1.end(), 7); // use lower_bound() method with value = 7, and by default the fourth parameter = true
```

> It has a method erase() that erases an iterator or a value (first value from left) in the array

* erase(value:T) it erases the first position that has the given value
* erase(position:iterator) it erases a given position iterator from the array
* erase(startPosition:iterator, endPosition:iterator) it erases a range of elements from startPosition iterator to the endPosition iterator

```cpp
  DynamicArray<int> array1;
  array1.push_back(5);
  array1.push_back(2);
  array1.push_back(3);
  array1.push_back(8);
  array1.push_back(4);
  array1.erase(3); // erase value 3
  array1.erase(array1.begin()); // erase the iterator
```

> swap(firstArray:DynamicArrat, secondArray:DynamicArray) 

```cpp
  DynamicArray<int> array1 {1,2,3,4,5};
  DynamicArray<int> array2 {100,200,300,400,500};
  for(auto& val : array1) std::cout << val << ' '; // 1 2 3 4 5
  std::cout << '\n';
  for(auto& val : array2) std::cout << val << ' '; // 100 200 300 400 500
  std::cout << '\n';
  swap(array1, array2);
  for(auto& val : array1) std::cout << val << ' '; // 100 200 300 400 500
  std::cout << '\n';
  for(auto& val : array2) std::cout << val << ' '; // 1 2 3 4 5
  std::cout << '\n';
```

## Program to test this Dynamic array

> I created a program to test this dynamic array with differnet datatype

![image](https://user-images.githubusercontent.com/101745968/194588324-3b1b450a-fafd-4d1b-9da3-1c2644619287.png)

![image](https://user-images.githubusercontent.com/101745968/194588696-8e021bdc-383b-4a3d-9859-9a6e02684b69.png)
