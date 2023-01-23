/*
	Sorting 0s, 1s, and 2s without using any sorting method (Bubblesort, quicksort, mergesort, selection, etc.)
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head1, *head2, *head0, *traverse, *temp0, *temp1, *temp2, *newNode;

void createNode(struct node **head, struct node **t, int num)
{	
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->data=num;
	newNode->next=NULL;
	
	if(*head==NULL)
	{
		*head=*t=newNode;
	}
	else
	{
   	    (*t)->next=newNode;
		*t=newNode;
	}
	
}


int main()
{
	head0=head1=head2=NULL;
	int i=1, n, data;
	printf ("Input number of nodes for your list: ");
	scanf("%d", &n);

	printf ("\nInput %d data:\n", n);
	while(i<=n)
	{
		inputData:
		printf ("Data %d: ", i);
		scanf("%d", &data);
		
		if(!(data>=0 && data<=2))
		{
			printf ("\n\nData not applicable for this program. Try again.\n\n");
		}
		
		switch(data)
		{
			case 0: createNode(&head0, &temp0, data); break;
			case 1: createNode(&head1, &temp1, data); break;
			case 2: createNode(&head2, &temp2, data); break;
			
			default: printf ("\n\nData not applicable for this program. Try again.\n\n"); goto inputData; 
			//break;
		}
		i++;
	}
	
	temp0=head0;
	while(temp0->next=NULL)
	{
		temp0=temp0->next;
	}
	temp0->next=head1;
	
	temp1=head1;
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=head2;
	
	traverse=head0;
	
	printf ("\n\nThe sorted list:\n");
	while(traverse!=NULL)
	{
		printf ("%d ", traverse->data);
		traverse=traverse->next;
	}
	
	free(head0);
	free(head1);
	free(head2);
	free(temp0);
	free(temp1);
	free(temp2);
	free(newNode);
	free(traverse);

	head0=head1=head2=temp0=temp1=temp2=newNode=traverse=NULL;
	
	return 0;
	
}