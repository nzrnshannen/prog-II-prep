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
	int i=1, j, n;
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf ("Input %d data for your linked list:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf ("Data %d: ", i);
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
	
	temp=head;
	
	int flag=0;
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next)
	{
		if(temp1->data==-1)
		{
			continue;
		}
		
		flag=0;
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
		{
			if(temp1->data == temp2->data && flag==0 && temp2->data!=-1 && temp1->data!=-1)
			{
				flag=1;
				temp2->data=-1;
				continue;
			}
			else if(flag==1 && temp1->data == temp2->data && temp2->data!=-1)
			{
				temp2->data=-1;
			}
		}
		
		if(flag==0)
		{
			printf("%d ", temp1->data);
		}
	}
	
	free(head);
	free(newNode);
	free(temp);
	free(temp1);
	free(temp2);
	
	return 0;

}