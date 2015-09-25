#ifndef LIST_H_
#define LIST_H_

// Author: Xiaofei 
// Date: Sep 2015
// Description: This is implementation of list in c language
// For This implementation, List assignments are pass by reference. If copy is needed, List_Copy is used for copy.
// Insert to a full list will not terminate the program
// User should call FreeList before exit the program 

#include <stdbool.h>
#include <string.h>

#define ARRAY_SIZE 50

typedef struct Data
{
	char tag[ARRAY_SIZE];
	double val;
}Item;

typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef Node* List;

void InitList(List* list);

void Insert_Back_List(List* list, const Item item);
void Delete_Back_List(List* list);
void Insert_Front_List(List* list, const Item item);
void Delete_Front_List(List* list);
void FreeList(List* list);

void For_Each_Item(const List* list, void(*fpt)(Item item));
Item* Find_Item_If(const List* list, bool(*fpt)(const Item* item));
void List_Copy(const List* listA, List* listB);
void List_Copy_IF(const List* listA, List* listB, bool(*fpt)(const Item* item));

void Print_List(const List* list);

#endif