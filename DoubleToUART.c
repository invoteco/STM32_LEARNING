#include <stdio.h>

#include <math.h>

#include <stdint.h>

int main() {
    double sourcenum = -3.14159;

    int digitstoround = 5;//До скольки знаков производить округление
    int digitstodisplay = 4;
    if (sourcenum < 0) {
        digitstoround = digitstoround - 1;
    }

    double k = 0.0;
    uint32_t IntVal = 0;
    double num;
    double roundednum;
    uint16_t intpart;
    //uint8_t DispMass[4];
    uint8_t Mass[digitstodisplay];

    if (sourcenum < 0) {
        num = -1 * sourcenum;
    }
    else {
        num = sourcenum;
    }

    uint8_t dpp = 1; //Ïîçèöèÿ òî÷êè

    double fac = pow(10, digitstoround);
    roundednum = round(num * fac) / fac;

    intpart = (uint16_t) roundednum;

    while (intpart /= 10) {
        dpp++;
    }
    if (sourcenum < 0) {
        dpp = dpp + 1;
    }

    dpp = dpp - 1;

    if (dpp == 0) {
        k = 1000.0;
    }
    else if (dpp == 1) {
        k = 100.0;
    }
    else if (dpp == 2) {
        k = 10.0;
    }
    else if (dpp == 3) {
        k = 1.0;
    }
    else {
        k = 1.0;
    }
    double bigdou = roundednum * k;

    IntVal = (int) bigdou;

    Mass[0] = (IntVal / 1000);
    Mass[1] = (IntVal % 1000) / 100;
    Mass[2] = (IntVal % 100) / 10;
    Mass[3] = (IntVal % 10);


    printf("dpp: %d\n", dpp); //Вывод положения (индекса) точки

    //Вывод исходного массива
    for (int i = 0; i < 4; i++) {
        printf("numbers[%d] = %d\n", i, Mass[i]);
    }

    if (sourcenum < 0) {
        //Создание и заполнение массива с данными ои точкой в позиции dppа
        char buffer[sizeof(Mass) + 1] = {}; //т.к массив увеличивается на 1 из-за точки и минуса
        int dppnew = dpp + 1; //Для вычисления правильного положения точки (сдвигается вправо)
        for (int k = 0; k < sizeof(buffer); k++) {
            if (k == 0) {
                buffer[k] = '-';
            }
            else if (k == dppnew) {
                buffer[k] = '.';
            } else if (k > dppnew) {
                buffer[k] = Mass[k - 1];
            }
            else {
                buffer[k] = Mass[k];
            }
        }

        //Вывод содержимого буфера
        for (int j = 0; j < sizeof(buffer); j++) {
            if (buffer[j] == '-') {
                printf("buffer[%d] = %c\n", j, '-');
            }
            else if (buffer[j] == '.') {
                printf("buffer[%d] = %c\n", j, '.');
            } else {
                printf("buffer[%d] = %c\n", j, buffer[j] + '0');
            }
        }
    }
    else
    {
        //Создание и заполнение массива с данными и точкой в позиции dpp
        char buffer[sizeof(Mass) + 1] = {}; //т.к. массив увеличивается на 1 из-за точки
        int dppnew = dpp + 1; //Для вычисления правильного положения точки
        for (int k = 0; k < sizeof(buffer); k++) {

            if (k == dppnew) {
                buffer[k] = '.';
            } else if (k > dppnew) {
                buffer[k] = Mass[k - 1];
            }
            else {
                buffer[k] = Mass[k];
            }
        }

        //Вывод содержимого буфера
        for (int j = 0; j < sizeof(buffer); j++) {
            if (buffer[j] == '.') {
                printf("buffer[%d] = %c\n", j, '.');
            } else {
                printf("buffer[%d] = %c\n", j, buffer[j] + '0');
            }
        }
    }
    return 0;
}