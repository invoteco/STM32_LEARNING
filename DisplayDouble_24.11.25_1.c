#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

//Работает для    if ((sourcenum > -999.999) && (sourcenum <= -1.000))

//Возведение в степень
int my_power(int base, unsigned int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
}

int main(void) {

    //double sourcenum = -998.999;
    double sourcenum = -1.001;


    while (1) {
        uint8_t digitstoround = 3; //До скольки знаков производить округление
        double k = 0.0;
        uint32_t IntVal = 0;
        double num;
        double roundednum;
        uint16_t intpart;
        uint8_t dpp = 0; //Положение (индекс) десятичной точки

        if (sourcenum < 0) { //До начала формирования буфера работаем только с положительным числом
            num = -1 * sourcenum;
        }
        else {
            num = sourcenum;
        }

        //Округление
        double fac = pow(10, digitstoround);
        roundednum = round(num * fac) / fac;

        //Выделяем целую часть округленного числа
        intpart = (uint16_t) roundednum;

        dpp = floor(log10(abs(intpart))); //Вычисляетсположение точки

        if (dpp == 0) {
            k = 1000000.0;
        }
        else if (dpp == 1) {
            k = 100000.0;
        }
        else if (dpp == 2) {
            k = 10000.0;
        }
        else if (dpp == 3) {
            k = 1000.0;
        }
        else if (dpp == 4) {
            k = 100.0;
        }
        else if (dpp == 5) {
            k = 10.0;
        }
        else if (dpp == 6) {
            k = 1.0;
        }
        else {
            k = 1.0;
        }

        double bigdou = roundednum * k;

        IntVal = (int) bigdou;
        uint8_t nDigits = floor(log10(abs(IntVal))) + 1; //Вычисляется кол-во знаков в IntVa
        uint8_t myarray[nDigits]; //Массив для цифр
        uint8_t w = nDigits - 1; //Вспомогательная переменная

        //Добавление цифр в массив
        for (int p = 0; p < nDigits; p++) {
            if (p == 0) {
                myarray[p] = IntVal / my_power(10, w);
            }
            if (p == 1) {
                myarray[p] = (IntVal % my_power(10, w)) / my_power(10, w - p);
            }
            myarray[p] = (IntVal % my_power(10, (w - p + 1))) / my_power(10, w - p);
        }

        //Вывод результата
        for (int i = 0; i < sizeof(myarray); i++) {
            printf("myarray[%d] = %d \n", i, myarray[i]);
        }
        
        if ((sourcenum > -999.999) && (sourcenum <= -1.000)) {
            //Создание и заполнение массива с данныи ои точкой в позиции dppа
            char buffer[8] = {};
            int dppnew = dpp + 2; //Для вычисления правильного положения точки (сдвигается вправо)
            for (int k = 0; k < sizeof(buffer); k++) {
                if (k == 0) {
                    buffer[k] = '-';
                }
                if (k == dppnew) {
                    buffer[k] = '.';
                } 
                if (k > dppnew) {
                    buffer[k] = myarray[k-2] + '0';
                }
                if ((k < dppnew) && (k > 0)){
                    buffer[k] = myarray[k - 1] + '0';
                }
            }
            
            //Вывод содержимого буфера
            for (int j = 0; j < sizeof(buffer); j++) {
                printf("buffer[%d] = %c\n", j, buffer[j]);
            }
        }
        break;
    }
}