#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;
	struct node *ptr;
}*head, *temp, *temp1, *newNode, *check;


int main()
{
	head==NULL;
	int i=1, sum=0, flag=0, n, smallestPos=999, diff=0, s;
	printf("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Input data for each %d nodes:\n", n);
	for(i; i<=n; i++)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i);
		scanf("%d", &newNode->data);
		newNode->ptr=NULL;
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			temp->ptr=newNode;
			temp=newNode;
		}
	}
	
	printf("\nThe given linked list: ");
	for(temp=head; temp!=NULL; temp=temp->ptr)
	{
		printf("%d ", temp->data);
	}
	
	for(temp1=head; temp1->ptr!=NULL; temp1=temp1->ptr)
	{
		diff=temp1->ptr->data - temp1->data;
		
		if(diff>1)
		{
			for(int j=1; j<diff; j++)
			{
				flag=0;
				s=temp1->data + j;
				check=head;
				while(check!=NULL)
				{
					if(check->data == s)
					{
						flag=1;
						break;
					}
					
					check=check->ptr;
				}
				
			
				if(flag!=1)
				{
					if(s<smallestPos && s > 0)
					{
						smallestPos=s;
					}
				}
			}
		}
	}
	
	
	printf("\n\nThe smallest positive number missing in the list is: %d", smallestPos);
	
	head=temp=temp1=check=newNode=NULL;
	free(head);
	free(temp);
	free(temp1);
	free(check);
	free(newNode);
	
	return 0;
}
