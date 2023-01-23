#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int num;
	struct node *next_addr;
};

struct node *head, *temp, *temp1, *temp2, *newNode;

void displayList();
int countDuplicates();

int main()
{
	head=NULL;
	int n, i=1;
	printf("Input the number of nodes for your linked list: ");
	scanf("%d", &n);
	
	printf("Input %d numbers:\n", n);
	while(i<=n)
	{
		newNode=(struct node*)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->num);
		
		newNode->next_addr=NULL;
		
		if(head==NULL)
		{
			head=temp=newNode;
		}
		else
		{
			temp->next_addr=newNode;
			temp=newNode;
		}
	}
	
	printf("\nLinked list: ");
	displayList();
	
	printf("\n\nChecking if there are duplicates...\n\nPress any key to continue- ");
	getch();
	
	int result=countDuplicates();
	
	if(result==0)
	{
		printf("\n\nThere are no duplicating numbers found.\n\n");
	}
	else
	{
		printf("\n\nTotal number of duplicates: %d\n\n", result);
	}
	
	free(head);
	free(temp1);
	free(temp2);
	free(temp);
	free(newNode);

	head=temp1=temp2=temp=newNode=NULL;
		
	return 0;
}

void displayList()
{
	struct node *traverse;
	traverse=head;
	
	while(traverse!=NULL)
	{
		printf("%d ", traverse->num);
		traverse=traverse->next_addr;
	}
	
	free(traverse);
	traverse=NULL;
}

int countDuplicates()
{
	int flag, dupliCount=0;
	
	for(temp1=head; temp1!=NULL; temp1=temp1->next_addr)
	{
		if(temp1->num==-9999)
		{
			continue;
		}
		
		flag = 0;
		
		for(temp2=temp1->next_addr; temp2!=NULL; temp2=temp2->next_addr)
		{
			if(temp2->num == temp1->num && temp2->num!=-9999)
			{
				flag=1;
				temp2->num=-9999;
			}
		}
		
		if(flag==1)
		{
			dupliCount++;
		}
	}
	
	return dupliCount;
}
