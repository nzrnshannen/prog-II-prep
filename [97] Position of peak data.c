#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *prev;

int main()
{
	head=NULL;
	int i=1, n;
	printf("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
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
	
	
	printf("\nThe created linked list: ");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	prev=head;
	
	int flag=0, peakElem, pos=2, index;
	for(temp=head->next; temp->next!=NULL; temp=temp->next)
	{
		if(temp->data > prev->data && temp->data > temp->next->data)
		{
			flag=1;
			index=pos;
			peakElem=temp->data;
		}
		
		if(flag==1)
			break;
		
		prev=temp;
		pos++;
	}
	
	if(flag==1)
	{
		printf("\n\nThe peak data and its location [starting from 1]:\n%d located in position %d", peakElem, pos);
	}
	else
	{
		printf("\n\nNo peak data was found in the list.");
	}
	
	head=temp=newNode=prev=NULL;
	free(head);
	free(temp);
	free(newNode);
	free(prev);
	
	return 0;
}