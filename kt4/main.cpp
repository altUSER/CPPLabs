#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


bool checkPart(int num) {
    return num % 3 == 0;
}

void printArr(int *arr, int size){
    for (int i = 0; i < size; i++){
        printf("%d ", arr[i]);
    }
}

void invert(int *arr, int size){
    int temp;
    for (int i = 0; i<size/2; i++){
        temp = arr[i];
        arr[i] = arr[size-1-i];
        arr[size-1-i] = temp;
    }
}

void decStat(int *arr, int size, int dec){
    int min = arr[0];
    int max = arr[0];
    int sum, count;
    for (int i = 0; i < size; i++){
        if (arr[i]%dec==0 and arr[i]!=0) {
            count++;
            sum += arr[i];
            if (arr[i] < min) {
                min = arr[i];
            }
            if (arr[i] > max) {
                max = arr[i];
            }
        }
    }
    printf("Статистика для значений, кратных %d\nmin: %d\nmax: %d\navg: %d", dec, min, max, sum/count);
}

void showAddr(int *arr, int size){
    printf("Адреса переменных массива:\n");
    for (int i = 0; i < size; i++){
        printf("\n0x%X", &arr[i]);
    }
}

int main() {
    system("chcp 65001");
    setlocale(LC_ALL, "Russian");

    short extcode = 0;
    int resp, step;
    int size;


    do {
        printf("Введите размер массивов\n>");
        scanf("%d", &size);
        if (size < 1) {
            printf("Ошибка!");
            extcode = 1;
            break;
        }

        int* arr1 = new int[size];
        int* arr2 = new int[size];

        printf("Определите способ заполнения первого массива:\n1-случайными значениями\n2-попорядку от x1 с шагом k\n>");
        scanf("%d", &resp);
        if (resp==1) {
            const short MIN = -1000;
            const short MAX = 1000;

            for (int i = 0; i < size; i++)
                arr1[i] = MIN + rand() % (MAX - MIN + 1);
        }
        else if (resp == 2) {
            printf("Задайте шаг для заполнения массива\n>");
            scanf("%d", &step);

            int val = step;
            for (int i = 0; i < size; i++){
                arr1[i] = val;
                val += step;
            }
        }
        else {
            printf("Ошибка!");
            extcode = 1;
            break;
        }

        printf("Исходный массив:\n");
        printArr(arr1, size);
        printf("\n");

        for (int i = 0, pos = 0; i < size; i++) {
            if (checkPart(arr1[i])) {
                arr2[pos] = arr1[i];
                pos++;
            }
        }

        printf("Измененный массив с числами, кратными 3:\n");
        printArr(arr2, size);
        printf("\n\n\n");


        invert(arr1, size);
        printf("Исходный массив с перестановкой:\n");
        printArr(arr1, size);
        printf("\n");
        showAddr(arr1, size);
        printf("\n");
        decStat(arr1, size, 5);
        printf("\n\n");

        invert(arr2, size);
        printf("Измененный массив с перестановкой:\n");
        printArr(arr2, size);
        printf("\n");
        showAddr(arr2, size);
        printf("\n");
        decStat(arr2, size, 5);
        printf("\n\n");


    } while (extcode == 0);
}

