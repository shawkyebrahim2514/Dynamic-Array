#include "DynamicArray.h"
#include "DynamicArray.cpp"
#include <vector>

int main() {
    DynamicArray<int> vector1{1, 2, 3, 4, 5};
    DynamicArray<int> vector2(6, 12);
    DynamicArray<int> vector3(vector2);
    DynamicArray<int> vector4(DynamicArray<int>{7, 8, 9, 10, 11});
    DynamicArray<int> vector5 = vector4;
    DynamicArray<int> vector6 = DynamicArray<int>{10, 20, 30, 40, 50};
    std::cout << "vector1: ";
    for (auto &val: vector1) {
        std::cout << val << ' ';
    }
    std::cout << '\n';
    std::cout << "vector2: ";
    for (auto &val: vector2) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "vector3: ";
    for (auto &val: vector3) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "vector4: ";
    for (auto &val: vector4) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "vector5: ";
    for (auto &val: vector5) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "vector6: ";
    for (auto &val: vector6) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "-------------------------\n";
    std::cout << "Is vector1 > vector4: " << (vector1 > vector4) << '\n';
    std::cout << "Is vector1 < vector4: " << (vector1 < vector4) << '\n';
    std::cout << "Is vector1 == vector4: " << (vector1 == vector4) << '\n';
    std::cout << "-------------------------\n";
    std::cout << "Is vector4 > vector5: " << (vector4 > vector5) << '\n';
    std::cout << "Is vector4 < vector5: " << (vector4 < vector5) << '\n';
    std::cout << "Is vector4 == vector5: " << (vector4 == vector5) << '\n';
    std::cout << "-------------------------\n";
    std::cout << "Is vector6 > vector5: " << (vector6 > vector5) << '\n';
    std::cout << "Is vector6 < vector5: " << (vector6 < vector5) << '\n';
    std::cout << "Is vector6 == vector5: " << (vector6 == vector5) << '\n';
    std::cout << "-------------------------\n";
    std::cout << "vector6: ";
    for (auto &val: vector6) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "Replace the 2nd element in vector6 with (70): ";
    vector6[1] = 70;
    for (auto &val: vector6) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "Erasing position 3 from vector6: ";
    vector6.erase(vector6.begin() + 2);
    for (auto &val: vector6) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "-------------------------\n";
    std::cout << "vector4: ";
    for (auto &val: vector4) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "Erasing from position 2 to position 4 from vector4: ";
    vector4.erase(vector4.begin() + 1, vector4.end() - 1);
    for (auto &val: vector4) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "Inserting (100) to the begging of vector4: ";
    vector4.insert(vector4.begin(), 100);
    for (auto &val: vector4) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "-------------------------\n";
    std::cout << "vector6: ";
    for (auto &val: vector6) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "Resize vector6 to 3 elements only: ";
    vector6.resize(3);
    for (auto &val: vector6) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "Resize vector6 to 10 elements only: ";
    vector6.resize(10);
    for (auto &val: vector6) std::cout << val << ' ';
    std::cout << '\n';
    std::cout << "-------------------------\n";
}

