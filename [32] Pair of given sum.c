#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *temp1, *temp2;

void freeNode()
{
	head=temp=newNode=temp1=temp2=NULL;
	free(head);
	free(temp);
	free(newNode);
	free(temp1);
	free(temp2);
	
}
int main()
{
	int n, i, sum, flag=0, node1, node2;
	node1=1, node2=1;
	printf ("Input number of nodes for your linked list: ");
	scanf("%d", &n);
	
	i=1;
	head=NULL;
	
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf ("Node %d: ", i++);
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
	
	printf ("\nInput sum: ");
	scanf("%d", &sum);
	
	for(temp1=head; temp1->next!=NULL; temp1=temp1->next)
	{
		node2=node1+1;
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
		{
			if((temp1->data + temp2->data)== sum)
			{
				printf("\n\nPair of nodes that can make the given sum:\n\t[Node %d]: %d\n\t[Node %d]: %d\n", node1, temp1->data, node2, temp2->data);
				freeNode();
				exit(1);
			}
			node2++;

		}
		node1++;
	}
	printf ("\nNo pair can make the given sum.");
	freeNode();
	return 0;
}