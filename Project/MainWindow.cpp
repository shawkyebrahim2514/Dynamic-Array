#include "MainWindow.h"
#include "DynamicArray.cpp"
template<typename T>
DynamicArray<T> myContainer;

void MainWindow::print(const std::string &paragraph) {
    // Print the paragraph parameter in a suitable form
    int width = 200;
    int part = width / 2 - paragraph.size()/2;
    std::cout << std::string(part, '-') << ' ' << paragraph << ' ' << std::string(part, '-') << '\n';
}

void MainWindow::run() {
    show();
    takeType();
    if(continueRunning()) run();
}

void MainWindow::show() {
    print("Enter the type of your array");
    std::cout << "1- Int\n";
    std::cout << "2- Long\n";
    std::cout << "3- Float\n";
    std::cout << "4- Char\n";
    std::cout << "5- String\n";
}

bool MainWindow::continueRunning() {
    std::string input;
    print("Do you want to create another array?");
    std::cout << "Enter y(yes) | n(no): ";
    std::cin >> input;
    if(input == "yes" || input == "y") return true;
    else return false;
}

void MainWindow::takeType() {
    int input;
    std::cout << "Enter your type number here: ";
    std::cin >> input;
    while (input < 1 || input > 5){
        std::cout << "Enter correct choice: ";
        std::cin >> input;
    }
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