#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *temp1, *temp2, *newNode, *nodeOne, *nodeTwo, *majorElem;

int main()
{
	head=NULL;
	int n, i=1, flag=0, count;

inputNo:
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf ("\n\nNumber can't generate a linked list. Try inputting a different one.\n\n");
		goto inputNo;
	}
	
	printf ("\nInput %d data:\n", n);
	
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
	
	printf ("\nLinked list: ");
	temp=head;
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->next;
	}
	
	
	//majority of element
	
	for(temp1=head; temp1->next!=NULL; temp1=temp1->next)
	{
		if(temp1->data==-1)
			continue;
			
		count=1;
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
		{
			if(temp2->data == temp1->data && temp2->data!=-1)
			{
				flag=1;
				count++;
				temp2->data=-1;
			}
		}
		
		if(count>n/2 && flag==1)
		{
			majorElem=temp1;
			break;
		}
		
		flag=0;
	}
	
	if(flag==1)
	{
		printf ("\n\nThe major element is: %d", majorElem->data);
	}
	else
	{
		printf("\n\nTheere are no major element in the list.");
	}
	
	head=temp=newNode=temp1=temp2=majorElem=NULL;
	free(head);
	free(temp);
	free(newNode);
	free(temp1);
	free(temp2);
	free(majorElem);
	
	return 0;
}