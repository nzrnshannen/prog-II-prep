#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *head1, *head2, *temp, *temp1, *temp2, *newNode;

int main()
{
	head=head1=head2=NULL;
	int i=1, n;

enterAgain:
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf ("\nNumber not suitable for this particular program. Try inputting a different one.\n\n");
		goto enterAgain;
	}
	
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
	
	temp=head;
	newNode=NULL;
	
	while(temp!=NULL)
	{
		if(((temp->data)%2)==0)
		{	
			newNode=(struct node*)malloc(sizeof(struct node));
			newNode->data = temp->data;
			newNode->next=NULL;
			if(head2==NULL)
				head2=temp2=newNode;
			else
			{
				temp2->next=newNode;
				temp2=newNode;
			}
		}
		else
		{	
			newNode=(struct node*)malloc(sizeof(struct node));
			newNode->data = temp->data;
			newNode->next=NULL;
			if(head1==NULL)
				head1=temp1=newNode;
			else
			{
				temp1->next=newNode;
				temp1=newNode;
			}
		}
		
		temp=temp->next;
	}
	
	printf ("\nThe Even data are:\n");
	
	temp2=head2;
	while(temp2!=NULL)
	{
		printf ("%d ", temp2->data);
		temp2=temp2->next;
	}
	
	printf ("\nThe Odd data are:\n");
	temp1=head1;
	while(temp1!=NULL)
	{
		printf ("%d ", temp1->data);
		temp1=temp1->next;
	}
	
	free(head);
	free(head1);
	free(head2);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);

	head=head1=head2=temp=temp1=temp2=newNode=NULL;
	
	return 0;
}