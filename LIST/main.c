#include <stdio.h>
#include "LIST.h"
/* Test LIST */

void testInsertF();
void testInsertB();
void testDeleteF();
void testDeleteB();

int main(int argc, char** argv)
{
	testDeleteB();


	return 0;
}


void testInsertF()
{
	List list;
	InitList(&list);

	Item item1;
	strcpy(item1.tag, "hello1");
	item1.val = 1;

	Insert_Front_List(&list, item1);

	Item item2;
	strcpy(item2.tag, "hello2");
	item2.val = 2;

	Insert_Front_List(&list, item2);

	Item item3;
	strcpy(item3.tag, "hello3");
	item3.val = 3;

	Insert_Front_List(&list, item3);

	Print_List(&list);

	FreeList(&list);
}

void testInsertB()
{
	List list;
	InitList(&list);

	Item item1;
	strcpy(item1.tag, "hello1");
	item1.val = 1;

	Insert_Back_List(&list, item1);

	Item item2;
	strcpy(item2.tag, "hello2");
	item2.val = 2;

	Insert_Back_List(&list, item2);

	Item item3;
	strcpy(item3.tag, "hello3");
	item3.val = 3;

	Insert_Back_List(&list, item3);

	Print_List(&list);

	FreeList(&list);
}

void testDeleteF()
{
	List list;
	InitList(&list);

	Item item1;
	strcpy(item1.tag, "hello1");
	item1.val = 1;

	Insert_Back_List(&list, item1);

	Item item2;
	strcpy(item2.tag, "hello2");
	item2.val = 2;

	Insert_Back_List(&list, item2);

	Item item3;
	strcpy(item3.tag, "hello3");
	item3.val = 3;

	Insert_Back_List(&list, item3);

	Delete_Front_List(&list);
	Delete_Front_List(&list);

	Print_List(&list);

	FreeList(&list);
}

void testDeleteB()
{
	List list;
	InitList(&list);

	Item item1;
	strcpy(item1.tag, "hello1");
	item1.val = 1;

	Insert_Back_List(&list, item1);

	Item item2;
	strcpy(item2.tag, "hello2");
	item2.val = 2;

	Insert_Back_List(&list, item2);

	Item item3;
	strcpy(item3.tag, "hello3");
	item3.val = 3;

	Insert_Back_List(&list, item3);

	Delete_Back_List(&list);
	Delete_Back_List(&list);

	Print_List(&list);

	FreeList(&list);
}