#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *traverse;

int main()
{
	head=NULL;
	int i=1, n, freq=1, flag=0;

inputAgain:
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf ("\n\nInput doesn't aid with the construction of LL. Try again.\n\n");
		goto inputAgain;
	}
	
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
	
	//traversing
	
	for(temp=head; temp!=NULL; temp=temp->next)
	{
		if(temp->data==-1)
			continue;
		
		for(traverse=temp->next; traverse!=NULL; traverse=traverse->next)
		{
			if(temp->data == traverse->data && temp->data!=-1 && traverse->data!=-1)
			{
				freq++;
				traverse->data=-1;
			}
		}
		
		printf ("%d occurs %d times\n", temp->data, freq);
		freq=1;
	}
	
	free(head);
	free(temp);
	free(newNode);
	free(traverse);
	
	return 0;	
}