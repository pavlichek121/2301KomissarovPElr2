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
        for (int step = length / 2; step > 0; step /= 2) {   //�� ����� ����������
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

    

    void selectionSort(int(&mas)[lengthMas1], int length) {     //������� (����������� � ������)
        for (int index = 0; index < length; index++)
        {
            int minElemIndex = index;       //����������� ������

            for (int j = index + 1; j < length; j++)   //������� ������ ������������ ��������
                if (mas[minElemIndex] > mas[j])
                    minElemIndex = j;
            int temp = mas[index];  //������ ������� ������ ����������������� � �����������
            mas[index] = mas[minElemIndex];
            mas[minElemIndex] = temp;
        }
    }

    void insertionSort(int(&mas)[lengthMas1], int left, int right) {     //���������(������� �� ���� �����)
        for (int j = left; j < right + 1; j++) {
            int keyNum = mas[j];       //������� ���������
            int i = j - 1;        //������ ������� �� ��������������� ����. (���� � ������)
            while ((i >= left) and (mas[i] > keyNum)) { //���� �� ����� �� ������ ��� ��������� �� ����������
                mas[i + 1] = mas[i];    //�������� �������� ������, ��� ����� �������� �� ������
                i--;
            }
            mas[i + 1] = keyNum;        //������ ������� ��������� �� ��������� �������
        }
    }

    void bubbleSort(int(&mas)[lengthMas1], int length) {     //�������
        bool swap = true;
        int stable = 0;
        while (swap) {
            swap = false;
            for (int i = 0; i < length - stable - 1; i++)
                if (mas[i] > mas[i + 1]) {  //���������� �������� ��������
                    int temp = mas[i];      //������������ �������
                    mas[i] = mas[i + 1];
                    mas[i + 1] = temp;
                    swap = true;
                }
            stable++;
        }

    }

    void merge(int(&mas)[lengthMas1], int start, int end, int mid) {        //��������
        int lengthArray = end - start + 1;  //����� ���������������� �������
        int right = mid + 1;    //������ ������� ��. ������ �������
        int left = start;     //������ ������� ��. ����� �������
        int indexArray = 0;   //������ ���������������� �������
        int* array = new int[lengthArray];


        while ((left <= mid) and (right <= end)) {   //���� �� ��������
            if (mas[left] < mas[right])     //������� ���������� � ��������������
                array[indexArray++] = mas[left++];
            else array[indexArray++] = mas[right++];

        }
        while (left <= mid)     //���������� ���������� ������� �������
            array[indexArray++] = mas[left++];
        while (right <= end)
            array[indexArray++] = mas[right++];
        for (int i = start; i <= end; i++)      //������������ ������
            mas[i] = array[i - start];

        delete[] array;     //������� ��������������� ������
        array = nullptr;

    }
    void mergeSort(int(&mas)[lengthMas1], int left, int right)
    {     //����� ������ �������, ��������� �� ���������� � ������� ��
        if (left >= right) {    //���� �� ��������� 1 �������
            return;
        }
        int mid = left + (right - left) / 2; //������� ��������
        mergeSort(mas, left, mid);     //��������� ����� �����
        mergeSort(mas, mid + 1, right);//��������� ������ �����
        merge(mas, left, right, mid);  //����������
    }

    void quickSort(int(&mas)[lengthMas1], int left, int right) {
        int i = left;           //��� ��. ������ ����� �����, ������ ������
        int j = right;
        int mid = mas[(left + right) / 2];  //������� �������(�����)
        do {
            while (mas[i] < mid) //���� �������� ������� ������ �����
                i++;    //���� �� �������
            while (mas[j] > mid) //���� �������� � ����� ������ �����
                j--;    //���� �������
            if (i <= j) { 
                swap(mas[j], mas[i]);
                
                i++; j--;
            }
        } while (i <= j);   //���� �� ������� ������ ���������

        if (j > left) { //��������� �� ������
            //"����� �����"
            quickSort(mas, left, j);
        }
        if (i < right) {
            //"����� �����"
            quickSort(mas, i, right);
        }
    }

    void heapify(int(&mas)[lengthMas1], int length, int i) { //������ ����
        int maxElem = i;    //������������ ������� (��������)
        int left = 2 * i + 1;   //����� ���������
        int right = 2 * i + 2;  //������ ���������
        if ((left < length) and (mas[left] > mas[maxElem])) {
            maxElem = left; //���� �� ����� �� ������� ������ � � ����� ���� ������� ��
        }
        if ((right < length) and (mas[right] > mas[maxElem])) {
            maxElem = right;
        }
        if (maxElem != i) { //���� ����. �� ��������, ������ �������
            int tmp = mas[i];
            mas[i] = mas[maxElem];
            mas[maxElem] = tmp;
            heapify(mas, length, maxElem);  //����� ������, ���� ���� �� ����� � �����
        }
    }
    void heapSort(int(&mas)[lengthMas1], int length) {  //���������� ������
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
            insertionSort(mas, left, right);//��������� ���� � ������� �������
        }
        int size = run;
        while (size < length) {     //��������� ���� ��������
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





    void heapsort(int(&mas)[lengthMas1], int end, int begin) {  //���������� ������
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