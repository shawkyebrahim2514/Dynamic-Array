#include "MainWindow.h"
#include "DynamicArray.cpp"
template<typename T>
DynamicArray<T> myContainer;

void MainWindow::run() {
    show();
    takeType();
    std::string input;
    std::cout << "Do you want to create another array? y(yes) | n(no)\n";
    std::cin >> input;
    if(input == "yes" || input == "y") run();
}

void MainWindow::show() {
    std::cout << "Enter the type of your array\n";
    std::cout << "1- int\n";
    std::cout << "2- long\n";
    std::cout << "3- float\n";
    std::cout << "4- char\n";
    std::cout << "5- string\n";
}


void MainWindow::takeType() {
    int input;
    std::cin >> input;
    switch (input) {
        case 1:
            makeArray(myContainer<int>);
            break;
        case 2:
            makeArray(myContainer<long>);
            break;
        case 3:
            makeArray(myContainer<float>);
            break;
        case 4:
            makeArray(myContainer<char>);
            break;
        case 5:
            makeArray(myContainer<std::string>);
            break;
    }
}

template<typename T>
void MainWindow::makeArray(DynamicArray<T> &a) {
    int containerSize;
    std::cout << "Enter the size of the array: ";
    std::cin >> containerSize;
    a.clear();
    for (int i = 1; i <= containerSize; ++i) {
        T input;
        std::cout << "Enter string number " << i << ": ";
        std::cin >> input;
        a.append(input);
    }
    for (int i = 0; i < containerSize; ++i) {
        std::cout << i + 1 << " - " << a[i] << '\n';
    }
}
