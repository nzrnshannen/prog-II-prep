#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode;

int main()
{
	head=NULL;
	int n, num, flag=0, pos=1;
	printf("Input number of nodes for your linked list: ");
	scanf("%d", &n);
	
	int i=1;
	printf("Input %d data:\n", n);
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
	
	printf("\nEnter a number to be searched: ");
	scanf("%d", &num);
	
	for(temp=head; temp!=NULL; temp=temp->next)
	{
		if(num==temp->data)
		{
			flag=1;
			break;
		}
		pos++;
	}
	
	if(flag==1)
		printf("\n\n[%d] has been found, located in position %d.", num, pos);
	else
		printf("\n\nThere's no such thing as number [%d] in the list.", num);
		
	free(head);
	free(temp);
	free(newNode);

	head=temp=newNode=NULL;
	
	return 0;
}