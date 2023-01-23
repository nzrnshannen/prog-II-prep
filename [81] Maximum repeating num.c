#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *temp1, *temp2;

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
	
	
	int maxCount=0, count=0, maxElem;
	
	for(temp1=head; temp1->next!=NULL; temp1=temp1->next)
	{
		if(temp1->data==-1)
			continue;
		count=1;
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
		{
			if(temp1->data == temp2->data)
			{
				temp2->data=-1;
				count++;
			}
		}
		
		if(count>maxCount)
		{
			maxCount=count;
			maxElem=temp1->data;
		}
	}
	
	
	printf("\nThe maximum repeating number is: %d", maxElem);
	
	
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);
	
	head=temp=temp1=temp2=newNode=NULL;

	return 0;
}
