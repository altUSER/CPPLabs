#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

//var 15

void solve(char *inpString){
    char buffer[256];

    for (int i=0; i<strlen(inpString); i++){
        printf("%d\n", i);
    }

    printf("\n\n");
}

int main() {
    system("chcp 65001");

    int extcode = 0;
    short resp;

    const char deff_string[] = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    char proc_string[256] = "";

    while(extcode==0) {
        printf("Определите способ ввода текста:\n1-Ввод из файла\n2-Ручной ввод\n3-Предустановленная строка:\n\n0-Выход\n>");
        scanf("%d", &resp);

        switch (resp) {
            case 1:
                extcode = 1;
                printf("WIP");
                break;

            case 2:
                extcode = 1;
                printf("WIP");
                break;

            case 3:
                strcpy(proc_string, deff_string);
                break;

            case 0:
                extcode = 0;
                break;

            default:
                printf("Ошибка!");
                break;
        }

        if (extcode == 0){
            solve(proc_string);
        }

    }
    return 0;
}
