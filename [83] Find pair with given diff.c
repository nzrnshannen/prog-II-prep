#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *newNode, *temp1, *temp2;

int main()
{
	head=NULL;
	int i=1, n;
	printf("Input the number of nodes for your linked list: ");
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
	
	
	printf("\nThe created linked list: ");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	int diff, flag=0, num1, num2;
	printf("\nInput a difference: ");
	scanf("%d", &diff);
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{
		for(temp2=head; temp2!=NULL; temp2=temp2->next)
		{
			if((temp1->data - temp2->data)==diff)
			{
				flag=1;
				num1=temp1->data;
				num2=temp2->data;
				break;
			}
		}
	}
	
	printf("\nThe given difference is: %d", diff);
	if(flag==1)
	{
		printf("\n\nThe pair are: (%d, %d)\n", num1, num2);
	
	}
	else
	{
		printf("\n\nNo distinctive pairs were found.\n");
	}
	
	free(head);
	free(temp1);
	free(temp2);
	free(temp);
	free(newNode);

	head=temp=temp1=temp2=newNode=NULL;
	
	return 0;
}