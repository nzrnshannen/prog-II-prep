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
	
	int i=1, n, zeroCount=0, input;
	printf("Input number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Input %d data:\n", n);
	while(i<=n)
	{
		printf("Data %d: ", i++);
		scanf("%d", &input);
		
		if(input==0)
		{
			zeroCount++;
		}
		else
		{
			newNode=(struct node*)malloc(sizeof(struct node));
			newNode->data=input;
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
	}
	
	i=1;
	
	while(i<=zeroCount)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->data=0;
		newNode->next=NULL;
		
		temp->next=newNode;
		temp=newNode;
		
		i++;
	}
	
	temp=head;
	
	printf("\nAfter moving the zeroes to the right: ");
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	head=temp=newNode=NULL;
	free(head);
	free(temp);
	free(newNode);
	
	return 0;
}