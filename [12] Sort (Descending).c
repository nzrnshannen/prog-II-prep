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
	int i, j, n;
	
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf ("\nInput %d data: \n", n);
	
	i=1;
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
	
	struct node *temp1, *temp2;
	
	for(temp1=head; temp1->next!=NULL; temp1=temp1->next)
	{
		for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
		{
			if(temp2->data < temp2->next->data)
			{
				int swap;
				
				swap=temp2->data;
				temp2->data = temp2->next->data;
				temp2->next->data = swap;
			}
		}
	}
	
	//traversing
	temp=head;
	
	while(temp!=NULL)
	{
		printf ("%d ", temp->data);
		temp=temp->next;
	}
	
	free(temp);
	free(temp1);
	free(temp2);
	free(head);
	free(newNode);

	head=temp=temp1=temp2=newNode=NULL;
	
	return 0;
}