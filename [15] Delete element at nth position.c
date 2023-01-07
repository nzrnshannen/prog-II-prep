/*
	In this program, if pos exceeds to the number of nodes, it won't proceed to the deletion. Unlike the previous one 
	(the insertion program that I've made), when user enters a position which is pos>n, insertion will still proceed.
	This is only my personal preference on making algos of this code despite the similarities between two programs.
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *prev, *newNode;
int n;

void displayList()
{
	struct node *traverse;
	traverse=head;
	
	while(traverse!=NULL)
	{
		printf ("%d ", traverse->data);
		traverse=traverse->next;
	}
	printf ("\n\n");
	
	traverse=NULL;
	free(traverse);
}

int main()
{
	int i, pos;
	
	head=NULL;
	
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf ("\nInput %d data:\n", n);
	
	i=1; 
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
	
	printf ("\nLinked list before the deletion: ");
	displayList();

inputAgain:	
	printf ("Delete at what position? (starting from 1): ");
	scanf("%d", &pos);
	
	if(pos<=0 || pos>n)
	{
		printf ("\nInvalid input. Try inputting a different one.\n\n");
		goto inputAgain;
	}
	
	
	struct node* freeNode;
	if(pos==1)
	{
		//delete at beginning
		freeNode=head;
		head=head->next;
		
		free(freeNode);
	}
	else 
	{
		//delete at nth position
		prev=NULL;
		temp=head;
		i=1;
		while(i!=pos)
		{
			prev=temp;
			temp=temp->next;
			i++;
		}
		
		freeNode=temp;
		prev->next=temp->next;
		free(freeNode);
	}
	
	printf ("\nLinked list after deletion: ");
	displayList();

    head=temp=newNode=prev=NULL;
    free(head);
    free(temp);
    free(newNode);
    free(prev);

    return 0;
}