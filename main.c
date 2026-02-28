
#include <stdio.h>
#include <inttypes.h>
#include "functions.h"
#include <string.h>


int main(int argc, char **argv)
{
	//точность  вычислений
	double eps = 1e-6;
	
	//количество итераций вычислений
	//unsigned int iterations=0,iterations1=0;
	unsigned int iterations[16]={0};
	
	
	//абциссы точек пересечения графиков
	double x1,x2,x3,x4,x5;
	
	// площади
	double total_area=0,area1=0,area2=0;
	
	//выбран ли  режим тестирования(0-нет,1-да)
	uint8_t test_mode=0;
	
	//выбран ли  режим установки точности(0-нет,1-да)
	uint8_t set_accuracy=0;
	
	//выбран ли  режим печати кол-ва итераций(0-нет,1-да)
	uint8_t print_iterations=0;
	
	//выбран ли  режим печати абцисс точек пересечений графиков функций
	// (корней)(0-нет,1-да)
	uint8_t print_roots=0;
	
    //для хранения данных командной строки
	char* str;


	//перебираем введенные параметры командной строки
    //argc- кол-во введенных параметров командной строки
    //argv- массив строк (введенных параметров) командной строки

    for(uint8_t i=0; i<argc; i++)
    {
        str = argv[i];
        
        if(str[0]=='-')
        {
            if (strcmp(str, "-help") == 0) {
                //вывод справки
	            print_help(); 
             return 0;
            } else if (strcmp(str, "-test") == 0) {
            //если выбрали тестовый режим
             test_mode = 1;
            } else if (strcmp(str, "-set_accuracy") == 0) {
                //если  выбран режим задания точности вычислений
                set_accuracy = 1;
            } else if (strcmp(str, "-iterations") == 0) {
                //если выбран режим печати кол-ва итераций
	            print_iterations=1;
            }else if (strcmp(str, "-roots") == 0) {
            //если выбран режим печати абцисс точек пересечений
            // графиков функций(корней)
	             print_roots=1;
            }
         else
         {
                //если ни один из перечисл. выше ключей
                printf("Underfined key!\n");
		        printf("Enter -help key for HELP\n");
            }
        }
    }
	
	
	//если  выбран режим задания точности вычислений
	if(set_accuracy)
	{
		//задание точности вычислений
		printf("Set accuracy\n");
		scanf("%lf",&eps);
		
		set_accuracy=0;
	}
	
	
	//если не выбран  тестовый режим
	if(!test_mode)
	{
	//Расчет точек пересечения графиков функций
	
	// пересечение f1(x) и  f2(x) справа от оси оу
	x1 = root(f1, f2, eps, 5, eps,  &iterations[0]); 
	
	// пересечение f1(x) и  f3(x) слева от оси оу
	x2 = root(f1, f3, -6, -4, eps,  &iterations[1]); 
	
	// пересечение f1(x) и  f3(x) справа от оси оу
	x3 = root(f1, f3, eps, 2, eps,  &iterations[2]); 
	
	// пересечение f2(x) и  f3(x) слева от оси оу
	x4 = root(f2, f3, -2, -eps, eps,  &iterations[3]); 
	
	// пересечение f2(x) и  f3(x) справа от оси оу
	x5 = root(f2, f3, 2, 4, eps, &iterations[4]); 
	
	
	//если  выбран режим печати абцисс точек пересечений графиков функций
	// (корней)
	if(print_roots)
	{
		printf("\n---------------------------------------------------------------------\n");
		printf(" Functions intersection points(roots): \n");
		printf("\n f1 and f2 x1=%f",x1);
		printf("\n f1 and f3 x2=%f",x2);
		printf("\n f1 and f3 x3=%f",x3);
		printf("\n f2 and f3 x4=%f",x4);
		printf("\n f2 and f3 x5=%f",x5);
		
		printf("\n---------------------------------------------------------------------\n");
		
		print_roots=0;
	}
	
	
	
	
	//Вычисление площади
	
	
	area1=integral(f1,x3, x1, eps,&iterations[5])-integral(f2,x5, x1, eps,&iterations[6])-integral(f3,x3, x5, eps,&iterations[7]);
	
	area2=integral(f1,x2, x3, eps,&iterations[8])-integral(f2,x4, x5, eps,&iterations[9])-integral(f3,x2, x4, eps,&iterations[10])+integral(f3,x3, x5, eps,&iterations[11]);
	
	//если выбран режим печати кол-ва итераций
	if(print_iterations)
	{
		printf("\n---------------------------------------------------------------------\n");
		printf(" Number of iterations: \n");
		printf("search functions intersection points(roots)\n");
		printf("\n f1 and f2  %u  iterations",iterations[0]);
		printf("\n f1 and f3  %u  iterations",iterations[1]);
		printf("\n f1 and f3  %u  iterations",iterations[2]);
		printf("\n f2 and f3  %u  iterations",iterations[3]);
		printf("\n f2 and f3  %u  iterations",iterations[4]);
		printf("\n\nIntegrals(area) calculations\n");
		printf("Triangle area \n");
		printf("\n f1   %u  iterations",iterations[5]);
		printf("\n f2   %u  iterations",iterations[6]);
		printf("\n f3   %u  iterations",iterations[7]);
		printf("\nQuadrangle area \n");
		printf("\n f1   %u  iterations",iterations[8]);
		printf("\n f2   %u  iterations",iterations[9]);
		printf("\n f3   %u  iterations",iterations[10]);
		printf("\n f3   %u  iterations",iterations[11]);
		
		printf("\n---------------------------------------------------------------------\n");
		
		print_iterations=0;
	}
	
	printf("\n Area triangle: %lf\n", area1);
	
	printf("\n Area quadrangle: %lf\n", area2);
	
	total_area=area1+area2;
	
	printf("\nSumm_area= %lf",total_area);
	}
	else
	{
		//в качестве теста находим площадь, огранич.графиками функций y=10 и y=x^2(f4 и f5)
		printf("\n---------------------------------------------------------------------\n");
		printf(" Test: \n");
		printf("f4(x)=10 and f5(x)=x^2 functions intersection points(roots)");
		// пересечение f4(x) и  f5(x) справа от оси оу
		x1 = root(f4, f5, eps, 5, eps,  &iterations[0]); 
		// пересечение f4(x) и  f5(x) слева от оси оу
		x2 = root(f4, f5, -5, -eps, eps,  &iterations[1]);
		printf("\nx1=%lf  x2=%lf\n",x1,x2);
		
		total_area=integral(f4,x2, x1, eps,&iterations[2])-integral(f5,x2, x1, eps,&iterations[3]);
		
		printf("Summ_area= %lf",total_area);
		
		printf("\n---------------------------------------------------------------------\n");
	}
	
	

	return 0;
}

