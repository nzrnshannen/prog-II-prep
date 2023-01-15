#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int num;
	struct node *next_add;
};

struct node *head, *head1, *head2, *temp, *temp1, *temp2, *newNode;

void createList(struct node **, struct node **, int);
void displayList(struct node**, struct node**);
int checkEqual();

int main()
{
	head1=head2=NULL;
	int n1, n2, result;
	printf("Input the number of nodes for your first linked list: ");
	scanf("%d", &n1);
	createList(&head1, &temp1, n1);
	printf("First Linked List: ");
	displayList(&head1, &temp1);
	
	printf("Input the number of nodes for your second linked list: ");
	scanf("%d", &n2);
	createList(&head2, &temp2, n2);
	printf("Second Linked List: ");
	displayList(&head2, &temp2);
	
	result=checkEqual();
	
	printf("\nChecking if two linked list are equal...\n\nPress any key to continue- ");
	getch();
	
	if(result==1)
	{
		printf("\n\nTwo linked lists are not equal.\n");
	}
	else
	{
		printf("\n\nTwo linked lists are equal.\n");
	}
	
	head=head1=head2=temp=temp1=temp2=newNode=NULL;
	free(head);
	free(head1);
	free(head2);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);
	
	return 0;
}

void createList(struct node **head, struct node **temp, int n)
{
	int i=1;
	printf("Input %d data:\n", n);
	
	for(i; i<=n; i++)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->num);
		newNode->next_add=NULL;
		
		if(*head==NULL)
		{
			*head=*temp=newNode;
		}
		else
		{
			(*temp)->next_add=newNode;
			*temp=newNode;
		}
	}
	printf("\n");
}

void displayList(struct node **hd, struct node **traverse)
{
	*traverse=*hd;
	while(*traverse!=NULL)
	{
		printf("%d ", (*traverse)->num);
		*traverse=(*traverse)->next_add;
	}
	
	printf("\n\n");
	
}

int checkEqual()
{
	int flag, notEqual=0;
	
	for(temp1=head1; temp1!=NULL; temp1=temp1->next_add)
	{
		for(temp2=head2; temp2!=NULL; temp2=temp2->next_add)
		{
			if(temp1->num==temp2->num)
			{
				flag=1;
			}
		}
		
		if(flag==1)
		{
			flag=0;
			continue;
		}
		else
		{
			notEqual=1;
			break;
		}
		
		notEqual=0;
	}
	
	if(notEqual==1)
		return 1;
	else
		return 0;
		
}