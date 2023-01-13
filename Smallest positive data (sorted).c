/*
	Program is somewhat similar to [42].
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode;

void sortList()
{
	struct node *temp1, *temp2;
	
	for(temp1=head; temp1->next!=NULL; temp1=temp1->next)
	{
		for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
		{
			int tempNum;
			if(temp2->data > temp2->next->data)
			{
				tempNum=temp2->data;
				temp2->data=temp2->next->data;
				temp2->next->data=tempNum;
			}
		}
	}
	
	temp1=temp2=NULL;
	free(temp1);
	free(temp2);
}

int main()
{
	head=NULL;
	int i=1, n, diff=0, smallest=9999, missingElem=0;
	printf("Input the number of nodes: ");
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
	
	printf("\nLinked list: ");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	sortList();
	
	for(temp=head; temp->next!=NULL; temp=temp->next)
	{
		diff=temp->next->data - temp->data;
		
		if(diff>1)
		{
			int j;
			for(j=1; j<diff; j++)
			{
				missingElem=0;
				missingElem = temp->data + j;
				
				if(missingElem<smallest && missingElem>0)
				{
					smallest=missingElem;
				}
			}
		}
	}
	
	printf("\nThe smallest positive data missed is: %d", smallest);
	
	head=temp=newNode=NULL;
	free(head);
	free(temp);
	free(newNode);
	
	return 0;
}