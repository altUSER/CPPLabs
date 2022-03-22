#include <stdio.h>
#include <cstdlib>
#include <cmath>
//#pragma once
#define _CRT_SECURE_NO_WARNINGS

float Power(float value, unsigned short p)
{
    unsigned short i;
    float result = 1;
    for (i = 0; i < p; i++)
        result *= value;

    return result;
}


int main() {
    system("chcp 65001");

    printf("\n\nЗадание 2");
    printf("\n|   X   |      Y     |\n");
    printf("|-------|------------|\n");
    float x, y;
    int h;

    for (short n = 0; n < 5; n++) {

        for (x = 0; x < 4; x += 0.25) {
            if (x < 2) {
                y = sqrt(abs(1 - Power(x - 1, 2)))+2;
            }
            else {
                y = -1*sqrt(abs(1 - Power(x-3, 2)));
            }


            printf("| %5.2lf | %10.7lf | ", (x + n * 4), y);

            for (short h=11+y*5; h > 0; h--)
                printf(" ");
            printf("*\n");

        }
    }
    printf("|-------|------------|\n");

    printf("Press any key...");
    //_getch();
    return 0;
}