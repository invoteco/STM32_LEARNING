#include <stdio.h>
#include <math.h>
#include <stdint.h>
/*Реализация преобразования числа типа uint в массив с использованием функции void TransformUintToArray (uint32_t sourcenum, uint8_t arr[])
Недостатком является необходимость при реализации вычислять размер массива dg (он равен кол-ву знаков в преобразуемом числе). В самой функции 
этот размер также вычисляется*/
int main() {

    uint32_t IntVal = 123456;//Число, которое мы хотим загнать в масси
    uint8_t dg = floor(log10(abs(IntVal))) + 1;//Вычисляется кол-во знаков в IntValв
    uint8_t myarray[dg]; //Массив для цифр1-мин кол-во
    
    TransformUintToArray (IntVal, myarray);

    //Вывод результата
    for (int i = 0; i < sizeof(myarray); i++) {
        printf("num = %d \n", myarray[i]);
    }
}


void TransformUintToArray (uint32_t sourcenum, uint8_t arr[]){
    uint8_t nDigits = floor(log10(abs(sourcenum))) + 1;//Вычисляется кол-во знаков в sourcenum
    uint8_t array[nDigits]; //Массив для цифр
    uint8_t w = nDigits - 1; //Вспомогательная переменная
    
    //Добавление цифр в массив
    for (int p = 0; p < nDigits; p++) {
       if (p == 0) {
            array[p] = sourcenum / my_power(10, w);
       }
        if (p == 1) {
            array[p] = (sourcenum % my_power(10, w)) / my_power(10, w - p);
        }
        array[p] = (sourcenum % my_power(10, (w - p + 1))) / my_power(10, w - p);
    }
    
    for (int d = 0; d < sizeof(array); d++) {
      arr[d] = array[d];
    }
 }
 
 //Возведение в степень
int my_power(int base, unsigned int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
 }
