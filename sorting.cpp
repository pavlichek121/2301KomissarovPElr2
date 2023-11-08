#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include "sort.h"
#include <iomanip>

#define minrun 32


using namespace std;

int deg(int length, int dig) {
    int i = 0;
    int k = 1;
    while (length > k) {
        k *= dig;
        i++;
    }
    return i;
}


void shellSort2(int(&mas)[lengthMas1], int length) {
    int i;
    int j;
    int temp;
    int step;
    int k= deg(lengthMas1, 2);

    for (step = pow(2, k) - 1; step > 0; step /= 2) {
        for (i = step; i < length; i++) {
            temp = mas[i];
            for (j = i; j >= step; j -= step) {
                if (temp < mas[j - step]) {
                    mas[j] = mas[j - step];
                }
                else {
                    break;
                }
            }
            mas[j] = temp;
        }
    }
}

void shellSort3(int(&mas)[lengthMas1], int length)
{
    int k= deg(lengthMas1, 3);
    int i;
    int j;
    int temp;
    int step;

    for (step = ((pow(3, k) - 1) / 2); step > 0; step /= 3) {
        for (i = step; i < length; i++) {
            temp = mas[i];
            for (j = i; j >= step; j -= step) {
                if (temp < mas[j - step]) {
                    mas[j] = mas[j - step];
                }
                else {
                    break;
                }
            }
            mas[j] = temp;
        }
    }

}

    void shellSort(int(&mas)[lengthMas1], int length, int step) {
        for (int step = length / 2; step > 0; step /= 2) {   //по шагам сортировки
            int i; int j;
            for (int i = step; i < length; i++) {
                int temp = mas[i];
                for (j = i; j >= step; j -= step) {
                    if (temp < mas[j - step]) {
                        mas[j] = mas[j - step];
                    }
                    else {
                        break;
                    }
                }
                mas[j] = temp;
            }
        }
    }

    

    void selectionSort(int(&mas)[lengthMas1], int length) {     //выбором (минимальный в начало)
        for (int index = 0; index < length; index++)
        {
            int minElemIndex = index;       //минимальный индекс

            for (int j = index + 1; j < length; j++)   //находим индекс минимального элемента
                if (mas[minElemIndex] > mas[j])
                    minElemIndex = j;
            int temp = mas[index];  //меняем местами первый неотсортированный и минимальный
            mas[index] = mas[minElemIndex];
            mas[minElemIndex] = temp;
        }
    }

    void insertionSort(int(&mas)[lengthMas1], int left, int right) {     //вставками(опорный на свое место)
        for (int j = left; j < right + 1; j++) {
            int keyNum = mas[j];       //элемент сравнения
            int i = j - 1;        //индекс прохода по отсортированной псол. (идем к началу)
            while ((i >= left) and (mas[i] > keyNum)) { //пока не дошли до начала или сравнение не прервалось
                mas[i + 1] = mas[i];    //сдвигаем элементы вправо, тем самым движемся по масиву
                i--;
            }
            mas[i + 1] = keyNum;        //ставим элемент сравнения на найденную позицию
        }
    }

    void bubbleSort(int(&mas)[lengthMas1], int length) {     //пузырек
        bool swap = true;
        int stable = 0;
        while (swap) {
            swap = false;
            for (int i = 0; i < length - stable - 1; i++)
                if (mas[i] > mas[i + 1]) {  //сравниваем соседние элементы
                    int temp = mas[i];      //перестановка местами
                    mas[i] = mas[i + 1];
                    mas[i + 1] = temp;
                    swap = true;
                }
            stable++;
        }

    }

    void merge(int(&mas)[lengthMas1], int start, int end, int mid) {        //слиянием
        int lengthArray = end - start + 1;  //длина вспомогательного массива
        int right = mid + 1;    //индекс первого эл. правой стороны
        int left = start;     //индекс первого эл. левой стороны
        int indexArray = 0;   //индекс вспомогательного массива
        int* array = new int[lengthArray];


        while ((left <= mid) and (right <= end)) {   //идем по сторонам
            if (mas[left] < mas[right])     //меньший записываем в спомогательный
                array[indexArray++] = mas[left++];
            else array[indexArray++] = mas[right++];

        }
        while (left <= mid)     //записываем оставшийся хвостик массива
            array[indexArray++] = mas[left++];
        while (right <= end)
            array[indexArray++] = mas[right++];
        for (int i = start; i <= end; i++)      //переписываем массив
            mas[i] = array[i - start];

        delete[] array;     //удаляем вспомогательный массив
        array = nullptr;

    }
    void mergeSort(int(&mas)[lengthMas1], int left, int right)
    {     //делим массив пополам, сортируем по половинкам и слияние их
        if (left >= right) {    //пока не останется 1 элемент
            return;
        }
        int mid = left + (right - left) / 2; //находим середину
        mergeSort(mas, left, mid);     //разбиваем левую часть
        mergeSort(mas, mid + 1, right);//разбиваем правую часть
        merge(mas, left, right, mid);  //объединяем
    }

    void quickSort(int(&mas)[lengthMas1], int left, int right) {
        int i = left;           //все эл. меньше опоры слева, больше справа
        int j = right;
        int mid = mas[(left + right) / 2];  //средний элемент(опора)
        do {
            while (mas[i] < mid) //пока элементы сначала меньше опоры
                i++;    //идем по массиву
            while (mas[j] > mid) //пока элементы в конце больше опоры
                j--;    //идем обратно
            if (i <= j) { 
                swap(mas[j], mas[i]);
                
                i++; j--;
            }
        } while (i <= j);   //пока не пройдем массив полностью

        if (j > left) { //сортуруем по кускам
            //"Левый кусок"
            quickSort(mas, left, j);
        }
        if (i < right) {
            //"Првый кусок"
            quickSort(mas, i, right);
        }
    }

    void heapify(int(&mas)[lengthMas1], int length, int i) { //баланс кучи
        int maxElem = i;    //максимальный элемент (родитель)
        int left = 2 * i + 1;   //левое поддерево
        int right = 2 * i + 2;  //правое поддерево
        if ((left < length) and (mas[left] > mas[maxElem])) {
            maxElem = left; //если не вышли за пределы дерева и в левом есть больший эл
        }
        if ((right < length) and (mas[right] > mas[maxElem])) {
            maxElem = right;
        }
        if (maxElem != i) { //если макс. эл сменился, меняем метсами
            int tmp = mas[i];
            mas[i] = mas[maxElem];
            mas[maxElem] = tmp;
            heapify(mas, length, maxElem);  //снова запуск, пока макс не будет в корне
        }
    }
    void heapSort(int(&mas)[lengthMas1], int length) {  //сортировка кучами
        for (int i = length / 2 - 1; i >= 0; i--) {
            heapify(mas, length, i);
        }
        for (int i = length - 1; i >= 0; i--) {
            int temp = mas[0];
            mas[0] = mas[i];
            mas[i] = temp;
            heapify(mas, i, 0);
        }
    }

    int minRun(int length) {
        int r = 0;
        while (length >= minrun) {
            r |= length & 1;
            length >>= 1;
        }
        return length + r;
    }
    void timSort(int(&mas)[lengthMas1], int length) {

        int run = minRun(length);

        for (int left = 0; left < length; left += run) {
            int right = min(left + run - 1, length - 1);
            insertionSort(mas, left, right);//сортируем раны с помощью вставок
        }
        int size = run;
        while (size < length) {     //сортируем раны слиянием
            for (int left = 0; left < length; left += 2 * size) {
                int middle = min(length - 1, left + size - 1);
                int right = min(left + 2 * size - 1, length - 1);
                if (middle < right) {
                    merge(mas, left, right, middle);
                }
            }
            size *= 2;
        }
    }





    void heapsort(int(&mas)[lengthMas1], int end, int begin) {  //сортировка кучами
        for (int i = (end-begin) / 2 - 1; i >= 0; i--) {
            heapify(mas, (end - begin), i);
        }
        for (int i = (end - begin) - 1; i >= 0; i--) {
            int temp = mas[0];
            mas[0] = mas[i];
            mas[i] = temp;
            heapify(mas, i, 0);
        }
    }



    int partition(int(&mas)[lengthMas1], int begin, int end)
    {
        int pivot = mas[end];
        int index = begin;


        for (int i = begin; i < end; i++)
        {
            if (mas[i] <= pivot)
            {
                int temp = mas[i];
                mas[i] = mas[index];
                mas[index] = temp;
                index++;
            }
        }
        int temp = mas[end];
        mas[end] = mas[index];
        mas[index] = temp;
        return index;
    }

    int pivotPartition(int(&mas)[lengthMas1], int begin, int end)
    {
        
        int pivot = mas[begin] + mas[end] + mas[((end - begin) / 2)] - max(mas[begin], mas[end], mas[(end - begin) / 2]) - min(mas[begin], mas[end], mas[(end - begin) / 2]);
        if (mas[begin] == pivot) {
            int temp = mas[begin];
            mas[begin] = mas[end];
            mas[end] = temp;
        }
        else if (mas[(end - begin) / 2] == pivot) {
            int temp = mas[(end - begin) / 2];
            mas[(end - begin) / 2] = mas[end];
            mas[end] = temp;
        }
        return partition(mas, begin, end);
    }

    void introsort(int(&mas)[lengthMas1], int begin, int end, int maxdepth)
    {
       
        if ((end - begin) < 16) {
            insertionSort(mas, begin, end);
        }
      
        else if (maxdepth == 0) {
            heapsort(mas, end, begin);
        }
        else {
      
            int pivot = pivotPartition(mas, begin, end);
            introsort(mas, begin, pivot, maxdepth - 1);
            introsort(mas, pivot+1, end, maxdepth - 1);
        }
    }