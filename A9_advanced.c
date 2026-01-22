/*
 * A9_advanced.c
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

struct pack_array {
uint32_t array; // поле для хранения упакованного массива из 0 и 1
uint32_t count0 : 8; // счетчик нулей в array
uint32_t count1 : 8; // счетчик единиц в array
};



void array2struct(int [], struct pack_array *);





int main(int argc, char **argv)
{
	uint32_t n;
	
	uint8_t i=0;
	
	int arr[32];
	
	struct pack_array pack;
	
	
	for(i=0;i<32;i++)
	{
		scanf("%u",&n);
		*(arr+i)=n;
	}
	
	
	array2struct(arr, &pack);
	
	printf("%u %hhd %hhd",pack.array,pack.count0,pack.count1);
	
	
	
	return 0;
}



//функция для упаковки массива в структуру pack_array-из массива 0 и 1 
//делаем число, зашифрованное в массиве
void array2struct(int a [], struct pack_array * st)
{
	uint8_t i=0;
	
	st->array=0;
	st->count0=0;
	st->count1=0;
	
	
	
	//проходим по элементам массива, подсчитываем кол-во 0 и 1 в нем,
	//также формируем число, закодированное в массиве 
	for(i=0;i<32;i++)
	{
		if(*(a+i))
		{
			st->count1++;
			
		}
		else
		{
			st->count0++;
		}
		
		//добавляем к текущему значению числа
		//число выраженное элементом массива и преобразованное к виду числа
		st->array|=*(a+i)<<(31-i);
	}
	
	
	
	
	return;
}




