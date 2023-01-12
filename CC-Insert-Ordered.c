#include <stdio.h>
#include <stdlib.h>

struct node{
	int num;
	struct node *next;
};

struct node *head, *temp, *temp1, *temp2, *newNode, *traverse;
int n;

void sortList();

int main()
{
	head=NULL;
	int data;
	
	inputAgain:
	printf("Insert Data Value: ");
	scanf("%d", &data);
		
	if(data==0)
	{
		goto end;
	}
	
	newNode=(struct node*)malloc(sizeof(struct node));
	newNode->num = data;
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
		
	sortList();
		
	traverse=head;
	printf("LinkedList Data:\n");
	while(traverse!=NULL)
	{
		printf("%d ", traverse->num);
		traverse=traverse->next;
	}
	
	printf("\n\n");
		
	if(data!=0)
	{
		goto inputAgain;
	}
	
	
	end:
	head=temp=temp1=temp2=traverse=newNode=NULL;
	free(head);
	free(temp);
	free(temp1);
	free(temp2);
	free(traverse);
	free(newNode);
	
	return 0;
}

void sortList()
{
	for(temp1=head; temp1->next!=NULL; temp1=temp1->next)
	{
		for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
		{
			int t;
			if(temp2->num > temp2->next->num)
			{
				t=temp2->num;
				temp2->num=temp2->next->num;
				temp2->next->num=t;
			}
		}
	}
	
	return;
}
