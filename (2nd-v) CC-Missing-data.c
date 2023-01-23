#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *temp, *newNode, *check;

int main()
{
	int i=1, n, diff=0;
	printf("Enter the number of nodes: ");
	scanf("%d", &n);
	
	head=NULL;
	
	printf("Enter the elements: ");
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
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
	
		i++;
	}
	
	printf("Gaps: ");
	for(check=head; check->next!=NULL; check=check->next)
	{
		diff= check->next->data - check->data;
		
		if(diff>1)
		{
			int j;
			for(j=1; j<diff; j++)
			{
				printf("%d ", (check->data) + j);
			}
		}
	}
	
	free(head);
	free(temp);
	free(check);
	free(newNode);
	
	head=temp=check=newNode=NULL;
	
	return 0;
}

