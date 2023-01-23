#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int data;
	struct node *ptr;
};

struct node *head, *temp, *temp1, *temp2, *newNode, *start, *check;

void sortList();
void displayList();
void rotateList(int);

int main()
{
	int i=1, j, k, n, pos;
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
	
	printf("Enter number (positions): ");
	scanf("%d", &pos);
	
	printf("\nFrom the nth position [%d], the values of the list are: ", pos);
	temp=head;
	j=1;
	while(j<=pos)
	{
		temp=temp->ptr;
		j++;
	}
	
	while(temp!=NULL)
	{
		printf("%d ", temp->data);
		temp=temp->ptr;
	}
	
	printf("\n\nBefore the nth position [%d], the values of the list are: ", pos);
	j=1;
	temp=head;
	while(j<=pos)
	{
		printf("%d ", temp->data);
		temp=temp->ptr;
		j++;
	}
	
	rotateList(pos);
	
	printf("\n\nRotating the list...\nPress any key to continue- ");
	getch();
	
	printf("\n\nAfter rotating: ");
	displayList();
	
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(check);
	free(newNode);
	free(start);
	
	head=temp=temp1=temp2=check=newNode=NULL;
	
	return 0;
}

void displayList()
{
	for(temp=head; temp!=NULL; temp=temp->ptr)
	{
		printf("%d ", temp->data);
	}
	printf("\n\n");
}

void rotateList(int pos)
{
	int	i=1;
	temp1=head;
	while(i<=pos)
	{
		temp1=temp1->ptr;
		i++;
	}
	
	start=temp1;
	
	temp2=start;
	while(temp2->ptr!=NULL)
	{
		temp2=temp2->ptr;	
	}
	temp2->ptr=head;
	
	check=head;
	while(check->ptr!=start)
	{
		check=check->ptr;
	}
	check->ptr=NULL;
	head=start;
}