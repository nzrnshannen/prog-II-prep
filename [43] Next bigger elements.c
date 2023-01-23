#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *newNode, *temp1, *temp2, *temp, *start, *t;
int n;

void displayFunc(struct node *print)
{
	int i;
	while(print!=NULL)
	{
		printf("%d ", print->data);
		print=print->next;	
	}
	
	print=NULL;
	free(print);
}

int main()
{
	head=NULL;
inputNo:
	printf ("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	if(n<=0)
	{
		printf("\n\nInput cannot generate a linked list. Try inputting a different one.\n\n");
		goto inputNo;
	}
	
	int i, j, k, flag=0;
	i=1;
	
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
	
	printf("\nThe given list is: ");
	displayFunc(head);
	k=1;
	start=NULL;
	for(temp1=head; temp1->next; temp1=temp1->next)
	{
		for(temp2=temp1->next; temp2!=NULL; temp2=temp2->next)
		{
			if(temp2->data>temp1->data)
			{
				flag=1;
				newNode=(struct node*)malloc(sizeof(struct node));
				newNode->data=temp2->data;
				newNode->next=NULL;
				
				if(start==NULL)
				{
					start=t=newNode;
				}
				else
				{
					t->next=newNode;
					t=newNode;
				}
				
				k++;
				break;
			}
		}
		
		if(flag==0)
		{
			newNode=(struct node*)malloc(sizeof(struct node));
			newNode->data=-1;
			newNode->next=NULL;
			
			if(start==NULL)
			{
				start=t=newNode;
			}
			else
			{
				t->next=newNode;
				t=newNode;
			}
			k++;
		}
		
		flag=0;
		
		if(k==n)
		{
			newNode=(struct node*)malloc(sizeof(struct node));
			newNode->data=-1;
			newNode->next=NULL;
			
			t->next=newNode;
			t=newNode;
		}
	}
	
	printf("\nNext bigger data list:\n");
	displayFunc(start);
	
	free(head);
	free(newNode);
	free(temp);
	free(temp1);
	free(temp2);
	free(start);
	free(t);

	head=newNode=temp=temp1=temp2=start=t=NULL;
	
	return 0;
}