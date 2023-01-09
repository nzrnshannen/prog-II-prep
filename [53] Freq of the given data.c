#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode;

int main()
{
	head=NULL;
	int i=1, n, num, freq=0;

inputNo:
	printf ("Input number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf ("\n\nInput can't generate a linked list. Try a different one.\n\n");
		goto inputNo;
	}
	
	printf ("\nInput %d data:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf ("Data %d: ", i++);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			temp->next=newNode;
			temp=newNode;
		}
	}
	
	printf ("\nThe given linked list is:\n");
	temp=head;
	while(temp!=NULL)
	{
		printf ("%d ", temp->data);
		temp=temp->next;
	}
	
	printf ("\n\nInput a number: ");
	scanf("%d", &num);
	
	for(temp=head; temp!=NULL; temp=temp->next)
	{
		if(temp->data == num)
		{
			freq++;
		}
	}
	
	if(freq!=0)
	{
		printf ("\n\nThe number [%d] appears %d time/s in the given list.\n", num, freq);
	}
	else
	{
		printf ("\n\nThere's no such thing as [%d] in the given list.", num);
	}
	
	head=temp=newNode=NULL;
	free(head);
	free(temp);
	free(newNode);
	
	return 0;
}