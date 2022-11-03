#include "DynamicArray.h"
#include "DynamicArray.cpp"

int main() {
//    MainWindow w;
//    w.run();
    DynamicArray<int> arr;
    arr.append(8);
    arr.append(5);
    arr.append(5);
    arr.append(5);
    arr.append(2);
    arr.append(2);
    arr.append(7);
    for (int i = 0; i < 7; ++i) {
        std::cout << arr[i];
    }
    arr.sort(0,6, false);
    std::cout << '\n';

    for (int i = 0; i < 7; ++i) {
        std::cout << arr[i];
    }
    std::cout << '\n';
    std::cout << arr.lower_bound(0, 6, 5, false);
}

