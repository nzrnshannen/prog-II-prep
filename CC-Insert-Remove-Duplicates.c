#include<stdio.h>
#include<stdlib.h>

struct node{
	int data;
	struct node *next;
};

struct node *head, *temp, *traverse, *newNode;

int main()
{
	int i=1, n, flag;
	n=5;
	
	while(i<=n)
	{
		printf("Input Value %d: ", i++);
		newNode=(struct node*)malloc(sizeof(struct node));
		scanf("%d", &newNode->data);
		newNode->next=NULL;
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			traverse=head;
			flag=0;
			while(traverse!=NULL)
			{
				if(traverse->data == newNode->data)
				{
					flag=1;
				}
				traverse=traverse->next;
			}
			
			if(flag==1)
			{
				continue;
			}
			else
			{
				temp->next=newNode;
				temp=newNode;
			}
		}
	}
	
	printf("\n\nResult:\n");
	traverse=head;
	while(traverse!=NULL)
	{
		printf("%d ", traverse->data);
		traverse=traverse->next;
	}
	
	free(head);
	free(temp);
	free(newNode);
	free(traverse);

	head=temp=newNode=traverse=NULL;
	
	return 0;
}