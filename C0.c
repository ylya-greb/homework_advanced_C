/*
 * C0.c
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
#include <string.h>
#include <stdlib.h>

#define NUMBER_OF_DIGITS 3
#define INPUT_NUMBER_SIZE 255


int count_three_digit_numbers(char *number) {
	//длина числа
	int lenght = strlen(number);
	//кол-во неповторяющихся чисел
	int count = 0;
	//массив,содержащий уникальные-неповторяющиеся числа 
	int unique_numbers[1000];
	uint16_t i,j,k,m;
	//текущее собранное 3-х разрядное число
	int n;
	//флаг  уникальности числа(1-уникально , 0-нет)
	uint8_t unique;
	
	//если число содержит меньше,чем 3 разряда-сразу выходим
	if (lenght < NUMBER_OF_DIGITS) {
		;
	}
	else
	{
	
		for ( i = 0; i < lenght; i++) {
			for ( j = i + 1; j < lenght; j++) {
				for ( k = j + 1; k < lenght; k++) {
					//если 3 цифры начинаются с 0-пропускаем так как 
					//число  с 0 начинаться не может
					if (number[i] == '0') 
						{continue;}
					//cобираем число из 3-х разрядов
					 n = (number[i] - '0') * 100 + (number[j] - '0') * 10 + (number[k] - '0');
					
					//устанавливаем флаг  уникальности числа
					unique = 1;
					//проверяем уникально ли  число
					//в цикле сравниваем  с ранее записанными  в массив уникальными  числами
					for ( m = 0; m < count; m++) {
						//если проверяемое на  уникальность  число
						//совпало с одним из массива уникальных  числе-оно не  уникально
						//сбрасываем флаг и прекращаем проверку
						if (unique_numbers[m] == n) {
							unique = 0;
							break;
						}
					}
					//если число уникально(прошло проверку на уникальность)
					//записываем ег ов массив уник.числе и инкрементируем  
					//счетчик таких чисел
					if (unique) 
					{
						unique_numbers[count++] = n;
					}
				}
			}
		}
	}
	return count;
}


int main(int argc, char **argv)
{
	//исходная строка с символами числа
	char str[INPUT_NUMBER_SIZE];
	scanf("%s", str);
	//кол-во различных 3-х значных чисел
	int count;
	count= count_three_digit_numbers(str);
	
	printf("%d\n", count);
	
	
	return 0;
}
