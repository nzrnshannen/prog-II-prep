#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *temp1, *temp2, *newNode;

int main()
{
	head=NULL;
	int i=1, n, sum, num1, num2, flag=0;
	printf("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Input %d data:\n", n);
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
	
	printf("\n\nThe created linked list: ");
	temp=head;
	
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	printf("\n\nEnter a number (sum): ");
	scanf("%d", &sum);
	
	printf("\n\nNow finding the pair of the given sum: %d...\nPress any key to continue- ", sum);
	getch();
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{
		for(temp2=head; temp2!=NULL; temp2=temp2->next)
		{
			if((temp1->data + temp2->data) == sum)
			{
				num1= temp1->data;
				num2= temp2->data;
				flag=1;
				break;
			}
		}
		
		if(flag==1)
		{
			break;
		}
	}
	
	if(flag==0)
	{
		printf("\n\nCannot find pair of the given sum.\n\n");
	}
	else
	{
		printf("\n\nPair of the given sum: [%d, %d]\n\n", num1, num2);
	}
	
	head=temp=temp1=temp2=newNode=NULL;
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);
	
	return 0;
}