//program bound to change

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *start;

int main()
{
	head=NULL;
	int i, n, pos;
	
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	i=1;
	printf("Input %d data:\n", n);
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
	
	printf ("\nLinked list before rotation: ");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	start=NULL;
	
	printf("\nRotate how many positions? ");
	scanf("%d", &pos);
	i=1;
	temp=head;
	
	while(temp!=NULL)
	{
		if(i==pos)
		{
			start=temp->next;
			break;
		}
		temp=temp->next;
		i++;
	}
	
	struct node *traverse;
	traverse=start;
	while(traverse->next!=NULL)
	{
		traverse=traverse->next;
	}
	traverse->next=head;
	
	temp=head;
	while(temp->next!=start)
	{
		temp=temp->next;
	}
	temp->next=NULL;
	
	head=start;
	
	printf ("\nLinked list after rotation: ");
	temp=head;
	
	while(temp!=NULL)
	{
		printf ("%d ", temp->data);
		temp=temp->next;
	}
	
	head=start=temp=newNode=NULL;
	free(head);
	free(start);
	free(temp);
	free(newNode);
	free(traverse);
	
	return 0;
}