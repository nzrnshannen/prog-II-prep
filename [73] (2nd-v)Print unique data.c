#include <stdlib.h>
#include <stdio.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *traverse;

int main()
{
	head=NULL;
	int i=1, n, flag=0;
	printf("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Input %d data:\n", n);
	while(i<=n)
	{
		flag=0;
		
	inputData:
		printf("Data %d: ", i++);
		newNode=(struct node*)malloc(sizeof(struct node));
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			traverse=head;
			while(traverse!=NULL)
			{
				if(newNode->data==traverse->data)
				{
					flag=1;
					break;
				}
				else
				{
					flag=0;
				}
				
				traverse=traverse->next;
			}
			
			if(flag==0)
			{
				temp->next=newNode;
				temp=newNode;
			}
			else
			{
				goto inputData;
			}
		}
	}
	
	
	printf("\nPrinting unique data in the list: ");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}

	head=temp=newNode=traverse=NULL;
	free(head);
	free(temp);
	free(newNode);
	free(traverse);
	
	return 0;
}