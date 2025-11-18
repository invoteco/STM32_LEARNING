#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main() {
    double sourcenum = -0.123456789;

    int digitstoround = 3; //До скольки знаков производить округление
    if (sourcenum < 0) {
        digitstoround = digitstoround - 1;
    }

    double k = 0.0;
    uint32_t IntVal = 0;
    double num;
    double roundednum;
    uint16_t intpart;
    uint8_t myarray[4];

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

    myarray[0] = (IntVal / 1000);
    myarray[1] = (IntVal % 1000) / 100;
    myarray[2] = (IntVal % 100) / 10;
    myarray[3] = (IntVal % 10);


    printf("dpp: %d\n", dpp); //Вывод положения (индекса) точки

    //Вывод исходного массива
    for (int i = 0; i < 4; i++) {
        printf("numbers[%d] = %d\n", i, myarray[i]);
    }

    //Создание и заполнение массива с данными ои точкой в позиции dppа
    char buffer[sizeof(myarray) + 1] = {}; //т.к массив увеличивается на 1 из-за точки и минуса
    int dppnew = dpp + 1; //Для вычисления правильного положения точки (сдвигается вправо)
    for (int k = 0; k < sizeof(buffer); k++) {

        if ((k == 0) && (sourcenum < 0)) {
            buffer[k] = '-';
        }
        else if (k == dppnew) {
            buffer[k] = '.';
        } else if (k > dppnew) {
            buffer[k] = myarray[k - 1];
        }
        else {
            buffer[k] = myarray[k];
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
    return 0;
}