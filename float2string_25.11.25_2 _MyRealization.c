// C program to convert float and double value in string using gcvt()
#include <stdio.h>



int main()
{
    double x = 999.0014567;
    
    int toround = 4; //Кол-во знаков после точки для отображения. Правильное округление последнего знака работает не всегда.
    int z;
    
    if (x < 0) {
        if ((x > -1000) && (x <= -100)){
            z = toround + 5;
        }
        if ((x > -100) && (x <= -10)){
            z = toround + 4;
        }
        if ((x > -10) && (x <= 0)){
            z = toround + 3;
        }
       
    }
    if (x > 0){
        if ((x < 1000) && (x >= 100)){
            z = toround + 4;
        }
        if ((x < 100) && (x >= 10)){
            z = toround + 3;
        }
        if ((x < 10) && (x >= 0)){
            z = toround + 2;
        }
    }
    
    int ndigits;
    if (x < 0) {
        if (x > -1){
            ndigits = z - 3;    
        }
        if (x < -1){
            ndigits = z - 2;    
        }
    }else{
        ndigits = z - 1;
    }
    
    char buf[z];
    
    gcvt(x, ndigits, buf);
    //Вывод содержимого буфера
    for (int j = 0; j < sizeof(buf); j++) {
        printf("buf[%d] = %c\n", j, buf[j]);
    }

    return 0;

}
