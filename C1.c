/*
 * C1.c
 * 
 * Copyright 2026 USER <USER@PC-1>
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
#include <stdint.h>
#include <stdlib.h>
#include <inttypes.h>
#include <string.h>

#define SIZE 1000



//функция вычисления Z-функции
void zFunction(char *s, int *z)
{
int n =  strlen(s);
int i;
	
for(i=0;i<n;i++)
{z[i]=0;}
	
	
	for ( i=1; i<n; i++)
		while ( i+z[i] < n && s[z[i]] == s[i+z[i]])
		{  
			z[i]++;
		}       
}

//функция вычисления макс.суфикса  1-й и  преф 2-й
int calculate_max_suffix_prefix(char *str1, char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    //соединяем 2 строки: str2 + '#' + str1
    int summ_len = len1 + len2 + 1;
    //Z-функция
    int z[summ_len];
    //макс суффикс
    int max_suff = 0;
    
    char s[summ_len + 1];
    strcpy(s, str2);
    s[len2] = '#';
    strcpy(s + len2 + 1, str1);
    s[summ_len] = '\0';
    //вычисляем Z-функцию 
    zFunction(s, z);

    
    for (int i = len2 + 1; i < summ_len; i++) {

        if (z[i] > 0 && i + z[i] == summ_len) {
            max_suff = z[i];
            break;
        }
    }
    
    
    return max_suff;
}

//функция вычисления макс.префикса  1-й и  суфф 2-й
int calculate_max_prefix_suffix(const char *str1, const char *str2) {
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    // соединяем 2 строки: str1 + '#' + str2
    int summ_len = len1 + len2 + 1;
    //Z-функция
    int z[summ_len];
    //макс.префикс
    int max_pre = 0;
    //итоговая строка-объединение двух строк
    char s[summ_len + 1];
    strcpy(s, str1);
    s[len1] = '#';
    strcpy(s + len1 + 1, str2);
    s[summ_len] = '\0';
    //вычисляем Z-функцию 
    zFunction(s, z);
    
    
    
    for (int i = len1 + 1; i < summ_len; i++) {
        if (z[i] > 0 && i + z[i] == summ_len) {
            max_pre = z[i];
            break;
        }
    }
    
    
    return max_pre;
}


int main(int argc, char **argv)
{
	//исходные строки
	char str1[SIZE], str2[SIZE];
	//наибольш преффикс 1-й строки и  суффикс 2-й 
	int prefiks;
	//наибольш суффикс 1-й строки и префикс 2-й
	int suffiks;
	
	scanf("%s",str1);
	scanf("%s",str2); 
	
	prefiks = calculate_max_prefix_suffix(str1, str2);
	suffiks = calculate_max_suffix_prefix(str1, str2);
	printf("%d %d\n", prefiks, suffiks);
	
	return 0;
}
