#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct stu
{
	int num;
	//char name[20];
	struct stu *next;
}STU;

STU *createList()
{
	STU *head = NULL;
	STU *p2 = NULL;
	STU *p1 = (STU *)malloc(sizeof(STU));
	printf("input a student's NO:");
	scanf("%d",&p1->num);
#if 0
	printf("input a student's name:");
	scanf("%s",p1->name);
#endif
	//p2 = p1;
	while((p1->num) != 0)
	{
		//printf("%s %d\n",__func__,__LINE__);
		if(head == NULL)
		{
			head = p1;
			p1->next = NULL;
		}
		else
		{
			p2->next = p1;
			//p1->next = NULL;		
		}
		p2 = p1;
		p1 = (STU *)malloc(sizeof(STU));
		printf("input a student's NO:");
		scanf("%d",&p1->num);
		//printf("p1->num is %d\n",p1->num);
#if 0
		printf("input a student's name:");
		scanf("%s",p1->name);
#endif
	}
	p1->next = NULL;
	return head;
}

void printList(STU *head)
{
	STU *p1 = head;
	while(p1 != NULL)
	{
		printf("p1->num is %d\n",p1->num);
		p1 = p1->next;
		//printf("p1->name is %s\n",p1->name);
	}
}

STU *revertList(STU *head)
{
	STU *p = NULL;
	STU *q = NULL;
	STU *r = NULL;
	p = head;
	q = p->next;
	head->next = NULL;

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
	STU *head = NULL;
	STU *revertHead = NULL;
	head = createList();	
	printList(head);	
#if 1
	revertHead = revertList(head);	
	printList(revertHead);	
#endif
	return 0;
}
