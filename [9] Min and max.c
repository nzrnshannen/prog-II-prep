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
	int n, i=1, min=999, max=-999;
	
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf ("Input %d data: \n", n);
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
	
	temp=head;
	
	//for min
	while(temp!=NULL)
	{
		if(temp->data<min)
			min = temp->data;
		
		temp=temp->next;
	}
	
	//for max
	temp=head;
	
	while(temp!=NULL)
	{
		if(temp->data>max)
			max = temp->data;
		
		temp=temp->next;
	}
	
	printf ("\nMaximum data is: %d\n", max);
	printf ("Minimum data is: %d\n", min);
	
	free(temp);
	free(head);
	free(newNode);
	
	return 0;
}