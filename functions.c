
#include "functions.h"

//исходные функции
//f1=0.6x+3
double f1(double x)
{
return 0.6*x+3;
}

//f2=(x-2)^3-1
double f2(double x)
{
return ((x-2)*(x-2)*(x-2))-1;
}

//функция 3/x имеет разрыв при х=0
double f3(double x)
{
if(x)
{return 3/x;}
else
return NAN;
}



//функция y=10
double f4(double x)
{
return 10.0;
}

//функция y=x^2
double f5(double x)
{
return x*x;
}


//поиск решения методом деления отрезка пополам
double root(double (*f)(double), double (*g)(double), double a, double b, double eps, unsigned int * count_iteration) 
{
	double fa; 
	double fb;
	double c;
	double fc;
	
	//a-левая граница интервала
	//b-правая граница интервала
	//с-середина интервала
	//fa,fb,fc- значения функции f в точках a,b,c
	//ga,gb,gc- значения функции g в точках a,b,c
	
	//обнуляем кол-во итераций при входе в функцию вычисления
	(*count_iteration)=0;
	
	
	fa= f(a) - g(a);
	fb = f(b) - g(b);
	
	
	//вычисляем середину отрезка
	c = (a + b) / 2.0;
	
	
	//теорема о промежуточных значениях
	//на концах отрезка функция должна быть противоположных знаков
	//(если на этом отрезке есть  корень, то есть fx(x)=0)
	//то есть произведение <0
	if (fa * fb > 0) {
		printf( "No roots found  in this interval %f, %f\n", a, b);
		return NAN;
	}
	// продолжаем, пока не достигли заданной точности или не вып. 
	//макс.возможн число итераций(защита от зацикливания)
	while ((fabs(b - a) > eps)&&(NUMBER_MAX_ITERATION>*count_iteration)) 
	{
		//инкрементируем счетчик кол-ва итераций
		(*count_iteration)++;
		
		//вычисляем середину отрезка
		c = (a + b) / 2.0;
		fc = f(c) - g(c);
		
		//если f(x)=0-знач функции в середине отрезка
		//выходим
		if (fabs(fc) < eps) 
		{
			break;
		}
		//если знак функции в точках  a, c отличается-
		//корень находится в этом отрезке(в этой  половине)
		if (fa * fc < 0) {
			b = c;
			fb = fc;
		} 
		else 
		{
			//если знак функции в точках  a, c  не отличается-
		//корень находится в  отрезке [b;c]
			a = c;
			fa = fc;
		}
	}
	//если выполнили больше итераций, чем макс.возм(защита от зацикл.)
	if(NUMBER_MAX_ITERATION<=*count_iteration)
	{printf("\nExceed max number of iterations!!!\n");}
	
	
	return c;
}


// вычисление интеграла методом трапеций от функции f(x) на интервале 
//[a,b] с точностью eps
double integral(double (*f)(double), double a, double b, double eps, unsigned int * count_iteration) 
{
	int n = 1; 
	double h = (b - a) / n; 
	double summ = (f(a) + f(b)) / 2; 
	double previous_summ = 0; 
	
	//a-левая граница интервала
	//b-правая граница интервала
	//h-высота трапеции
	//n-кол-во интервалов
	//summ-интеграл на текущем шаге(площадь под кривой граф.функц )
	// f(x) на интервале  [a,b]
	//previous_summ-значение интеграла на предыдущем шаге 
	
	
	//обнуляем кол-во итераций при входе в функцию вычисления
	(*count_iteration)=0;
	
	//продолжаем, пока не достигли заданной точности или не вып. 
	//макс.возможн число итераций(защита от зацикливания)
	while ((fabs(summ - previous_summ) > eps)&&(NUMBER_MAX_ITERATION>*count_iteration)) 
	{
		//инкрементируем счетчик кол-ва итераций
		(*count_iteration)++;
		
		//увеличиваем кол-во интервалов
		n *= 2; 
		h = (b - a) / n; 
		previous_summ = summ; 
		summ = 0; 
		for (int i = 1; i < n; i++) 
			{summ += f(a + i * h); }
		summ = (f(a) + f(b) + 2 * summ) * h / 2; 
	}
	//если выполнили больше итераций, чем макс.возм(защита от зацикл.)
	if(NUMBER_MAX_ITERATION<=*count_iteration)
	{printf("\nExceed max number of iterations!!!\n");}
	return summ;
}



//функция для вывода справки(помощи) о ключах командной строки 
void print_help(void) 
{
	printf("\n---------------------------------------------------------------------\n");
    printf("Program options:\n");
    printf(" -help Print information about all program options\n");
    printf(" -test Test search root and calculate integral functions\n");
    printf(" -set_accuracy   Set accurancy of calculations(1e-4 for example)\n");
    printf(" -iterations Print number of iterations \n");
    printf(" -roots Print functions intersection points(roots) \n");
    printf("\n---------------------------------------------------------------------\n");
}



