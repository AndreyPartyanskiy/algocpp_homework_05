// algocpp_homework_05_2.cpp 

#include <iostream>
#include <math.h>
#include <Windows.h>
#include <string>

std::string print_elem(int* arr, int current_elem, int size) 
{
    std::string sum;
    if (current_elem==0) 
    {

        sum = "0 root " + std::to_string(arr[0]);
    }
    else 
    {
        int level = static_cast <int> (log2(current_elem + 1));
        std::string element = (current_elem % 2 != 0) ? " left" : " right";
        int parent = ((current_elem - ((element != "left") ? 1 : 2)) / 2);
        sum = std::to_string(level) + element + "(" + std::to_string(arr[parent]) + ") " + std::to_string(arr[current_elem]);
    }
    return (sum);
}

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
        std::cout << print_elem(arr,i,size) << std::endl;
    }
}

int main()
{
   
    system("chcp 1251");
    system("cls");

    int size = 6;
    int* arr0 = new int [size] {1, 3, 6, 5, 9, 8};
    print_pyramid(arr0, size);
    std::string command="";
    int curr_element = 0;

    while (command!="exit")
    {
        std::cout << "Вы находитесь здесь: " << print_elem(arr0,curr_element,size) <<std::endl;
        std::cout << "Введите команду: ";
        std::cin >> command;
        if (command == "up" || command == "left" || command == "right" || command == "exit") 
        {
            
            if (command == "up" && curr_element > 0)
            {
                curr_element = ((curr_element - ((curr_element % 2 != 0) ? 1 : 2)) / 2);
                std::cout << "Ok" << std::endl;
            }
            else
            {
                if (command == "up") std::cout << "Ошибка! Отсутствует родитель" << std::endl;
            }

            if (command == "left" && (curr_element * 2 + 1) < size)

            {
                curr_element = (curr_element * 2 + 1);
                std::cout << "Ok" << std::endl;
            }
            else
            {
                if (command == "left") std::cout << "Ошибка! Отсутствует левый потомок " << std::endl;
            }

            if (command == "right" && (curr_element * 2 + 2) < size)
            {
                curr_element = (curr_element * 2 + 2);
                std::cout << "Ok" << std::endl;
            }
            else
            {
                if (command == "right") std::cout << "Ошибка! Отсутствует правый потомок " << std::endl;
            }

        } 
        else
        {
            std::cout << "Такой команды нет в списке. " << print_elem(arr0, curr_element, size) << std::endl;
        }
    }

    delete[] arr0;

    return 0;
}