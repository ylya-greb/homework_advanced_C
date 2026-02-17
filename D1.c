/*
 * D1.c
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
#include <string.h>
#include <stdlib.h>
#include <inttypes.h>

#define BUFFER_SIZE 1000


typedef int datatype;


//двоичное дерево
typedef struct tree {
datatype key;
struct tree *left, *right;
} tree;



//функция для вставки узла в дерево
void insert(tree **root,datatype key ) 
{
    if(!(*root))
    { 
// дерево пустое или дошли до нужного места
        *root=(tree *)calloc(1,sizeof(tree));
        (*root)->key=key;
        
    }
    else if( key < (*root)->key)
    {
        //если значение меньше,чем у корневого узла-вставляем в левое поддерево
        insert( &((*root)->left) ,key);
        
        
     }
     //иначе-вставляем в правое поддерево   
    else
        insert( &((*root)->right),key);
}



//функция  для обхода левого поддерева
void View_left(tree *root)
{
	//если не дошли до  самого левого узла-идем еще левее
	if(root->left!=NULL)
	{View_left(root->left);}
	//когда дошли до  самого левого узла-дальше рекурсивного  вызова не будет
	//печатаем ключи каждого узла снизу вверх
	printf("%d ",root->key);
	
	
}


//функция  для обхода правого поддерева
void View_right(tree *root)
{
	printf("%d ",root->key);
	
	if(root->right!=NULL)
	{View_right(root->right);}
	
	
	
	
}


//функция для печати  вида дерева сверху вниз


void btUpView(tree *root)  
{
    if (root == NULL)
    {
        return;
    }
    View_left(root);  
    if(root->right)  
    {
        View_right(root->right);
    }
    printf("\n");
}



int main(int argc, char **argv)
{
	tree *tr = NULL;
	
	char array[BUFFER_SIZE];
	datatype d;
	
	
	char *n;
	
	
	//считываем входные числа как строку символов
	fgets(array,BUFFER_SIZE,stdin);
	
	
	//разделение строки на лексемы по пробелу и переводу строки
	n=strtok(array," \n\r");
	
	while(n)
	{
		//переводим  в числа
		d=atoi(n);
		//вставляем узел  в дерево
		insert(&tr,d);
		
		
		//разделение строки на лексемы по пробелу и переводу строки
		n=strtok(NULL," \n\r");
	}
	
	//печать вида  дерева сверху
	btUpView(tr);
	
	return 0;
}

