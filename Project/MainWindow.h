#ifndef DYNAMIC_CLASS_ARRAY_MAINWINDOW_H
#define DYNAMIC_CLASS_ARRAY_MAINWINDOW_H
#include "DynamicArray.h"
#include <iostream>

class MainWindow {
    template<typename T>
    void makeArray(DynamicArray<T>& a);
    void takeType();
    void show();
    void print(const std::string &paragraph);
    bool continueRunning();
public:
    void run();
};


#endif
