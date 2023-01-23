#include <stdio.h>
#include <stdlib.h>
#include <conio.h>

struct node{
	int num;
	struct node *ptr;
};

struct node *head, *temp, *temp1, *temp2, *newNode, *head1, *head2, *common_data;

void createList(struct node**, struct node**, int);
void displayList(struct node**, struct node**);
int commonElem();

int main()
{
	head1=head2=NULL;
	int i=1, n1, n2;
	printf("Input the number of nodes for your first linked list: ");
	scanf("%d", &n1);
	createList(&head1, &temp1, n1);
	printf("First linked list: ");
	displayList(&head1, &temp1);
	printf("\nInput the number of nodes for your second linked list: ");
	scanf("%d", &n2);
	createList(&head2, &temp2, n2);
	printf("Second linked list: ");
	displayList(&head1, &temp1);
	
	printf("\nChecking if there are common elements...\n");
	printf("\nPress any key to continue-\n\n");
	getch();
	
	int result=commonElem();
	
	if(result==0)
	{
		printf("No common elements were found.\n");
	}
	else
	{
		printf("The first common element found: %d\n", common_data->num);
	}
	
	free(head);
	free(head1);
	free(head2);
	free(newNode);
	free(common_data);
	free(temp1);
	free(temp2);
	free(head);
	free(temp);

	head1=head2=head=temp=newNode=common_data=temp1=temp2=NULL;
	
	return 0;
}

void displayList(struct node **hd, struct node **tmp)
{
	*tmp=*hd;
	while(*tmp!=NULL)
	{
		printf("%d ", (*tmp)->num);
		*tmp=(*tmp)->ptr;
	}
	printf("\n");
}

void createList(struct node **head, struct node **temp, int n)
{
	int i=1;
	printf("Input %d numbers:\n", n);
	*head=*temp;
	while(i<=n)
	{
		newNode=(struct node *)malloc(sizeof(struct node));
		printf("Data %d: ", i++);
		scanf("%d", &newNode->num);
		newNode->ptr=NULL;
		
		if(*head==NULL)
		{
			*head=*temp=newNode;
		}
		else
		{
			(*temp)->ptr=newNode;
			*temp=newNode;
		}
	}
	printf("\n");
}

int commonElem()
{
	int flag;
	for(temp1=head1; temp1!=NULL; temp1=temp1->ptr)
	{
		flag=0;
		for(temp2=head2; temp2!=NULL; temp2=temp2->ptr)
		{
			if(temp1->num == temp2->num)
			{
				flag=1;
				common_data = temp1;
			}
			
			if(flag==1)
				break;
		}
		
		if(flag==1)
			break;
	}
	
	
	if(flag==1)
	{
		return 1;
	}
	else
	{
		return 0;
	}
}