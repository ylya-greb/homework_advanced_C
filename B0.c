/*
 * B0.c
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
#include <inttypes.h>
#include <stdlib.h>



typedef struct list {
uint64_t address;
size_t size;
char comment[64];
struct list *next;
} list;


uint64_t findMaxBlock(list *head);
void insert(list **head, uint64_t address, size_t size); 
_Bool delete(list **head, uint64_t address); 



int main(int argc, char **argv)
{
	list *l=NULL;
	uint16_t number;
	uint64_t address;
	size_t size;
	
	
	scanf("%hu",&number);
	
	for(uint16_t i=0;i<number;i++)
	{
		scanf("%llu",&address);
		scanf("%llu",&size);
		insert(&l,address,size);
	}
	
	
	printf("%llu",findMaxBlock(l));
	
	
	while(l)
	{
		delete(&l, l->address);
		
	}
	
	return 0;
}



uint64_t findMaxBlock(list *head)
{
	
	uint64_t address;
	size_t max_size;
	list *p;
	
	
	address=0;
	
	if(head!=NULL)
	{
		
		max_size=head->size;
		address=head->address;
		p=head;
		
		while(p!=NULL)
		{
			if(p->size>max_size)
			{
				max_size=p->size;
				address=p->address;
				
			}
			
			p=p->next;
		}
		
	}
	
	return address;
}


void insert(list **head, uint64_t address, size_t size) 
{
    list *tmp = malloc(sizeof(list));
    tmp->next = *head;
    tmp->address = address;
    tmp->size = size;

    *head = tmp;
}


_Bool delete(list **head, uint64_t address) 
{
    if(*head == NULL)
        return 0;
    list *del = NULL;
    if( (*head)->address == address) 
    {
        del = *head;
        *head = (*head)->next;
        free(del);
        return  1;//нашли адрес в начале
 list *tmp = *head;
    while( tmp->next ) {
        if( tmp->next->address == address ) {
            del = tmp->next;
            tmp->next = del->next;
            free(del);
            return 1;//нашли адрес в середине
        }
        tmp=tmp->next;
    }
    
}
    return 0;//не нашли адреса - это плохо
    
}

