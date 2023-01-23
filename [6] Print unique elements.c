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
	int i=1, n;
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
	
	int flag;
	
	printf("\n\nThe unique numbers are as follows: ");
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{
		if(temp1->data==-9999)
			continue;
		
		flag=0;
		
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
		{
			if(temp1->data == temp2->data && temp2->data!=-9999)
			{
				flag=1;
				temp2->data=-9999;
			}	
		}
		
		if(flag==0)
		{
			printf("%d ", temp1->data);
		}
	}
	
	if(flag==1)
	{
		printf("\nSorry, there are no unique numbers in the list.\n\n");
	}
	
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);

	head=temp=temp1=temp2=newNode=NULL;
	
	return 0;
}