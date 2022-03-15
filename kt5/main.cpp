#include <iostream>
#define N 9

void ViewArray(int arr[N][N], int size){
    for (int i = 0; i < size; i++) {
        for (int j = 0; j < size; j++)
            printf("%3d", arr[i][j]);
        printf("\n");
    }
}


int main() {
    int arr[N][N];

    int type=1;
    printf("Определите способ заполнения\n1-в случайном порядке\n2-с шагом К\n>");
    scanf("%d", &type);
    if (type==1){
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++)
                arr[i][j] = rand() % 100; // заполнение массива
        }
    } else if (type==2) {
        int step;
        printf("Задайте шаг К\n>");
        scanf("%d", &step);
        int k = 1;
        for (int i = 0; i < N; i++){
            for (int j = 0; j < N; j++)
                arr[i][j] = k++;// заполнение массива
                k += step;
        }
    } else {
        printf("Ошибка!");
        exit(0);
    }

    for (int i=2; i<=N; i+=2){
        for (int k=i; k>0; k--){
            std::cout << k;
        }
        std::cout << arr[0][i];
        printf("  ");
    }

    std::cout << arr[0][2] + arr[2][0] ;
    printf("\n\n");

    ViewArray(arr, N);
}
