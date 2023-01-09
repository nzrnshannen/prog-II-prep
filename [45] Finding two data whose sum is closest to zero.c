#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *temp1, *temp2, *newNode, *nodeOne, *nodeTwo;

int main()
{
	head=NULL;
	int n, i=1, flag=0;

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
	
	
	//finding two data whose sum is closest to zero
	int sum=0, sum_2=99;
	for(temp1=head; temp1->next!=NULL; temp1=temp1->next)
	{
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
		{
			if(temp1->data + temp2->data < 5 && (temp1->data + temp2->data) > -5)
			{
				sum=temp1->data + temp2->data;
				printf ("sum: %d", sum);
				flag=1;
			}
			
			if(sum<sum_2 && sum > -5 && sum < 5 && flag==1)
			{
				sum=sum_2;
				nodeOne=temp1;
				nodeTwo=temp2;
			}	
		}
	}
	
	if(flag==1)
	{
		printf ("\n\nThe two nodes whose data both being added is closest to the value 0:\n[%d, %d]", nodeOne->data, nodeTwo->data);
	}
	else
	{
		printf ("\n\nAddition of the two data that is closest to zero can't be found in the given linked list.");
	}
	
	head=newNode=temp=temp1=temp2=nodeOne=nodeTwo=NULL;
	free(head);
	free(temp);
	free(newNode);
	free(temp1);
	free(temp2);
	free(nodeOne);
	free(nodeTwo);
	return 0;
}