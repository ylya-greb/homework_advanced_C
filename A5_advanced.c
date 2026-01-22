/*
 * A5_advanced.c
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

#define BITS_PER_BYTE 8







int main(int argc, char **argv)
{
	uint32_t N;
	
	uint8_t i,counter;
	
	i=0;
	counter=0;
	
	scanf("%d",&N);
	
	while(i<sizeof(N)*BITS_PER_BYTE)
	{
		if(N&(1<<i))
		{
			counter++;
		}
		
		i++;
		
	}
	
	printf("%u",counter);
	
	
	
	
	
	
	
	
	return 0;
}

