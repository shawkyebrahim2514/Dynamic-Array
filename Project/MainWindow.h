#ifndef DYNAMIC_CLASS_ARRAY_MAINWINDOW_H
#define DYNAMIC_CLASS_ARRAY_MAINWINDOW_H
#include "DynamicArray.h"
#include <iostream>
class MainWindow {
    template<typename T>
    void makeArray(DynamicArray<T>& a);
    void takeType();
    void show();
public:
    void run();
};


#endif //DYNAMIC_CLASS_ARRAY_MAINWINDOW_H
