#include <stdio.h>
#include <stdlib.h>
#include "LIST.h"

bool Is_List_Full();
Node* List_End(List* list);
Node* List_Beg(List* list);

void InitList(List* list)
{
	*list = NULL;
}

void Insert_Back_List(List* list, const Item item)
{
	if (Is_List_Full())
		return;

	Node* new_node = (Node*)malloc(sizeof(Node));
	new_node->item = item;
	new_node->next = NULL;

	if (*list == NULL)
	{
		*list = new_node;
	}
	else
	{
		Node* ptr = List_End(list);
		ptr->next = new_node;
	}

}

void Delete_Back_List(List* list, const Item item)
{
	if (Is_List_Full())
		return;

	Node* ptr = *list;

	while (ptr->next->next)
	{
		ptr = ptr->next;
	}

	ptr->next = NULL;
	free(ptr->next->next);
}

void Insert_Front_List(List* list, const Item item)
{
	if (Is_List_Full())
		return;
}

void Delete_Front_List(List* list, const Item item)
{

}


bool Is_List_Full()
{
	Node *pt = (Node*)malloc(sizeof(Node));

	if (pt == NULL)
		return true;
	else
		free(pt);
	return false;
}

Node* List_End(List* list)
{
	Node* end = *list;
	while (end->next)
	{
		end = end->next;
	}
	return end;
}

Node* List_Beg(List* list)
{
	return *list;
}