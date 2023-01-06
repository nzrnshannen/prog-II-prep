#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head1, *temp1, *newNode, *head2, *temp2, *traverse;
int main()
{
	int n, i=1;
	head1=NULL;
	printf ("Input the number of elements to be stored in the array: ");
	scanf("%d", &n);
	
	printf ("Input %d data in the node:\n", n);
	
	while(i<=n)
	{
		newNode = (struct node*)malloc(sizeof(struct node));
		printf ("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(head1==NULL)
		{
			head1=temp1=newNode;
		}
		else
		{
			temp1->next=newNode;
			temp1=newNode;
		}
		i++;
	}
	
	i=1;
	newNode=NULL;
	traverse=head1;
	head2=NULL;
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data = traverse->data;
		newNode->next=NULL;
		
		if(head2==NULL)
		{
			head2=temp2=newNode;
		}
		else
		{
			temp2->next=newNode;
			temp2=newNode;
		}
		
		traverse=traverse->next;
		i++;
	}
	
	printf ("\nThe data stored in the first linked list are: ");
	traverse=head1;
	while(traverse!=NULL)
	{
		printf ("%d ", traverse->data);
		traverse=traverse->next;
	}
	
	printf ("\nThe data stored in the second linked list are: ");
	traverse=head2;
	while(traverse!=NULL)
	{
		printf ("%d ", traverse->data);
		traverse=traverse->next;
	}
	
	free(traverse);
	free(head1);
	free(head2);
	
	return 0;
}

