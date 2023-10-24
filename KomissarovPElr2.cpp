#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include <time.h>
#define LANGUAGE 1251
#define minrun 32
const int lengthMas = 1000;

using namespace std;

void sortedArray(int(&mas)[lengthMas]) {
    for (int i = 0; i < lengthMas; i++) {
        mas[i] = i;
    }
}
void almostSortedArray(int(&mas)[lengthMas]) {
    int j = 0;
    for (int i = 19; i >= 0; i--) {

        mas[j] = i;
        j++;
    }
    for (int i = 20; i < lengthMas; i++) {
        mas[i] = i;
    }
}
void backSortedArray(int(&mas)[lengthMas]) {

    for (int i = 0; i < lengthMas; i++) {
        mas[i] = lengthMas - 1 - i;
    }
}
void randomSortedArray(int(&mas)[lengthMas]) {

    for (int i = 0; i < lengthMas; i++) {
        int j = rand() % (lengthMas);
        mas[i] = j;
    }
}
void printArray(int(&mas)[lengthMas]) {

    cout << "[";
    for (int i = 0; i < lengthMas; i++) {
        if (i != lengthMas - 1)
            cout << mas[i] << ", ";

        else cout << mas[i];
    }
    cout << "]" << endl;
}


void shellSort(int(&mas)[lengthMas], int length, int step) {
    for (int step = length / 2; step > 0; step /= 2)
        for (int i = step; i < length; i++)
            for (int j = i - step; j >= 0; j -= step)
                if (mas[j] > mas[j + step]) {
                    int temp = mas[j];
                    mas[j] = mas[j + step];
                    mas[j + step] = temp;
                }
}


void selectionSort(int(&mas)[lengthMas], int length) {
    for (int i = 0; i < length; i++)
    {
        int minIndex = i;

        for (int j = i + 1; j < length; j++)
            if (mas[minIndex] > mas[j])
                minIndex = j;
        int temp = mas[i];
        mas[i] = mas[minIndex];
        mas[minIndex] = temp;
    }
}


void insertionSort(int(&mas)[lengthMas], int left, int right) {
    for (int j = left; j < right + 1; j++) {
        int keyNum = mas[j];       //элемент сравнения
        int i = j - 1;        //переменная для сравнения (идем к началу)
        while ((i >= left) and (mas[i] > keyNum)) { //пока не дошли до начала или сравнение не прервалось
            mas[i + 1] = mas[i];    //сдвигаем текущий элемент вправо, тем самым движемся по масиву
            i--;
        }
        mas[i + 1] = keyNum;        //ставим элемент сравнения на найденную позицию
    }
}

void bubbleSort(int(&mas)[lengthMas], int length) {
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


void merge(int(&mas)[lengthMas], int start, int end, int mid) {
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

    delete[] array;     //удаляем массив
    array = nullptr;

}
void mergeSort(int(&mas)[lengthMas], int left, int right)
{
    if (left >= right) {    //пока не останется 1 элемент
        return;
    }
    int mid = left + (right - left) / 2; //находим середину
    mergeSort(mas, left, mid);     //разбиваем левую часть
    mergeSort(mas, mid + 1, right);//разбиваем правую часть
    merge(mas, left, right, mid);  //объединяем
}

void quickSort(int(&mas)[lengthMas], int left, int right) {
    int i = left;
    int j = right;
    int mid = mas[(left + right) / 2];
    do {
        while (mas[i] < mid)
            i++;
        while (mas[j] > mid)
            j--;
        if (i <= j) {
            int temp = mas[j];
            mas[j] = mas[i];
            mas[i] = temp;
            i++; j--;
        }
    } while (i <= j);

    if (j > left) {
        //"Левый кусок"
        quickSort(mas, left, j);
    }
    if (i < right) {
        //"Првый кусок"
        quickSort(mas, i, right);
    }
}

void heapify(int(&mas)[lengthMas], int length, int i) {
    int maxEl = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;
    if ((left < length) and (mas[left] > mas[maxEl])) {
        maxEl = left;
    }
    if ((right < length) and (mas[right] > mas[maxEl])) {
        maxEl = right;
    }
    if (maxEl != i) {
        int tmp = mas[i];
        mas[i] = mas[maxEl];
        mas[maxEl] = tmp;
        heapify(mas, length, maxEl);
    }
}
void heapSort(int(&mas)[lengthMas], int length) {
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

void timSort(int(&mas)[lengthMas], int length) {

    int run = minRun(length);

    for (int left = 0; left < length; left += run) {
        int right = min(left + run - 1, length - 1);
        insertionSort(mas, left, right);
    }
    int size = run;
    //printArray(mas);
    while (size < length) {
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

int partition(int(&mas)[lengthMas], int start, int end) {
    int pivot = mas[end];

    int index = start - 1;
    for (int j = start; j <= end - 1; j++) {
        if (mas[j] < pivot) {
            index++;
            swap(mas[index], mas[j]);
        }
    }
    index++;
    swap(mas[index], mas[end]);

    return index;
}

void IntroSort(int(&mas)[lengthMas], int length) {
    int partSize = partition(mas, 0, length-1);
    if (partSize < 16) {
        insertionSort(mas, 0, length-1);
    }
    else if (partSize > (2 * log(length))) {
        heapSort(mas, length);
    }
    else {
        quickSort(mas, 0, length - 1);
    }
}

int main()
{
    SetConsoleCP(LANGUAGE);
    SetConsoleOutputCP(LANGUAGE);
    clock_t startTime, endTime;
    int choice;
    int masSize = 100;
    int mas[lengthMas];
    int length = lengthMas;
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
    // cout << endl << "Массив до сортировки: " << endl;
    // printArray(mas);

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
        shellSort(mas, length, length / 2);
        break;

    case 7:
        heapSort(mas, length);
        break;

    case 8:
        timSort(mas, length);
        break;

    case 9:
        IntroSort(mas, length);
        break;


    }

    endTime = clock();
    cout << endl << "Массив после сортировки: " << endl;
   // printArray(mas);
    cout << "Время выполнения: " << endTime - startTime << endl;
    } while (choice != 0);
    return 0;
    _getch();
}