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
	int n, diff=0, j;
	printf("Input number of nodes for your linked list: ");
	scanf("%d", &n);
	
	int i=1;
	printf("Input %d data:\n", n);
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
	
	printf("\nLinked list: ");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	
	printf("\nMissing data: ");
	for(temp=head; temp->next!=NULL; temp=temp->next)
	{
		diff=temp->next->data - temp->data;
		
		if(diff>1)
		{
			for(j=1; j<diff; j++)
			{
				printf("%d ", (temp->data) + j);
			}
		}
	}
	
	head=temp=newNode=NULL;
	free(head);
	free(temp);
	free(newNode);
	
	return 0;
}