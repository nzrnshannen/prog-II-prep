#include <stdio.h>
#include <stdlib.h>
#define MAX 50

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *temp1, *temp2;

int main()
{
	head=NULL;
	int i=1, n, pairCount=0, diff;
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
	
	int flag=0;
	
	printf("\n\nInput the difference: ");
	scanf("%d", &diff);
	
	printf("\n\nThe distinct pair/s for difference %d is/are:\n", diff);
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{
		for(temp2=head; temp2!=NULL; temp2=temp2->next)
		{
			if((temp1->data - temp2->data)==diff)
			{
				flag=1;
				pairCount++;
				printf("[%d, %d]\n", temp1->data, temp2->data);
				
			}
		}
	}
	
	if(flag==0)
	{
		printf("Number of distinct pairs: %d\n", pairCount);
		printf("\n\nNo distinct pairs were found in the list.\n");
	}
	else
		printf("\n\nNumber of distinct pairs: %d\n", pairCount);
	
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);

	head=temp=temp1=temp2=newNode=NULL;
	
	return 0;
	
}