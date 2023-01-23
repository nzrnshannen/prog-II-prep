#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node *next;
}*head, *temp, *temp1, *temp2, *newNode, *traverse;

void sortList();

int main()
{
	head=NULL;
	int diff=0;
	int data;

inputAnother:	
	newNode=(struct node*)malloc(sizeof(struct node));
	printf("Insert Data Value: ");
	scanf("%d", &data);
	
	if(data!=0)
	{
		newNode->data=data;
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
		
		printf("Linked list: ");
		traverse=head;
		printf("\n");
		while(traverse!=NULL)
		{
			printf("%d ", traverse->data);
			traverse=traverse->next;
		}
		
		printf("\n\n");
		goto inputAnother;
		
	}
	else
	{
		goto end;
	}
	
	
	end:
	free(head);
	free(traverse);
	free(temp);
	free(temp1);
	free(temp2);
	free(newNode);
	head=traverse=temp=temp1=temp2=newNode=NULL;
	
	return 0;
}

void sortList()
{
	int tmpNum;
	for(temp1=head; temp1->next!=NULL; temp1=temp1->next)
	{
		for(temp2=head; temp2->next!=NULL; temp2=temp2->next)
		{
			if(temp2->data > temp2->next->data)
			{
				tmpNum=temp2->data;
				temp2->data = temp2->next->data;
				temp2->next->data=tmpNum;
			}
		}
	}
}