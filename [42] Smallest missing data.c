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
	int i=1, n, diff=0, smallest=999, missingElem=0;
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
				
				if(missingElem<smallest)
				{
					smallest=missingElem;
				}
			}
		}
	}
	
	printf("\nThe smallest missing data is: %d", smallest);
	
	head=temp=newNode=NULL;
	free(head);
	free(temp);
	free(newNode);
	
	return 0;
}