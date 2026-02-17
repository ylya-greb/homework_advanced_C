/*
 * D0.c
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
#include <stdlib.h>
#include <string.h>
#include <inttypes.h>

//размер буфера 
#define BUFFER_SIZE 1000

//односвязный список
struct list {
char word[20];
struct list *next;
};

//функция для  печати односвязного списка
void print_list(struct list *p)
{
    while(p)
    {
        printf("%s ",p->word);
        p = p->next;
    }
    printf("\n");
}


//функция для добавления элемента в список
void add_to_list(struct list **head, char * value) 
{
   struct list *new = (struct list *)calloc(1,sizeof(struct list));
    strcpy(new->word,value);
    // = ;
    new->next = *head;
    *head = new;
}





//функция для удаления односвязного списка
void delete_list(struct list **head)
{
	struct list *ptmp;
	
	while((*head)->next!=NULL)
	{
		ptmp=*head;
		*head=ptmp->next;
		free(ptmp);
		
	}
	free(*head);
	*head=NULL;
	
}


void swap_data(char* i,char* j)
{
char temp[20];

strcpy(temp,i);

//temp=*i;

strcpy(i,j);
//*i=*j;

strcpy(j,temp);
//*j=temp;
}



//функция для перестановки элементов односвязного списка
void swap_elements(struct list * i,struct list *j)
{
	
	swap_data(&(i->word),&(j->word));

}



//функция упорядочивания элементов односвязного списка по алфавиту
void sort_list_by_alphabet(struct list* head)
{
	struct list* ptmpi;
	struct list* ptmpj; 
	
	for(ptmpi=head; ptmpi!=NULL;ptmpi=ptmpi->next)
	{
		for(ptmpj=ptmpi; ptmpj!=NULL; ptmpj=ptmpj->next)
		{
			if(strcmp(&(ptmpi->word), &(ptmpj->word))>0)
			{
				
				swap_elements(ptmpi,ptmpj);
				
				
			}
			
		}
	}
	
}





int main(int argc, char **argv)
{
	struct list * data=NULL;
	//размер списка(кол-во элементов)
	uint16_t list_size=0;
	
	//буфер-для промежуточного хранения считанного символа и считанного слова
	char c,str[BUFFER_SIZE];
	uint16_t len=0;
	
	//отдельное слово
	char *word;
	uint16_t i=0;
	
	
	
	fgets(str, BUFFER_SIZE, stdin);
	
	for(i=0;i<BUFFER_SIZE;i++)
	{
		if(str[i]=='.')
		{str[i]='\0';
		break;
		}
		
	}
	
	
	//разделение строки на лексемы по пробелу
	word=strtok(str," ");
	
	while(word)
	{
		//добавляем считанное слово в список,увеличиваем размер  списка
		add_to_list(&data, word);
		list_size++;
		
		//разделение строки на лексемы по пробелу
		word=strtok(NULL," ");
	}
	
	
	
	//сортируем список по  алфавиту
	sort_list_by_alphabet(data);
	
	//печатаем список
	print_list(data);
	
	//удаляем элементы списка
	delete_list(&data);
	
	
	return 0;
}

