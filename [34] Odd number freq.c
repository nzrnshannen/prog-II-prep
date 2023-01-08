#include<stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *num, *temp1, *temp2;
int n;

int main()
{
	int i, r, count=0, flag=0;
	head=NULL;
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	i=1;
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
	
	temp=head;
	printf ("\nLinked list: ");
	
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	
	count=1;
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{
		if(temp1->data==-1)
			continue;
			
		count=1;
		
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
		{
			if(temp1->data == temp2->data && temp2->data!=-1)
			{
				count++;
				temp2->data=-1;
				flag=1;
			}
		}
		
		if(flag==1 && count!=1 && count%2==1)
		{
			num=temp1;
			break;
		}
		else
		{
			count=1;
			flag=0;
			continue;
		}
	}
	
	printf("\n%d\n", count);
	
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	if(flag==1 && count%2==1)
	{
		printf ("\n\nData that appears odd number of times: %d\n", num->data);
	}
	else
	{
		printf ("\n\nNo data can be found that appears odd number of times.\n");
	}
	
	head=temp=temp1=temp2=newNode=num=NULL;
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);
	free(num);
	
	return 0;

}