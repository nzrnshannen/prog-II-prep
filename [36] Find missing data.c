//program bound to change

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
	int i, n;
	
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	i=1;
	printf("Input %d data:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf ("Data %d: ", i++);
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
	
	printf ("\nLinked list: ");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	int sum=0;
	int size=n+1;
	
	for(temp=head; temp!=NULL; temp=temp->next)
	{
		sum+=temp->data;
	}
	
	printf ("\nMissing number: %d", (size*(size+1))/2 - sum);
	
	head=temp=newNode=NULL;
	free(head);
	free(temp);
	free(newNode);
	
	return 0;
}