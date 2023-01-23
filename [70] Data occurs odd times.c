#include <stdlib.h>
#include <stdio.h>

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
	
	int data[2];
	
	printf("Input %d data:\n", n);
	while(i<=n)
	{
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
	
	
	int count=0, j, k=0, oddCount=0;
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{
		if(oddCount==2)
			break;
			
		if(temp1->data==-1)
			continue;
			
		count=1;
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
		{
			if(temp1->data == temp2->data)
			{
				count++;
				temp2->data=-1;
			}
		}
		
		if(count%2==1 && count!=-1)
		{
			data[k++]=temp1->data;
			
			oddCount++;
		}
		
	}
	
	if(oddCount==2)
		printf("\n\nThe first two nodes in which its data occurs odd number of times (exceptionally appeared once) are: %d %d", data[0], data[1]);
	else
		printf("\n\nNumber of nodes in which its data occurs odd number of times are either one only or none.");
	
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);

	head=temp=temp1=temp2=newNode=NULL;
	
	return 0;
}