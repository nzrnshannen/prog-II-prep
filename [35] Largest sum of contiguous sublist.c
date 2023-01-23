//program bound to change

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *temp1, *temp2, *temp3;

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
	
	int sum, maxSum;
	sum=maxSum=0;
	
	/*
	Or:
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{
		sum+=temp1->data;
		
		if(sum<0)
			sum=0;
		else if(sum>maxSum)
			maxSum=sum;
	}*/
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{
		for(temp2=temp1; temp2!=NULL; temp2=temp2->next)
		{
			sum=0;
			for(temp3=temp1; temp3!=temp2->next; temp3=temp3->next)
			{
				sum+=temp3->data;
			}
			
			if(sum>maxSum)
				maxSum=sum;
		}
	}
	
	printf ("\nLargest sum of the contiguous sub-list: %d", maxSum);
	
	free(temp);
	free(temp1);
	free(temp2);
	free(temp3);
	free(newNode);
	free(head);

	head=temp=temp1=newNode=NULL;
	
	return 0;
}