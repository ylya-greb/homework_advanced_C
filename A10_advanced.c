/*
 * A10_advanced.c
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






//прототип функции, которая  возвращает порядок числа с плавающей точкой
int extractExp(float);


int main(int argc, char **argv)
{
	float number;
	
	
	scanf("%f",&number);
	
	
	
	printf("%u",extractExp(number));
	
	
	
	return 0;
}

int extractExp(float f1)
{
//значение числа с плавающей точкой
//представлено объединением-с одной стороны,
//просто как число с плавающей точкой,
//с другой-как набор бит согласно представлению 
//чисел с плавающей точкой IEEE 754
union floatbit {
float value;
    struct {
        uint32_t mant : 23;
        uint32_t exp : 8;
        uint32_t sign : 1;
    } bit;
} f;
	
	f.value=f1;
	return f.bit.exp;
}
