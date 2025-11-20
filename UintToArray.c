#include <stdio.h>
#include <math.h>
#include <stdint.h>

int main() {

    uint32_t IntVal = 123456789;//Число, которое мы хотим загнать в массив

    uint8_t nDigits = floor(log10(abs(IntVal))) + 1;//Вычисляется кол-во знаков в IntVal
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
        printf("num = %d \n", myarray[i]);
    }

}
//Возведение в степень
int my_power(int base, unsigned int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
 }