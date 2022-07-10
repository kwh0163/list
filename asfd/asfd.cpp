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
	cursor = start.next;
	element* ele = (element*)malloc(sizeof(element));
	ele->num = num;
	ele->next = cursor;
	start.next = ele;
}

int pop_back()
{
	cursor = &start;
	element* tmp = NULL;
	while (true)
	{
		if (cursor->next == NULL)
		{
			break;
		}
		if (cursor->next->next == NULL)
		{
			tmp = cursor;
		}
		cursor = cursor->next;
	}
	if (cursor == &start)
	{
		printf("clear\n");
		return 0;
	}
	int retval = cursor->num;
	free(cursor);
	tmp->next = NULL;
	return retval;
}

int pop_front()
{
	if (start.next == NULL)
	{
		printf("clear\n");
		return 0;
	}
	cursor = start.next->next;
	int retval = start.next->num;
	free(start.next);
	start.next = cursor;
	return retval;
	
}

void push_at(int num, int index)
{
	element* at = (element*)malloc(sizeof(element));
	cursor = &start;
	for (int i = 1; i < index; i++)
	{
		if (cursor -> next == NULL)
		{
			printf("push at error\n");
			return;
		}
		cursor = cursor->next;
	}
	at->num = num;
	at->next = cursor->next;
	cursor->next = at;
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

	/*element e_1;
	e_1.num = 1;
	element e_2;
	e_2.num = 2;
	push_back(&e_1);
	push_back(&e_2);*/
	//중요: free()는 heap 영역에 있는 변수만 가능하다.
	
	push_back(1);
	push_back(3);
	push_at(9, 4);
	print_all();
	
}