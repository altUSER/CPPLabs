#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>

using std::string;

//var 15

void solve(string inpString){
    string buffer;

    int spaceCount = 0;
    for (int i=0; inpString.size()-3; i++){
        std::cout << inpString.substr(i, 1);
        if (inpString.substr(i, 1)==" ") spaceCount++;
    }

    std::cout << spaceCount << "\n";

    size_t pos = inpString.find(" ");
    while (pos != std::string::npos){
        std::cout << inpString.substr(0, pos);
    }

    printf("\n\n");
}

int main() {
    system("chcp 65001");

    int extcode = 0;
    short resp;

    string deff_string = "Lorem ipsum dolor sit amet, consectetur adipiscing elit, sed do eiusmod tempor incididunt ut labore et dolore magna aliqua.";
    string proc_string = "";

    while(extcode==0) {
        printf("Определите способ ввода текста:\n1-Ввод из файла\n2-Ручной ввод\n3-Предустановленная строка\n\n0-Выход\n>");
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
                proc_string = deff_string;
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
