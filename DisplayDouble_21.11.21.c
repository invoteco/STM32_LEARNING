#include <stdio.h>
#include <math.h>
#include <stdlib.h>
#include <stdint.h>

//Возведение в степень
int my_power(int base, unsigned int exp) {
    int i, result = 1;
    for (i = 0; i < exp; i++)
        result *= base;
    return result;
 }

int main(void) {

	double sourcenum = 0.23456789;


	while (1) {
	    uint8_t width = 6; //Ширина
	    uint8_t digitstoround = 2; //До скольки знаков производить округление
	    double k = 0.0;
	    //int k = 0;
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

	    dpp = floor(log10(abs(intpart)));//Вычисляетсположение точки

	    if (dpp == 0) {
	       k = 1000000.0;
	        //k = 1000000;
	   }
	    else if (dpp == 1) {
	        k = 100000.0;
	        //k = 100000;
	    }
	    else if (dpp == 2) {
	   k = 10000.0;
	    //k = 10000;
	    }
	    else if (dpp == 3) {
	   k = 1000.0;
	    //k = 1000;
	    }
	    else if (dpp == 4) {
	        k = 100.0;
	        //k = 100;
	    }
	    else if (dpp == 5) {
	        k = 10.0;
	        //k = 10;
	    }
	    else if (dpp == 6) {
	        k = 1.0;
	        //k = 1;
	    }
	    else {
	        k = 1.0;
	        //k = 1;
	    }
	    
	   //k = my_power(10, (11 - dpp));
	    //k = my_power(10, (width - dpp));
         printf("k = %f \n", k); 
	    double bigdou = roundednum * k;

	        IntVal = (int) bigdou;
		    uint8_t nDigits = floor(log10(abs(IntVal))) + 1;//Вычисляется кол-во знаков в IntVa
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


		    //Создание и заполнение массива с данными и точкой в позиции dppа

		    //char buffer[sizeof(myarray) + 1] = {'\0'}; //т.к массив увеличивается на 1 из-за точки и минуса
		    //char buffer[0];// = {'\0'}; //т.к массив увеличивается на 1 из-за точки и минуса
		    //char buffer[nDigits + 1] = {'\0'}; //т.к массив увеличивается на 1 из-за точки и минуса
		    //char buffer[dpp + 1] = {'\0'}; //т.к массив увеличивается на 1 из-за точки и мину
		    //char buffer[6] = {'\0'}; //т.к массив увеличивается на 1 из-за точки и минуса
		    char buffer[6] = {'\0'}; //т.к массив увеличивается на 1 из-за точки и минуса
		    uint8_t offset = 0;//Смещение знаков вправо для работы с числами типа 0,01

		    if ((fabs(sourcenum) < 1 ) && (fabs(sourcenum) >= 0.1 )){
		        offset = 1;
		    }
		    if ((fabs(sourcenum) < 0.1 ) && (fabs(sourcenum) >= 0.01 )){
		        offset = 2;
		    }
		    if ((fabs(sourcenum) < 0.01 ) && (fabs(sourcenum) >= 0.001 )){
		        offset = 3;
		    }
		    if ((fabs(sourcenum) < 0.001 ) && (fabs(sourcenum) >= 0.0001 )){
		        offset = 4;
		    }
		    if ((fabs(sourcenum) < 0.0001 ) && (fabs(sourcenum) >= 0.00001 )){
		        offset = 5;
		    }	
		    if ((fabs(sourcenum) < 0.00001 ) && (fabs(sourcenum) >= 0.000001 )){
		        offset = 6;
		    }	
		    if ((fabs(sourcenum) < 0.000001 ) && (fabs(sourcenum) >= 0.0000001 )){
		        offset = 7;
		    }
		    if ((fabs(sourcenum) < 0.0000001 ) && (fabs(sourcenum) >= 0.00000001 )){
		        offset = 8;
		    }
		    if ((fabs(sourcenum) < 0.00000001 ) && (fabs(sourcenum) >= 0.000000001 )){
		        offset = 9;
		    }
		    if ((fabs(sourcenum) < 0.000000001 ) && (fabs(sourcenum) >= 0.0000000001 )){
		        offset = 10;
		    }
		    
		    
		    
		    dpp = dpp + 1;

		    for (int l = 0; l < sizeof(buffer); l++) {
		        if (l == dpp) {
		            buffer[l] = '.';
		        } else if (l > dpp) {
		            buffer[l] = myarray[l - 1- offset] + '0';
		        }
		        else {
		            buffer[l] = myarray[l - offset] + '0';
		        }
		    }
		   
		   
		   if ((sourcenum < 0)){
		       
		       dpp = dpp + 1;
		       
		     for (int m = 0; m < sizeof(buffer); m++) {

		        if (m == 0) {
		            buffer[m] = '-';
		        }
		        else if (m == dpp){
		            buffer[m] = '.';
		        }
                else if (m > dpp) {
                    buffer[m] = myarray[m - 2 - offset] + '0';
		        }
		        else {
		            buffer[m] = myarray[m - 1 - offset] + '0';
		        }
		    }
     }
		   
		   
		   
		   
		    
		  //printf("k = %d \n", k); 
		  printf("dpp = %d \n", dpp);
		  printf("nDigits = %d \n", nDigits);
	
	
			  //Вывод результата
          for (int i = 0; i < sizeof(myarray); i++) {
              printf("a = %d \n", myarray[i]);
         }
		  
		  //Вывод результата
          for (int i = 0; i < sizeof(buffer); i++) {
              printf("z = %c \n", buffer[i]);
         }
         break;
	}
}


