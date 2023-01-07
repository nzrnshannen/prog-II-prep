#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode;

int main()
{
	int n, i, largest, largest2nd;
	largest=largest2nd=0;
	
	printf ("Input number of nodes for your linked list: ");
	scanf("%d", &n);
	
	i=1;
	head=NULL;
	
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
		
		if(newNode->data > largest)
		{
			largest=newNode->data;
		}
	}
	
	temp=head;
	
	printf ("\nLinked list: ");
	while(temp!=NULL)
	{
		printf ("%d ", temp->data);
		temp=temp->next;
	}
	printf ("\n\n");
	
	temp=head;
	
	while(temp->next!=NULL)
	{
		if(temp->data==largest)
		{
			temp=temp->next;
		}
		
		if(temp->data > largest2nd)
		{
			largest2nd=temp->data;
		}
		
		temp=temp->next;
	}
	
	
	printf ("\nThe second largest data: %d", largest2nd);
	
	head=temp=newNode=NULL;
	free(head);
	free(temp);
	free(newNode);
	
	return 0;
}