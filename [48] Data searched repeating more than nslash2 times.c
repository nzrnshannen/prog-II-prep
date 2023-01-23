#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *temp1, *temp2, *newNode;

int main()
{
	head=NULL;
	int n, i=1, flag=0, count=0;

inputNo:
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf ("\n\nNumber can't generate a linked list. Try inputting a different one.\n\n");
		goto inputNo;
	}
	
	printf ("\nInput %d data:\n", n);
	
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(head==NULL)
			head=temp=newNode;
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
	
	int num;
	//find integer that appears more than n/2 times in n nodes
	printf ("\n\nInput data to be searched: ");
	scanf("%d", &num);
	
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{	
		if(temp1->data == num)
		{
			flag=1;
			count++;
		}	
	}
	
	if(flag==0)
	{
		printf ("\n\nThere's no such [%d] in the list.\n", num);
	}
	
	if(flag==1)
	{
		if(count>n/2)
		{
			printf ("\n\n%d appears more than %d times in the given list.", num, n-count);
		}
		else
		{
			printf ("\n\n[%d]'s frequency is not greater than n/2.", num);
		}
	}
	
	head=temp=newNode=temp1=NULL;
	free(head);
	free(temp);
	free(newNode);
	free(temp1);

	head=temp=newNode=temp1=NULL;
	
	return 0;
}