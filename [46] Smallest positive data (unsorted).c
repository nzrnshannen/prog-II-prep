/*
	Program is somewhat similar to [42].
*/

#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *check;

int main()
{
	head=NULL;
	int i=1, n, diff=0, smallest=9999, missingElem=0;
	printf("Input the number of nodes: ");
	scanf("%d", &n);
	
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
	
//	sortList();
	
	for(temp=head; temp->next!=NULL; temp=temp->next)
	{
		diff=temp->next->data - temp->data;
		
		if(diff>1)
		{
			int j;
			for(j=1; j<diff; j++)
			{
				missingElem=0;
				missingElem = temp->data + j;
				
				if(missingElem<smallest && missingElem>0)
				{
					check=head;
					int flag=0;
					
					while(check!=NULL)
					{
						if(check->data == missingElem)
						{
							flag=1;
						}
						
						check=check->next;
					}
					
					if(flag!=1)
						smallest=missingElem;
					
					flag=0;
				}
			}
		}
	}
	
	printf("\nThe smallest positive data missed is: %d", smallest);
	

	free(head);
	free(temp);
	free(newNode);
	free(check);

	head=temp=newNode=check=NULL;

	return 0;
}