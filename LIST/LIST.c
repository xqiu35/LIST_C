#include <stdio.h>
#include <stdlib.h>
#include "LIST.h"

bool Is_List_Full();			// local function used for checking if mem full
Node* List_End(List* list);		// return the address of end of list
Node* List_Beg(List* list);		// return the address of beg of list

void InitList(List* list)
{
	*list = NULL;
}

void Insert_Back_List(List* list, const Item item)
{
	if (Is_List_Full())		// to be save, if full, not terminate program.
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

void Delete_Back_List(List* list)
{
	if (*list == NULL)
		return;

	Node* ptr = *list;

	while (ptr->next->next)
	{
		ptr = ptr->next;
	}

	free(ptr->next->next);
	ptr->next = NULL;
}

void Insert_Front_List(List* list, const Item item)
{
	if (Is_List_Full())
		return;
	Node* new_Node = (Node*)malloc(sizeof(Node));
	new_Node->item = item;

	if (*list == NULL)
	{
		*list = new_Node;
		(*list)->next = NULL;
	}
	else
	{
		new_Node->next = *list;
		(*list) = new_Node;
	}
}

void Delete_Front_List(List* list)
{
	if (*list == NULL)
		return;

	Node* ptr = (*list)->next;
	free(*list);
	*list = ptr;
}

void FreeList(List* list)
{
	Node* ptr = *list;
	while (*list)
	{
		ptr = (*list)->next;
		free(*list);
		(*list) = ptr;
	}
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

void For_Each_Item(const List* list, void(*fpt)(Item item))
{
	Node* ptr = *list;
	while (ptr)
	{
		(*fpt)(ptr->item);
		ptr = ptr->next;
	}
}

Item* Find_Item_If(const List* list, bool(*fpt)(const Item* item))
{
	Node* ptr = *list;
	while (ptr)
	{
		if ((*fpt)(&ptr->item))
		{
			return &ptr->item;
		}
		ptr = ptr->next;
	}
}

void List_Copy(const List* listA, List* listB)
{
	if (*listA == NULL)
	{
		InitList(listB);
		return;
	}
	else
	{
		Node* ptr = *listA;
		while (ptr)
		{
			if (!Is_List_Full())
			{
				Insert_Back_List(listB, ptr->item);
				ptr = ptr->next;
			}
			else
			{
				return;   // to be save, if list is full, not terminate the program. user should free list before exit;
			}
		}
	}
}

void List_Copy_IF(const List* listA, List* listB, bool(*fpt)(const Item* item))
{
	if (*listA == NULL)
	{
		InitList(listB);
		return;
	}
	else
	{
		Node* ptr = *listA;

		while (ptr)
		{
			if (!Is_List_Full())
			{
				if((*fpt)(&ptr->item))
					Insert_Back_List(listB, ptr->item);
				ptr = ptr->next;
			}
			else
			{
				return;   // to be save, if list is full, not terminate the program. user should free list before exit;
			}
		}
	}
}

void Print_List(const List* list)
{
	Node* ptr = *list;

	while (ptr)
	{
		printf("Tag: %s    Val: %.2f\n", ptr->item.tag, ptr->item.val);
		ptr = ptr->next;
	}
}