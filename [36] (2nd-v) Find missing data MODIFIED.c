#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;
	struct node *ptr;
};

struct node *head, *temp, *temp1, *temp2, *newNode;

void sortList();
void displayList();

int main()
{
	int i=1, n, diff=0, flag=0;
	head=NULL;
	
	printf("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Input %d data:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->data);
		newNode->ptr=NULL;
		
		if(head==NULL)
			head=temp=newNode;
		else
		{
			temp->ptr=newNode;
			temp=newNode;
		}
	}
	
	printf("\nLinked list: ");
	displayList();
	sortList();
	printf("After sorting: ");
	displayList();
	
	printf("\n\nFinding the missing number/s...\nPress any key to continue- ");
	getch();
	
	printf("\n\nThe missing number/s: ");
	for(temp1=head; temp1!=NULL; temp1=temp1->ptr)
	{
		diff=temp1->ptr->data - temp1->data;
		if(diff>1)
		{
			for(int j=1; j<diff; j++)
			{
				printf("%d ", temp1->data + j);
				flag = 1;
			}
		}
	}
	
	if(flag==0)
	{
		printf("\n\nNo missing numbers in the list!\n");
	}
	
	head=temp=temp1=temp2=newNode=NULL;
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);
	
	return 0;
}


void sortList()
{
	int tmpNum;
	
	for(temp1=head; temp1!=NULL; temp1=temp1->ptr)
	{
		for(temp2=head; temp2->ptr!=NULL; temp2=temp2->ptr)
		{
			if(temp2->data>temp2->ptr->data)
			{
				tmpNum=temp2->data;
				temp2->data=temp2->ptr->data;
				temp2->ptr->data=tmpNum;
			}
		}
	}
}

void displayList()
{
	for(temp=head; temp!=NULL; temp=temp->ptr)
	{
		printf("%d ", temp->data);
	}
	printf("\n\n");
}