#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int num;
	struct node *next_node;
};

struct node *head1, *head2, *temp, *temp1, *temp2, *t, *newNode;

int main()
{
	head1=head2=NULL;
	int i=1, n, flag=0, nextGreaterNum;
	
	printf("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Input %d data:\n", n);
	
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->num);
		newNode->next_node=NULL;
		
		if(head1==NULL)
		{
			head1=temp=newNode;
		}
		else
		{
			temp->next_node=newNode;
			temp=newNode;
		}
	}
	
	printf("\nThe given list is: ");
	temp=head1;
	while(temp!=NULL)
	{
		printf("%d ", temp->num);
		temp=temp->next_node;
	}
	
	printf("\n\nPrinting the next greater elements...\nPress any key to continue- ");
	getch();
	
	printf("\n\nThe next bigger elements are:\n");
	
	for(temp1=head1; temp1->next_node!=NULL; temp1=temp1->next_node)
	{
		flag=0;
		
		for(temp2=temp1->next_node; temp2!=NULL; temp2=temp2->next_node)
		{
			if(temp2->num > temp1->num)
			{
				flag=1;
				nextGreaterNum = temp2->num;
				break;
			}
		}
		
		if(flag==1)
		{
			newNode=(struct node*)malloc(sizeof(struct node));
			newNode->num = nextGreaterNum;
			newNode->next_node=NULL;
		}
		else
		{
			newNode=(struct node*)malloc(sizeof(struct node));
			newNode->num = -1;
			newNode->next_node = NULL;
		}
		
		if(head2==NULL)
		{
			head2=t=newNode;
		}
		else
		{
			t->next_node=newNode;
			t=newNode;
		}
	}
	
	if(temp1->next_node==NULL)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		newNode->num =-1;
		newNode->next_node=NULL;
		
		t->next_node=newNode;
		t=newNode;
	}
	
	temp1=head1;
	temp2=head2;
	
	while(temp1!=NULL)
	{
		printf("Next bigger element of %d is %d\n", temp1->num, temp2->num);
		temp1=temp1->next_node;
		temp2=temp2->next_node;
	}
	
	printf("\n\nNext bigger elements list:\n");
	temp=head2;
	while(temp!=NULL)
	{
		printf("%d ", temp->num);
		temp=temp->next_node;
	}
	
	head1=head2=temp=temp1=temp2=t=newNode=NULL;
	free(head1);
	free(head2);
	free(temp);
	free(temp1);
	free(temp2);
	free(t);
	free(newNode);
	
	return 0;
}