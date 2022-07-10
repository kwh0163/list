#include<stdio.h>
#include<stdlib.h>

struct element
{
	int num;
	element* next = NULL;
};
element start;
element* cursor;

void push_back(element* ele)
{
	cursor = &start;
	while (true)
	{
		if (cursor->next == NULL)
		{
			break;
		}
		cursor = cursor->next;
	}
	cursor->next = ele;
}

void push_back(int num)
{
	cursor = &start;
	while (true)
	{
		if (cursor->next == NULL)
		{
			break;
		}
		cursor = cursor->next;
	}
	element* eP = (element*)malloc(sizeof(element));
	eP->next = NULL;
	eP->num = num;
	cursor->next = eP;
}

void push_front(int num)
{
	cursor = &start;
	while (true)
	{
		if (cursor->next == NULL)
		{
			break;
		}
		cursor = cursor->next;
	}
	element* eF = (element*)malloc(sizeof(element));
	
}



/*int* someFunc()
{
	int* a;
	a = (int*)malloc(sizeof(int));
	*a = 11;
	return a;
}
*/

void print_all()
{
	cursor = start.next;
	while(true)
	{
		if (cursor == NULL)
		{
			break;
		}
		printf("%d\t", cursor->num);
		cursor = cursor->next;
		
	}
	printf("\n");
}

int main()
{
	/*
	int* ap = someFunc();
	printf("%d\n", *ap);
	int a;
	free(ap);
	ap = &a;
	return;
	*/

	element e_1;
	e_1.num = 1;
	element e_2;
	e_2.num = 2;
	push_back(&e_1);
	push_back(&e_2);
	push_back(1);
	push_back(3);
	push_back(5);
	print_all();


}