#include <stdlib.h>
#include <stdio.h>

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
	
	printf("Input %d data:\n", n);
	while(i<=n)
	{
		printf("Data %d: ", i++);
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
	}
	
	printf("\nLinked list: ");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	int diff=0, maxDiff=-999, ele1, ele2;
	
	for(temp1=head; temp1->next!=NULL; temp1=temp1->next)
	{
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
		{
			if(temp1!=temp2)
			{
				if(temp2->data > temp1->data)
				{
					diff=temp2->data - temp1->data;
				}
				else
				{
					continue;
				}
			}
			
			if(diff>maxDiff)
			{
				maxDiff=diff;
				ele1=temp1->data;
				ele2=temp2->data;
			}
		}
	}
	
	printf("\nThe data which provide maximum difference are: %d, %d\n", ele1, ele2);
	printf("The maximum difference between two data in the list is: %d", maxDiff);
	
	free(head);
	free(temp);
	free(newNode);
	free(temp1);
	free(temp2);

	head=temp=newNode=temp1=temp2=NULL;
	
	return 0;
}