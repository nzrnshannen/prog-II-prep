/*
	Note: Program is written poorly in here as my only aim is to show the algorithm on how median of two same size is solved. 
			Functions will be used on the other program for clarity. 
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head1, *head2, *temp1, *temp2, *newNode, *t1, *t2;

int main()
{
	int n, i, m1, m2;
	head1=head2=NULL;
	printf("Input size for your first linked list (will apply to your second LL also): ");
	scanf("%d", &n);
	i=1;

//will be implemented using functions soon: createList()
	printf("\nInput %d data:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
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
	}	
	
	i=1;
	printf("\nInput %d data (second LL):\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->data);
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
	}
	
	printf("\n\nFirst linked list: ");
	temp1=head1;
	while(temp1!=NULL)
	{
		printf("%d ", temp1->data);
		temp1 = temp1->next;
	}
	
	for(t1=head1; t1->next!=NULL; t1=t1->next)
	{
		for(t2=head1; t2->next!=NULL; t2=t2->next)
		{
			int num;
			if(t2->data > t2->next->data)
			{
				num=t2->data;
				t2->data=t2->next->data;
				t2->next->data=num;
			}
		}
	}
	
	printf("\nAfter sort: ");
	int s=0;
	temp1=head1;
	while(temp1!=NULL)
	{
		if(s==n/2)
		{
			m1=temp1->data;
		}
		printf("%d ", temp1->data);
		temp1=temp1->next;
		s++;
	}

	printf("\n\nSecond linked list: ");
	temp2=head2;
	while(temp2!=NULL)
	{
		printf("%d ", temp2->data);
		temp2 = temp2->next;
	}
	
	for(t1=head2; t1->next!=NULL; t1=t1->next)
	{
		for(t2=head2; t2->next!=NULL; t2=t2->next)
		{
			int num;
			if(t2->data > t2->next->data)
			{
				num=t2->data;
				t2->data=t2->next->data;
				t2->next->data=num;
			}
		}
	}
	
	printf("\nAfter sort: ");
	int r=0;
	temp2=head2;
	while(temp2!=NULL)
	{
		if(r==n/2)
		{
			m2=temp2->data;
		}
	
		printf("%d ", temp2->data);
		temp2=temp2->next;
		r++;
	}
	
	printf("\nM1: %d", m1);
	printf("\nM2: %d\n", m2);
	printf("\nMedian: %d ", (m1+m2)/2);
	
	head1=head2=temp1=temp2=t1=t2=newNode=NULL;
	free(head1);
	free(head2);
	free(temp1);
	free(temp2);
	free(t1);
	free(t2);
	free(newNode);
	
	return 0;
}