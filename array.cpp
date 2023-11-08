#define _CRT_SECURE_NO_WARNINGS
#include <conio.h>
#include <windows.h>
#include <iostream>
#include <stdio.h>
#include <cstdlib>
#include <stdlib.h>
#include "sort.h"


using namespace std;

void sortedArray(int(&mas)[lengthMas1]) {
    for (int i = 0; i < lengthMas1; i++) {
        mas[i] = i;
    }
}
void almostSortedArray(int(&mas)[lengthMas1]) {
    int j = 0;
    for (int i = 19; i >= 0; i--) {

        mas[j] = i;
        j++;
    }
    for (int i = 20; i < lengthMas1; i++) {
        mas[i] = i;
    }
}
void backSortedArray(int(&mas)[lengthMas1]) {

    for (int i = 0; i < lengthMas1; i++) {
        mas[i] = lengthMas1 - 1 - i;
    }
}
void randomSortedArray(int(&mas)[lengthMas1]) {

    for (int i = 0; i < lengthMas1; i++) {
        int j = rand() % (lengthMas1 * 100);
        mas[i] = j;
    }
}
void printArray(int(&mas)[lengthMas1]) {

    cout << "[";
    for (int i = 0; i < lengthMas1; i++) {
        if (i != lengthMas1 - 1)
            cout << mas[i] << ", ";

        else cout << mas[i];
    }
    cout << "]" << endl;
}