#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *traverse;

int main()
{
	head=NULL;
	int i=1, n, j, flag=0, count=0;
	printf ("Input the number of nodes for the construction of your linked list: ");
	scanf("%d", &n);
	
	printf ("Input %d data:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
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
		i++;
	}	
	
	i=1;
	for(temp=head; temp!=NULL; temp=temp->next)
	{
		flag=0;
		if(temp->data==-1)
			continue;
			
		for(traverse=temp->next; traverse!=NULL; traverse=traverse->next)
		{		
			if(temp->data == traverse->data && temp->data!=-1 && traverse->data!=-1 && flag==0)
			{
				flag=1;
				count++;
				traverse->data=-1;
				
				printf ("\nData %d: %d\n", i++, temp->data);
			}
			
			if(temp->data == traverse->data && flag == 1)
			{
				traverse->data=-1;
			}
		}
	}
	
	printf("\nTotal number of duplicate data found in the linked list is: %d", count);
	
	free(head);
	free(newNode);
	free(traverse);
	free(temp);

	head=newNode=traverse=temp=NULL;
	
	return 0;
}