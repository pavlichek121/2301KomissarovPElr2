#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#include "sort.h"
#define LANGUAGE 1251


using namespace std;


int main()
{
    SetConsoleCP(LANGUAGE);
    SetConsoleOutputCP(LANGUAGE);
    clock_t startTime, endTime;
   
    int choice;
    int mas[lengthMas1];
    int length = lengthMas1;
    int maxdepth = log(length) * 2;
    do {
    cout << endl << "-----------------------------------------" << endl;
    cout << "Выберите массив для сортировки: " << endl;
    cout << "1. Отсортированный массив" << endl;
    cout << "2. Почти отсортированный массив" << endl;
    cout << "3. Обратно отсортированный массив" << endl;
    cout << "4. Массив без доп данных" << endl;
    cout << "0. Выйти" << endl;
    cout << "-----------------------------------------" << endl;
    cin >> choice;
 
    switch (choice)
    {
    case 1:
       sortedArray(mas);
        break;
    case 2:
        almostSortedArray(mas);
        break;
    case 3:
        backSortedArray(mas);
        break;

    case 4:
        randomSortedArray(mas);
        break;
    }
    if (choice != 0) {
        do {
            cout << endl << "-----------------------------------------" << endl;
            cout << "Выберите сортировку: " << endl;
            cout << "1. Сортировка выбором" << endl;
            cout << "2. Сортировка вставками" << endl;
            cout << "3. Сортировка пузырьком" << endl;
            cout << "4. Сортировка слиянием" << endl;
            cout << "5. Быстрая сортировка" << endl;
            cout << "6. Сортировка Шелла" << endl;
            cout << "7. Пирамидальная сортировка" << endl;
            cout << "8. Timsort" << endl;
            cout << "9. IntroSort" << endl;
            cout << endl << "10. Вывести массив на экран" << endl;
            cout << "-----------------------------------------" << endl;
            cin >> choice;
            startTime = clock();
            switch (choice)
            {
            case 1:
               selectionSort(mas, length);
                break;
            case 2:
                insertionSort(mas, 0, length);
                break;
            case 3:
                bubbleSort(mas, length);
                break;
            case 4:
                mergeSort(mas, 0, length - 1);
                break;
            case 5:
                quickSort(mas, 0, length - 1);
                break;
            case 6:
                endTime = clock();
                cout << endl << "-----------------------------------------" << endl;
                cout <<  "Выберите шаг сортировки Шелла:"<<endl;
                cout << "1. Сортировка делением на 2" << endl << "2. По степени 2" << endl << "3. По степени 3";
                cout << endl << "-----------------------------------------" << endl;
                int choice2;
                cin >> choice2;
                startTime = clock();
                switch (choice2)
                {
                case 1:
                    shellSort(mas, length, length / 2);
                    break;
                case 2:
                    shellSort2(mas, length);
                    break;
                case 3:
                    shellSort3(mas, length);
                    break;
                default:
                    break;
                }
            
                break;
            case 7:
                heapSort(mas, length);
                break;
            case 8:
                timSort(mas, length);
                break;
            case 9:
                
                introsort(mas, 0, length-1, maxdepth);
                break;
            case 10:
                cout << endl << "Массив до сортировки: " << endl;
                printArray(mas);
                break;

            }

            endTime = clock();
            cout <<endl<< "Время выполнения (в мс): " << endTime - startTime << endl;
        } while (choice == 10);
        
        cout << endl << "Вывести массив после сортировки? 1-yes, 2-no" << endl;
        cin >> choice;
        if (choice == 1) {
            cout << endl << "Массив после сортировки: " << endl;
            printArray(mas);
        } 
     
    }
    } while (choice != 0);
    return 0;
    _getch();
}