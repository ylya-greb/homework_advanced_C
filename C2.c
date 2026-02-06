/*
 * C2.c
 * 
 * Copyright 2026 Ylya <Ylya@SADOVOI-PC>
 * 
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 * 
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 * 
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor, Boston,
 * MA 02110-1301, USA.
 * 
 * 
 */


#include <stdio.h>
#include <inttypes.h>


#define MAX_STACK_SIZE 255
#define false 0
#define true 1

typedef int datatype;

int st[MAX_STACK_SIZE];// массив - стек
int pst=0; // заполненность  стека

//функция загрузки элемента в стек
void push(int v)
{ 
	//uint8_t pst1;
//printf("push\n");
// используется для вычислений
		if(pst>MAX_STACK_SIZE) {
		fprintf(stderr,"Error. Stack overflow");
		return ;
		}
   //pst1=pst;
	st[pst++]=v;
    //printf("st[pst]=%u pst=%d\n",st[pst1],pst);
}


//функция извлечения элемента из стека
int pop(){
	//printf("pop\n");
	//uint8_t pst1;
	if(pst<=0) {
		fprintf(stderr, "Error. Stack underflow");
		return 1;
	}
	else if(pst>MAX_STACK_SIZE) {
		fprintf(stderr, "Error. Stack overflow");
		return 1;
	}
    //pst1=pst;
    //pst1--;
   //printf("st[pst]=%u pst=%d\n",st[pst1],pst);      
	return st[--pst];
}






int isDigit(char c){ // проверяем является ли символ цифрой
    //printf("isDigit\n");
	return ((c>='0')&&(c<='9'));
}


//проверяем, является ли символ  арифм. оператором
int isOperator(char c) {
	return c=='+' ||  c=='-' ||  c=='*' || c=='/';
}


//функция для вычисления
void operate(char c){ // вычисляем два верхних значения на стеке st
   //printf("operate\n");
	int arg1=pop(),arg2=pop();
	switch(c)
	{
		case '+':
			push(arg1+arg2);
		break;
		case '-':
			push(arg2-arg1);
		break;
		case '*':
			push(arg1*arg2);
		break;
		case '/':
			push(arg2/arg1);
		break;
	}
	
}




int main(int argc, char **argv)
{
	
	
	char c;
	//printf("Input inverse string: ");
	char str[1000];
	int len=0;// 1 2 + 4 * 3 + // 3 5 + 10 * 17 2 * -
              //answer = 15    // answer = 46
	//считываем символы в массив пока не встретим перевод строки
	while((c=getchar())!='\n')
		str[len++]=c;
	//добавляем конец строки для строковых функций
	str[len]=0;
	//проходиммя по  массиву посимвольно
	for(int i=0;i<len;i++)
	{
		//если очередной символ-число
		if(isDigit(str[i]))
		{
			//преобразуем  число из символов char в число int 
			int number;
			for(number=0;isDigit(str[i]);i++)
				number=number*10+str[i]-'0';
			//кладем получившееся число  в стек
			push(number);
		}
		else
		{
			//если дошли до  конца массива-выходим
			if(i>=len)
				break;
				//если очередной символ- арифм.оператор-проводим вычисления
			if(isOperator(str[i]))
				operate(str[i]);
		}
	}
	//printf("answer = %d\n",pop());
	printf("%d",pop());
	
	return 0;
}

