#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *temp1, *temp2, *repeat, *t;
int n;

int main()
{
	head=repeat=NULL;

inputNo:
	printf("Input number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf("\n\nInput can't generate a linked list. Try inputting a different one.\n\n");
		goto inputNo;
	}
	
	int i=1, freq=1;
	
	printf("\nInput %d data:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
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
	
	printf("\nLinked list: ");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	int flag=0, count=0;
	
	for(temp1=head; temp1->next!=NULL; temp1=temp1->next)
	{
		freq=1;
		if(temp1->data==-1)
			continue;
			
		if(count==2)
			break;
			
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
		{
			if(temp2->data == temp1->data && temp2->data!=-1)
			{
				temp2->data=-1;
				flag=1;
				freq++;
			}
		}
	
		if(flag==1 && freq>=2)
		{
			newNode=(struct node*)malloc(sizeof(struct node));
			newNode->data=temp1->data;
			newNode->next=NULL;
			
			if(repeat==NULL)
			{
				repeat=t=newNode;
			}
			else
			{
				t->next=newNode;
				t=newNode;
			}
			
			count++;
		}
		
		flag==0;
	}
	
	if(count==2)
	{
		printf("\n\nThe two repeating data are: ");
		temp=repeat;
		while(temp!=NULL)
		{
			printf("%d ", temp->data);
			temp=temp->next;
		}
	}
	else
	{
		if(flag==1 && count<2)
			printf("\n\nThere is only a one repeating data found.\n");
		else
			printf("\n\nNo repeating data can be found.\n");
	}


	head=temp=newNode=temp1=temp2=repeat=t=NULL;
	free(head);
	free(temp);
	free(newNode);
	free(temp1);
	free(temp2);
	free(repeat);
	free(t);
	
	return 0;
}