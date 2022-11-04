#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include <vector>

int main() {
    DynamicArray<int> array1, array2(55, 55);
    array1.append(5);
    array1.append(2);
    array1.append(3);
    array1.append(3);
    array1.append(8);
    array1.append(4);
    array1.erase(12);
    array1.append(DynamicArray<int>(20,10));
    array1 = DynamicArray<int>(50,20);
    array1.sort(array1.begin(), array1.end());
//    array1.erase(array1.begin());
for(auto val : array1) std::cout << val << ' ';
std::cout << '\n';
std::cout << *array1.lower_bound(array1.begin(), array1.end(), 7);

//    MainWindow w;
//    w.run();
//    DynamicArray<int> arr(6,2), arr2(3, 15), arr3(DynamicArray<int>(5,66));
//    for(auto& val : arr) std::cout << val << ' ';
//    std::cout << '\n';
//    for(auto& val : arr2) std::cout << val << ' ';
//    std::cout << '\n';
//    arr.append(DynamicArray<int>(10, 1000));
//    swap(arr, arr3);
//    for(auto& val : arr) std::cout << val << ' ';
//    std::cout << '\n';
//    for(auto& val : arr2) std::cout << val << ' ';
//    std::cout << '\n';
//    for(auto& val : arr3) std::cout << val << ' ';
//    std::cout << '\n';
//    arr.append(8);
//    arr.append(5);
//    arr.append(5);
//    arr.append(5);
//    arr.append(2);
//    arr.append(2);
//    arr.append(7);
//    arr.sort(0, 6);

//    for (int i = 0; i < 7; ++i) {
//        std::cout << arr[i];
//    }
//    arr.sort(0,6, false);
//    std::cout << '\n';
//
//    for (int i = 0; i < 7; ++i) {
//        std::cout << arr[i];
//    }
//    std::cout << '\n';
//    std::cout << arr.lower_bound(0, 6, 5, false);
//DynamicArray<int> arr;
//arr.append(1);
//arr.append(2);
//arr.append(3);
//arr.append(4);
//arr.append(5);
////for(auto& val : arr) std::cout << val << ' ';
////std::cout << '\n';
////auto itr = arr.begin();
////arr.erase(itr);
////    for(auto& val : arr) std::cout << val << ' ';
////    std::cout << '\n';
////    itr = arr.begin();
////    arr.erase(itr);
////    for(auto& val : arr) std::cout << val << ' ';
////    std::cout << '\n';
////    itr = arr.begin();
////    arr.erase(itr);
////    for(auto& val : arr) std::cout << val << ' ';
////    std::cout << '\n';
//for(auto& val : arr) std::cout << val << ' ';
//std::cout << '\n';
//for(auto itr = arr.rbegin(); itr != arr.rend(); itr ++){
//    std::cout << *itr << ' ';
//}
//std::cout << '\n';
//auto itr2 = arr.rbegin();
//std::cout << *itr2;
//std::cout << '\n';
//arr.sort(arr.begin(), arr.end());
//auto itr = arr.begin();
//std::cout << *itr;
//std::vector<int> vec;
//DynamicArray<int>::iterator b;
}

