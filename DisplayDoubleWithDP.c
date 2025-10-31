#include <stdio.h>
#include <stdint.h>

int main() {
	// your code goes here
	double sourcenum = 12.3456789;

	double k = 0.0; //Коэфф.
	uint32_t IntVal = 0;
	double num;
        double roundednum; //Округленне число почему то при попытке вывести со спецификатором %d дает 0, хотя считает правильно
	uint16_t intpart; //Целая часть в числе
	uint8_t DispMass[4];
	uint8_t Mass[4];

	if (sourcenum < 0){  //Для того, чтобы работать с отрицательными числами
	    num  = -1 * sourcenum;
	}
	else
        {num = sourcenum;} //Странно что компилятор не выдал ошибку на круглые скобки

	uint8_t dpp = 1; //Позиция точки

	if (num > 9999){
	    printf("%s\n", "TooBig");
	}
	if ((num <= 9999) && (num >= 999)){
	   roundednum = round(num * 1) / 1;
	}
	if((num < 999) && (num >= 99)){
	    roundednum = round(num * 10) / 10;
	}
	if((num < 99) && (num >= 9)){
	    roundednum = round(num * 100) / 100;
	}
	if((num < 9) && (num >= 1)){
	    roundednum = round(num * 1000) / 1000;
	}
	if((num < 1) && (num >= 0.001)){
	    roundednum = round(num * 1000) / 1000;
	}
	if(num < 0.001){
	    printf("%s\n", "TooSmall");
	}
    printf("%f\n", roundednum);
	
	intpart = (uint16_t)roundednum;
    printf("%d\n", intpart);
    
	while (intpart /= 10){
	    dpp++;
	}

	if (sourcenum < 0){
	    dpp  = dpp + 1;
	}

    dpp = dpp - 1;//Положение десятичной точки
    printf("%d\n", dpp);
    
     //Для того, чтобы из дробного числа получить число,  целая чать которого будет сорстоять из 4 разрядов (3 в случае, если первый 0), умножаем его на соответствующий коэффициент К
	if (dpp == 0){ //Напр., если число 1.356, то получится 1.356 х 1000=1356. Если 0,486 то 486. !!!
    	    k = 1000.0;
        }
        else if (dpp == 1){ //Напр.24.789х100=2478.9
    	    k = 100.0;
        }
        else if (dpp == 2){ //358.7589 х 10 = 3587.589
    	    k = 10.0;
        }
        else if (dpp == 3){ //8125.654685 х 1 = 8125.654685
          k = 1.0;
        }
        else {  //2165416646.61196987 х 1 = 2165416646.61196987
    	  k = 1.0;
        }
    double bigdou = roundednum * k;
    printf("%f\n", bigdou);

	IntVal = (int)bigdou;
	printf("%d\n", IntVal);

	Mass[0] = (IntVal / 1000);
    Mass[1] = (IntVal % 1000) / 100;
    Mass[2] = (IntVal % 100) / 10;
    Mass[3] = (IntVal % 10);

   return 0;
}