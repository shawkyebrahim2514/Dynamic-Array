#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include <vector>

int main() {
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
DynamicArray<int> arr;
arr.append(1);
arr.append(2);
arr.append(3);
arr.append(4);
arr.append(5);
//for(auto& val : arr) std::cout << val << ' ';
//std::cout << '\n';
//auto itr = arr.begin();
//arr.erase(itr);
//    for(auto& val : arr) std::cout << val << ' ';
//    std::cout << '\n';
//    itr = arr.begin();
//    arr.erase(itr);
//    for(auto& val : arr) std::cout << val << ' ';
//    std::cout << '\n';
//    itr = arr.begin();
//    arr.erase(itr);
//    for(auto& val : arr) std::cout << val << ' ';
//    std::cout << '\n';
auto begin = arr.begin(), end = arr.end();
arr.sort(arr.begin(), arr.end());
//auto itr = arr.begin();
//std::cout << *(itr+3);
}

