#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;
	struct node *ptr;
};

struct node *head, *temp, *temp1, *temp2, *newNode;

int main()
{
	int i=1, n, count, oddCount=0, num, flag=0;
	head=NULL;
	
	printf("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Input %d data:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->data);
		newNode->ptr=NULL;
		
		if(head==NULL)
			head=temp=newNode;
		else
		{
			temp->ptr=newNode;
			temp=newNode;
		}
	}
	
	printf("\nLinked list: ");
	for(temp=head; temp!=NULL; temp=temp->ptr)
	{
		printf("%d ", temp->data);
	}
	
	printf("\n\nChecking if there is a number that appears odd number of times...\nPress any key to continue- ");
	getch();
	
	for(temp1=head; temp1!=NULL; temp1=temp1->ptr)
	{
		if(temp1->data==-9999)
			continue;
		
		count=1;
		for(temp2=temp1->ptr; temp2!=NULL; temp2=temp2->ptr)
		{
			if(temp1->data==temp2->data)
			{
				temp2->data=-9999;
				count++;
			}
		}
		
		if(count%2==1 && count>1)
		{
			num=temp1->data;
			flag=1;
			break;
		}
	
	}
	
	
	if(flag==0)
	{
		printf("\n\nThere's no number that appears odd number of times.\n\n");
	}
	else
	{
		printf("\n\nThe first number that appears odd number of times: %d [%d times]\n\n", num, count);
	}
	
	head=temp=temp1=temp2=newNode=NULL;
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);
	
	return 0;
}