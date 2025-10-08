#include <stdio.h>

int main() {
    //double num = -1000;//Выводимое число
    //double num = -999.99;//Выводимое число
    double num = -99.99;//Выводимое число
    //double num = -100.1;//Выводимое число?
    //double num = -500.9;//Выводимое число?
    //double num = -0.19635;//Выводимое число
    //double num = -10.19635;//Выводимое число
    

    Int2CharArray(num);
    return 0;
}

//Конвертирует выводимое число в массив символов нужной длины
void Int2CharArray (double number) {
    double n;
   // if (((number >= 10.1) && (number<=99.9)) | ((number >= -99.9) && (number <= -10.1))){
    if (((number >= 0.1) && (number<=99.9)) | ((number >= -99.9) && (number <= -0.1))){
        n = round(number * 10) / 10; 
    } 
    else if(((number >= 100.1) && (number <= 999.99)) | ((number >= -999.99) && (number <= -100.1)))
    {
        n = round(number * 10) / 10;}
    else
    {
        n = round(number * 1000) / 1000;
    }
    
    int z;
    if(n >= 1000){
        z = 4;
    }else{
        z = 5;
    }
    
    if((n <= -1000) | (n >= 10000)){
        printf("%s\n", "Too."); }
    else{
        char c[z];
        sprintf(c , "%.4lf" , n);
        for (int i = 0; i < sizeof(c); i++) { 
            printf("%c\n" , c[i]); 
        } 
    }
}