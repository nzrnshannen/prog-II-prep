#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *temp, *newNode, *check;

int main()
{
	head=NULL;
	int n, i=1;

inputNo:
	printf("Enter the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf("\n\nInput does not create a linked list. Try a different one.\n\n");
		goto inputNo;
	}
	
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Input Value %d: ", i++);
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			int flag=0;
			
			check=head;
			
			while(check!=NULL)
			{
				if(check->data == newNode->data)
				{
					flag=1;
				}
				
				check=check->next;
			}
			
			if(flag==1)
			{
				continue;
			}
			else
			{
				temp->next=newNode;
				temp=newNode;
			}
		}
		
	}
	
	printf("\nResult:\n");
	temp=head;
	
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	free(head);
	free(temp);
	free(check);
	free(newNode);
	head=temp=check=newNode=NULL;
	
	return 0;
}

