#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;	
};

struct node *head1, *temp1, *head2, *temp2, *newNode;

int main()
{
	head1=head2=NULL;
	int n1, n2;
enterFirst:
	printf ("Input the number of nodes for the first linked list: ");
	scanf("%d", &n1);
	
	if(n1<=0)
	{
		printf ("\nInvalid input. Try again.\n\n");
		goto enterFirst;
	}
	//will create a function for inputData()
	
	int i=1;
	
	while(i<=n1)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf ("Data %d: ", i++);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(head1==NULL)
		{
			head1=temp1=newNode;
		}
		else
		{
			temp1->next=newNode;
			temp1=newNode;
		}
	}

inputAgain:
	printf ("\nInput the number of nodes for the second linked list: ");
	scanf("%d", &n2);
	
	if(n2<=0)
	{
		printf ("\nInvalid output. Try Again.\n\n");
		goto inputAgain;
	}
	if(n2!=n1)
	{
		printf ("\nNumber of nodes specifically in this program not applicable. Please input the same number of nodes as the previous SLL.\n");
		goto inputAgain;
	}
	
	newNode=NULL;
	i=1;
	while(i<=n2)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(head2==NULL)
		{
			head2=temp2=newNode;
		}
		else
		{
			temp2->next=newNode;
			temp2=newNode;
		}
	}
	
	//linking first
	
	temp1=head1;
	
	while(temp1->next!=NULL)
	{
		temp1=temp1->next;
	}
	temp1->next=head2;
	
	
	for(temp1=head1; temp1->next!=NULL; temp1=temp1->next)
	{
		for(temp2=head1; temp2->next!=NULL; temp2=temp2->next)
		{
			if(temp2->data < temp2->next->data)
			{
				int temp;
				temp = temp2->data;
				temp2->data = temp2->next->data;
				temp2->next->data= temp;
			}
		}
	}
	
	
	temp1=head1;
	
	printf ("\nThe merged linked list in descending order is:\n");
	while(temp1!=NULL)
	{
		printf("%d ", temp1->data);
		temp1=temp1->next;
	}
	
	free(temp1);
	free(temp2);
	free(head1);
	free(head2);
	free(newNode);
	return 0;
}
