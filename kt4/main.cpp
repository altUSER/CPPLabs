#define _CRT_SECURE_NO_WARNINGS
#include <iostream>


bool checkPart(int num) {
    return num % 3 == 0;
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

            for (int i = 0; i < size; i++){
                int val = step;
                arr1[i] = val;
                val += step;
            }
        }
        else {
            printf("Ошибка!");
            extcode = 1;
            break;
        }

        int pos = 0;
        for (int i = 0; i < size; i++) {
            if (checkPart(arr1[i])) {
                arr2[pos] = arr1[i];
            }
        }

    } while (extcode == 0);
}

