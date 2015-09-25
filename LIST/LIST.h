#ifndef LIST_H_
#define LIST_H_

// Author: Xiaofei 
// Date: Sep 2015
// Description: This is implementation of list in c language
#include <stdbool.h>

#define ARRAY_SIZE 50

typedef struct book
{
	char name[ARRAY_SIZE];
	int price;
}Item;

typedef struct node
{
	Item item;
	struct node* next;
}Node;

typedef Node* List;

void InitList(List* list);

void Insert_Back_List(List* list, const Item item);
void Delete_Back_List(List* list, const Item item);
void Insert_Front_List(List* list, const Item item);
void Delete_Front_List(List* list, const Item item);

void For_Each_Item(const List* list, void(*fpt)(Item item));
Item Find_Item_If(const List* list, void(*fpt)(const Item* item));


#endif