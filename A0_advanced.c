/*
 * A0_advanced.c
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




int main(int argc, char **argv)
{
	unsigned int N,i,count;
	
	int max,a;
	
	i=0;
	count=0;
	
	scanf("%d",&N);
	
	
	if(N)
	{
		
		scanf("%d",&a);
		max=a;
		i++;
		count++;
		
		while(N>i)
			{
				scanf("%d",&a);
				if(a>max)
				{
					max=a;
					count=1;
					
				}
				else
				{	if(a==max)
					{
						count++;
					}
				}
				
				i++;
				
			}
	
	
	}
	
	printf("%d",count);
	
	
	return 0;
}

