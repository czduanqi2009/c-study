#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student
{
	int age;
	struct student *next;
};

typedef struct student STU;

STU *createList()
{
	STU *head = NULL;
	int n = 1;
	STU *p2 = NULL;
	STU *p1 = (STU *)malloc(sizeof(STU));
	p2 = p1;
	printf("input some students's age:");
	scanf("%d",&p1->age);
	while(n <= 6)
	//while(p1->age != 0)
	{
		if(head == NULL)
		{
			head = p1;
			p1->next = NULL;
		}
		else
		{
			p2->next = p1;	
		}
		p2 = p1;
		p1 = (struct student *)malloc(sizeof(struct student));
		printf("input some students's age:");
		scanf("%d",&p1->age);
		++n;	
	}
	p2->next = NULL;
	return head;
}

void print(STU *head)
{
	STU *p = head;
	int n = 0;
	while(p != NULL)
	//while(n <=6 && p != NULL)
	{
		printf("p's age is %d\n",p->age);
		p = p->next;
		//n++;
	}
}

int findByIndex(STU *head, int index)
{
	STU *p = head;
	STU *q = NULL;
	int n = 1;
	while(p != NULL)
	{
		if(index == n)
		{
			q = p;
			break;		
		}
		else
		{
			p = p->next;
			n++;
			continue;
		}
	}	
	if(q != NULL)
	{
		printf("age is %d\n",q->age);
		return q->age;
	}
	else
	{
		printf("not found the node!\n");
		return -1;
	}
}

STU *revert(STU *head)
{
	STU *p = NULL;
	STU *r = NULL;
	STU *q = NULL;
	p = head;
	q = p->next;	
	p->next = NULL;

	while(q != NULL)
	{
		r = q->next;
		q->next = p;
		p = q;
		q = r;	
	}
	head = p;
	return head;
}

int main()
{
	int index;
	STU *head = NULL;
	STU *headRevert = NULL;
	head = createList();
	print(head);
	printf("input which node's age do you want to see from last:");
	scanf("%d",&index);
	headRevert = revert(head);
	findByIndex(headRevert, index);
	return 0;
}
