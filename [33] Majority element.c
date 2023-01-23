#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *temp1, *temp2;

int main()
{
	head=NULL;
	int n, i=1;
	
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf ("\nInput %d data:\n", n);
	
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
	
	int count=0, majorElem, flag=0;
	
	for(temp1=head; temp1->next!=NULL; temp1=temp1->next)
	{
		count=1;
		for(temp2=temp1; temp2->next!=NULL; temp2=temp2->next)
		{
			if(temp1->data == temp2->data)
			{
				count++;	
			}
		}
		
		if(count>n/2)
		{
			flag=1;
			majorElem=temp1->data;
			break;
		}
		
		flag=0;
		
	}
	
	temp=head;
	printf("\nLinked list: ");
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	if(flag==0)
	{
		printf ("\n\nNo majority data can be found.\n");
	}
	
	else
	{
		printf ("\n\nMajority data: %d\n", temp1->data);
	}
	
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);

	head=temp=temp1=temp2=newNode=NULL;
	
	return 0;
	
}