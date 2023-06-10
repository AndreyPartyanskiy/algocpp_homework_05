// algocpp_homework_05_1.cpp 

#include <iostream>
#include <math.h>
#include <Windows.h>

void print_pyramid(int* arr,int size) 
{
    std::cout << "Исходный массив: ";
    for (int i = 0; i < size; ++i)
    {
        std::cout << arr[i] << " ";
        
    }
    std::cout << std::endl << "Пирамида: " << std::endl;

    std::cout << "0 root " << arr[0] << std::endl;
    for (int i = 1; i < size; ++i) 
    {
        int level = static_cast <int> (log2(i+1));
        std::string element = (i % 2 != 0) ? " left" : " right";
        int parent = ((i - ((element != "left") ? 1 : 2)) / 2);
        std::cout << level << element << "(" << arr[parent] << ") " << arr[i] << std::endl;
    }
    std::cout << std::endl;
}

int main()
{
    system("chcp 1251");
    system("cls");

    int* arr0 = new int [6] {1, 3, 6, 5, 9, 8};
    print_pyramid(arr0, 6);
    delete[] arr0;

    int* arr1 = new int [8] { 94, 67, 18, 44, 55, 12, 6, 42};
    print_pyramid(arr1, 8);
    delete[] arr1;

    int* arr2 = new int [10] {16, 11, 9, 10, 5, 6, 8, 1, 2, 4};
    print_pyramid(arr2, 10);
    delete[] arr2;
}
